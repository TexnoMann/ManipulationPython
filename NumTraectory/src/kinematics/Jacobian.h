//
// Created by texnoman on 07.03.18.
//

#ifndef NUMTRAECTORY_JACOBIAN_H
#define NUMTRAECTORY_JACOBIAN_H


#include <armadillo>
#include "ManipulatorConfiguration.h"


using namespace arma;

class Jacobian {
    public:
        Jacobian(ManipulatorConfiguration configuration);
        mat getRelativeCoordsSpeed(mat relativeCoords, mat absoluteSpeed);
        mat getRelativeCoordsOrientation(mat absoluteCoords, mat absoluteSpeedOrientation);
        mat getAbsoluteCoordsSpeed(mat relativeCoords, mat relativeSpeed);
        mat getAbsoluteCoordsOrientation(mat relativeCoords, mat relativeSpeedOrientation);

    private:
        ManipulatorConfiguration _configuration;
        mat getJacobianMatrixCoordsfromRRR(mat coordsMatrix);
};


#endif //NUMTRAECTORY_JACOBIAN_H
