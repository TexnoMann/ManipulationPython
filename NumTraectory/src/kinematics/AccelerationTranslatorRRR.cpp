//
// Created by texnoman on 07.04.18.
//

#include "AccelerationTranslatorRRR.h"

AccelerationTranslator::AccelerationTranslator(ManipulatorConfiguration configuration)
        : _configuration(configuration){
}

mat AccelerationTranslator::getDerivatedJacodian(colvec relativeAngle) {
    float* _a=_configuration.getaM();
    float* _d=_configuration.getdM();
    float theta0=relativeAngle(0);
    float theta1=relativeAngle(1);
    float theta2=relativeAngle(2);
    /*mat derivatedJacobi =
    _a[2]*cos(theta0)*sin(theta2)*cos(theta1) - _d[1]*sin(theta0) - _d[2]*sin(theta0) + _a[1]*cos(theta0)*sin(theta1) - _a[2]*cos(theta0)*cos(theta2)*cos(theta1 + pi/2) - a0*cos(theta0),  sin(theta0)*(a1*sin(theta1 + pi/2) + a2*cos(theta2)*sin(theta1 + pi/2) + a2*cos(theta1 + pi/2)*sin(theta2)),  sin(theta0)*(a2*cos(theta2)*sin(theta1 + pi/2) + a2*cos(theta1 + pi/2)*sin(theta2))]
    [ d1*cos(theta0) + d2*cos(theta0) - a0*sin(theta0) - a1*cos(theta1 + pi/2)*sin(theta0) - a2*cos(theta2)*cos(theta1 + pi/2)*sin(theta0) + a2*sin(theta0)*sin(theta2)*sin(theta1 + pi/2), -cos(theta0)*(a1*sin(theta1 + pi/2) + a2*cos(theta2)*sin(theta1 + pi/2) + a2*cos(theta1 + pi/2)*sin(theta2)), -cos(theta0)*(a2*cos(theta2)*sin(theta1 + pi/2) + a2*cos(theta1 + pi/2)*sin(theta2))]
    [                                                                                                                                                                                    0,                                                                                                            0,                                                                                    0]
    [                                                                                                                                                                                    0,                                                                                                  cos(theta0),                                                                          cos(theta0)]
    [                                                                                                                                                                                    0,                                                                                                  sin(theta0),                                                                          sin(theta0)]
    [                                                                                                                                                                                    0,                                                                                                            0,                                                                                    0]
*/
}
