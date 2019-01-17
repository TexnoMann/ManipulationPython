//
// Created by texnoman on 13.03.18.
//

#include "ManipulatorKinematic.h"


ManipulatorKinematic::ManipulatorKinematic(fmat param) {
    _a=trans(((fcolvec)param.col(0)));
    _d=trans((fcolvec)param.col(1));
    _numberJoint=((fcolvec)param.col(0)).size();
}

fcolvec ManipulatorKinematic::getRelCoordinats(fcolvec absCoords) {
    fcolvec q={0,0,0};

    float X03=absCoords(0);
    float Y03=absCoords(1);
    float Z03=absCoords(2);

    q.fill(0.0);
    q[0] = atan2f(Y03, X03);

    float X01 = _a[0];
    float Z01 = _d[0];
    float Y01 = _a[0]*sinf(q(0));
    float X13 = sqrtf(pow(X03, 2)+powf(Y03, 2))-X01;
    float Y13 = Z03-Z01;

    float b2 = powf(X13, 2);
    float c2 = powf(Y13, 2);
    float b = X13;
    float c = Y13;
    float d2 = b2 + c2;

    float cq2 = (d2 - powf(_a[1], 2) - powf(_a[2], 2))/(2*_a[1]*_a[2]);
    q[2] = atan2f(-sqrtf(1-powf(cq2, 2)), cq2);
    q[1] = -(M_PI/2.0-(atan2(c, b) - atan2(_a[2]*sin(q[2]), _a[1]+cq2*_a[2])));
    return q;
}

fcolvec ManipulatorKinematic::getRelSpeed(fcolvec absSpeeds, fcolvec relCoords) {
    fcolvec relspeeds=inv(_getJacobian(relCoords))*absSpeeds;
    return relspeeds;
}

fmat ManipulatorKinematic::_getJacobian(fcolvec angles){
    float theta0=angles(0);
    float theta1=angles(1);
    float theta2=angles(2);

    fmat jacobian = {{- _a[0]*sinf(theta0) + _a[1]*cosf(theta1)*sinf(theta0) + _a[2]*cosf(theta2)*cosf(theta1)*sinf(theta0) + _a[2]*sinf(theta0)*sinf(theta2)*cosf(theta1),    -cosf(theta0)*(_a[1]*cosf(theta1) + _a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2)), -cosf(theta0)*(_a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2))},
                     {_a[0]*cosf(theta0)  - _a[1]*cosf(theta0)*sinf(theta1) - _a[2]*cosf(theta0)*cosf(theta2)*sinf(theta1) - _a[2]*cosf(theta0)*sinf(theta2)*cosf(theta1),  -sinf(theta0)*(_a[1]*cosf(theta1) + _a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2)),   -sinf(theta0)*(_a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2))},
                     {   0, cosf(theta0)*( - _a[1]*cosf(theta0)*sinf(theta1) - _a[2]*cosf(theta0)*cosf(theta2)*sinf(theta1) - _a[2]*cosf(theta0)*sinf(theta2)*cosf(theta1)) - sinf(theta0)*(_d[1]*cosf(theta0) + _d[2]*cosf(theta0) + _a[1]*sinf(theta1)*sinf(theta0) + _a[2]*cosf(theta2)*sinf(theta1)*sinf(theta0) + _a[2]*sinf(theta0)*sinf(theta2)*cosf(theta1)), cosf(theta0)*(_d[2]*sinf(theta0) - _a[2]*cosf(theta0)*cosf(theta2)*sinf(theta1) - _a[2]*cosf(theta0)*sinf(theta2)*cosf(theta1)) - sinf(theta0)*(_d[2]*cosf(theta0) + _a[2]*cosf(theta2)*sinf(theta1)*sinf(theta0) + _a[2]*sinf(theta0)*sinf(theta2)*sinf(theta1))}
    };

    return jacobian;
}


    