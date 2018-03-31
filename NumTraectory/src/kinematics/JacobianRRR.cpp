//
// Created by texnoman on 07.03.18.
//

#include "JacobianRRR.h"
#include "ManipulatorConfiguration.h"

JacobianRRR::JacobianRRR(ManipulatorConfiguration configuration): _configuration(configuration) {
    _configuration=configuration;
}


colvec JacobianRRR::getAbsoluteCoordsSpeed(colvec relativeCoords, colvec relativeSpeed) {
    mat absoluteSpeed = getJacobianMatrixCoordsfromRRR(relativeCoords)*relativeSpeed;
    return absoluteSpeed;
}

colvec JacobianRRR::getRelativeCoordsSpeed(colvec relativeCoords, colvec absoluteSpeed) {
    mat relativeSpeed = inv(getJacobianMatrixCoordsfromRRR(relativeCoords))*absoluteSpeed;
    return relativeSpeed;
}

mat JacobianRRR::getJacobianMatrixCoordsfromRRR(colvec coordsMatrix) {
    float* _a=_configuration.getaM();
    float* _d=_configuration.getdM();
    float theta0=coordsMatrix(0,0);
    float theta1=coordsMatrix(1,0);
    float theta2=coordsMatrix(2,0);

    mat jacobian= {{- _a[0]*sin(theta0) + _a[1]*cos(theta1)*sin(theta0) + _a[2]*cos(theta2)*cos(theta1)*sin(theta0) + _a[2]*sin(theta0)*sin(theta2)*cos(theta1),    -cos(theta0)*(_a[1]*cos(theta1) + _a[2]*cos(theta2)*cos(theta1) - _a[2]*sin(theta1)*sin(theta2)), -cos(theta0)*(_a[2]*cos(theta2)*cos(theta1) - _a[2]*sin(theta1)*sin(theta2))},
                   {_a[0]*cos(theta0)  - _a[1]*cos(theta0)*sin(theta1) - _a[2]*cos(theta0)*cos(theta2)*sin(theta1) - _a[2]*cos(theta0)*sin(theta2)*cos(theta1),  -sin(theta0)*(_a[1]*cos(theta1) + _a[2]*cos(theta2)*cos(theta1) - _a[2]*sin(theta1)*sin(theta2)),   -sin(theta0)*(_a[2]*cos(theta2)*cos(theta1) - _a[2]*sin(theta1)*sin(theta2))},
                   {   0, cos(theta0)*( - _a[1]*cos(theta0)*sin(theta1) - _a[2]*cos(theta0)*cos(theta2)*sin(theta1) - _a[2]*cos(theta0)*sin(theta2)*cos(theta1)) - sin(theta0)*(_d[1]*cos(theta0) + _d[2]*cos(theta0) + _a[1]*sin(theta1)*sin(theta0) + _a[2]*cos(theta2)*sin(theta1)*sin(theta0) + _a[2]*sin(theta0)*sin(theta2)*cos(theta1)), cos(theta0)*(_d[2]*sin(theta0) - _a[2]*cos(theta0)*cos(theta2)*sin(theta1) - _a[2]*cos(theta0)*sin(theta2)*cos(theta1)) - sin(theta0)*(_d[2]*cos(theta0) + _a[2]*cos(theta2)*sin(theta1)*sin(theta0) + _a[2]*sin(theta0)*sin(theta2)*sin(theta1))}
    };

    return jacobian;
}