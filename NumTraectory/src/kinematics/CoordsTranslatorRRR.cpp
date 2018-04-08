//
// Created by texnoman on 16.03.18.
//

#include "CoordsTranslatorRRR.h"
#include <cmath>

CoordsTranslatorRRR::CoordsTranslatorRRR(ManipulatorConfiguration configuration): _configuration(configuration) {
    _configuration=configuration;
}

colvec CoordsTranslatorRRR::getRelativeCoords(colvec absoluteCoords) {
    colvec q(_configuration.getNumberJoint(),1);
    float* _a= _configuration.getaM();
    float* _d= _configuration.getdM();

    float X03=absoluteCoords(0,0);
    float Y03=absoluteCoords(1,0);
    float Z03=absoluteCoords(2,0);

    q.fill(0.0);
    q(0,0) = atan2(Y03, X03);

    float X01 = _a[0];
    float Z01 = _d[0];
    float Y01 = _a[0]*sin(q(0,0));
    float X13 = sqrt(pow(X03, 2)+pow(Y03, 2))-X01;
    float Y13 = Z03-Z01;

    float b2 = pow(X13, 2);
    float c2 = pow(Y13, 2);
    float b = X13;
    float c = Y13;
    float d2 = b2 + c2;

    float cq2 = (d2 - pow(_a[1], 2) - pow(_a[2], 2))/(2*_a[1]*_a[2]);
    q(2,0) = atan2(-sqrt(1-pow(cq2, 2)), cq2);
    q(1,0) = -(M_PI/2-(atan2(c, b) - atan2(_a[2]*sin(q(2,0)), _a[1]+cq2*_a[2])));
    return q;
}


colvec CoordsTranslatorRRR::getAbsCoords(colvec relativeCoords) {
    colvec xyz = {_getX(relativeCoords), _getY(relativeCoords), _getZ(relativeCoords)};
    return xyz;
}




float CoordsTranslatorRRR::_getX(colvec relativeCoords) {
    float* _a= _configuration.getaM();
    float* _d= _configuration.getdM();
    float X= _a[0] * cos(relativeCoords(0,0)) + _d[1] * sin(relativeCoords(0,0)) + _d[2] * sin(relativeCoords(0,0)) + _a[1] * cos(relativeCoords(0,0)) * -sin(relativeCoords(1,0)) + _a[2] * cos(relativeCoords(0,0)) * -sin(relativeCoords(1,0)) * cos(relativeCoords(2,0)) - _a[2] * cos(relativeCoords(0,0)) * cos(relativeCoords(1,0)) * sin(relativeCoords(2,0));
    return X;
}

float CoordsTranslatorRRR::_getY(colvec relativeCoords){
    float* _a= _configuration.getaM();
    float* _d= _configuration.getdM();
    float Y = _a[0] * sin(relativeCoords(0,0)) - _d[2] * cos(relativeCoords(0,0)) - _d[1] * cos(relativeCoords(0,0)) + _a[1] * -sin(relativeCoords(1,0)) * sin(relativeCoords(0,0)) + _a[2] * -sin(relativeCoords(1,0)) * cos(relativeCoords(2,0)) * sin(relativeCoords(0,0)) - _a[2] * sin(relativeCoords(0,0)) * cos(relativeCoords(1,0)) * sin(relativeCoords(2,0));
    return Y;
}

float CoordsTranslatorRRR::_getZ(colvec relativeCoords) {
    float* _a= _configuration.getaM();
    float* _d= _configuration.getdM();
    float Z = _d[0] + _a[1] * cos(relativeCoords(1,0)) + _a[2] * -sin(relativeCoords(1,0)) * sin(relativeCoords(2,0)) + _a[2] * cos(relativeCoords(2,0)) * cos(relativeCoords(1,0));
    return Z;
}

/*
 * a0*cos(theta0) + d1*sin(theta0) + d2*sin(theta0) + a1*cos(theta0)*cos(theta1 + pi/2) + a2*cos(theta0)*cos(theta2)*cos(theta1 + pi/2) - a2*cos(theta0)*sin(theta2)*sin(theta1 + pi/2)
 a0*sin(theta0) - d2*cos(theta0) - d1*cos(theta0) + a1*cos(theta1 + pi/2)*sin(theta0) + a2*cos(theta2)*cos(theta1 + pi/2)*sin(theta0) - a2*sin(theta0)*sin(theta2)*sin(theta1 + pi/2)
                                                                                   d0 + a1*sin(theta1 + pi/2) + a2*cos(theta2)*sin(theta1 + pi/2) + a2*cos(theta1 + pi/2)*sin(theta2)

 */