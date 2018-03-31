//
// Created by texnoman on 07.03.18.
//

#ifndef NUMTRAECTORY_JACOBIAN_H
#define NUMTRAECTORY_JACOBIAN_H


#include <armadillo>
#include "ManipulatorConfiguration.h"


using namespace arma;

class JacobianRRR {
    public:
        JacobianRRR(ManipulatorConfiguration configuration);
        colvec getRelativeCoordsSpeed(colvec relativeCoords, colvec absoluteSpeed);
        mat getRelativeCoordsOrientation(colvec absoluteCoords, colvec absoluteSpeedOrientation);
        colvec getAbsoluteCoordsSpeed(colvec relativeCoords, colvec relativeSpeed);
        colvec getAbsoluteCoordsOrientation(colvec relativeCoords, colvec relativeSpeedOrientation);

    private:
        ManipulatorConfiguration _configuration;
        mat getJacobianMatrixCoordsfromRRR(colvec coordsMatrix);
};


#endif //NUMTRAECTORY_JACOBIAN_H
