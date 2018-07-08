//
// Created by texnoman on 07.04.18.
//

#include "AccelerationTranslatorRRR.h"

AccelerationTranslator::AccelerationTranslator(ManipulatorConfiguration configuration)
        : _configuration(configuration)
            {

}

fmat AccelerationTranslator::getDerivatedJacodian(fcolvec relativeAngle) {
    float* _a=_configuration.getaM();
    float* _d=_configuration.getdM();
    float theta0=relativeAngle(0);
    float theta1=relativeAngle(1);
    float theta2=relativeAngle(2);

    fmat derivateJacobian={{_a[2]*cosf(theta0)*sinf(theta2)*cosf(theta1) - _d[1]*sinf(theta0) - _d[2]*sinf(theta0) + _a[1]*cosf(theta0)*sinf(theta1) + _a[2]*cosf(theta0)*cosf(theta2)*sinf(theta1) - _a[0]*cosf(theta0), sinf(theta0)*(_a[1]*cosf(theta1) + _a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2)),  sinf(theta0)*(_a[2]*cosf(theta2)*cosf(theta1) - _a[2]*cosf(theta1)*sinf(theta2))},
                           { - _a[0]*sinf(theta0) + _a[1]* sinf(theta1)*sinf(theta0) + _a[2]*cosf(theta2)*sinf(theta1)*sinf(theta0) + _a[2]*sinf(theta0)*sinf(theta2)*cosf(theta1), -cosf(theta0)*(_a[1]*cosf(theta1) + _a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2)), -cosf(theta0)*(_a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2))},
                           {0,0,0}};
    return derivateJacobian;
}

fcolvec AccelerationTranslator::getDerivatedComponent(fcolvec absoluteAcceleration, fcolvec derivatedJacobian,
                                                     fcolvec relativeSpeed) {
    return absoluteAcceleration-derivatedJacobian*relativeSpeed;
}

fcolvec AccelerationTranslator::getRelativeAcceleration(fcolvec relativeSpeed, fcolvec absoluteAcceleration, fmat Jacobian, fcolvec relativeCoords) {
    return inv(Jacobian)*getDerivatedComponent(absoluteAcceleration,getDerivatedJacodian(relativeCoords),relativeSpeed);
}
