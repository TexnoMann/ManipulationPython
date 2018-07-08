//
// Created by texnoman on 07.03.18.
//

#include "SpeedTranslatorRRR.h"
#include "ManipulatorConfiguration.h"

SpeedTranslatorRRR::SpeedTranslatorRRR(ManipulatorConfiguration configuration): _configuration(configuration) {
}


fcolvec SpeedTranslatorRRR::getAbsoluteCoordsSpeed(fcolvec relativeCoords, fcolvec relativeSpeed) {
    fmat absoluteSpeed = getJacobianMatrixCoordsfromRRR(relativeCoords)*relativeSpeed;
    return absoluteSpeed;
}

fcolvec SpeedTranslatorRRR::getRelativeCoordsSpeed(fcolvec relativeCoords, fcolvec absoluteSpeed) {
    fcolvec relativeSpeed = inv(getJacobianMatrixCoordsfromRRR(relativeCoords))*absoluteSpeed;
    return relativeSpeed;
}

fmat SpeedTranslatorRRR::getJacobianMatrixCoordsfromRRR(fcolvec coordsMatrix) {
    float* _a=_configuration.getaM();
    float* _d=_configuration.getdM();
    float theta0=coordsMatrix(0);
    float theta1=coordsMatrix(1);
    float theta2=coordsMatrix(2);
    
    fmat jacobian = {{- _a[0]*sinf(theta0) + _a[1]*cosf(theta1)*sinf(theta0) + _a[2]*cosf(theta2)*cosf(theta1)*sinf(theta0) + _a[2]*sinf(theta0)*sinf(theta2)*cosf(theta1),    -cosf(theta0)*(_a[1]*cosf(theta1) + _a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2)), -cosf(theta0)*(_a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2))},
                   {_a[0]*cosf(theta0)  - _a[1]*cosf(theta0)*sinf(theta1) - _a[2]*cosf(theta0)*cosf(theta2)*sinf(theta1) - _a[2]*cosf(theta0)*sinf(theta2)*cosf(theta1),  -sinf(theta0)*(_a[1]*cosf(theta1) + _a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2)),   -sinf(theta0)*(_a[2]*cosf(theta2)*cosf(theta1) - _a[2]*sinf(theta1)*sinf(theta2))},
                   {   0, cosf(theta0)*( - _a[1]*cosf(theta0)*sinf(theta1) - _a[2]*cosf(theta0)*cosf(theta2)*sinf(theta1) - _a[2]*cosf(theta0)*sinf(theta2)*cosf(theta1)) - sinf(theta0)*(_d[1]*cosf(theta0) + _d[2]*cosf(theta0) + _a[1]*sinf(theta1)*sinf(theta0) + _a[2]*cosf(theta2)*sinf(theta1)*sinf(theta0) + _a[2]*sinf(theta0)*sinf(theta2)*cosf(theta1)), cosf(theta0)*(_d[2]*sinf(theta0) - _a[2]*cosf(theta0)*cosf(theta2)*sinf(theta1) - _a[2]*cosf(theta0)*sinf(theta2)*cosf(theta1)) - sinf(theta0)*(_d[2]*cosf(theta0) + _a[2]*cosf(theta2)*sinf(theta1)*sinf(theta0) + _a[2]*sinf(theta0)*sinf(theta2)*sinf(theta1))}
    };

   
    return jacobian;
}