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
        mat getRelativeCoords(mat absoluteCoords, mat absoluteSpeed);
        mat getRelativeCoordsOrientation(mat absoluteCoords, mat absoluteSpeedOrientation);
        mat getAbsoluteCoords(mat relativeCoords, mat relativeSpeed);
        mat getAbsoluteCoordsOrientation(mat relativeCoords, mat relativeSpeedOrientation);

    private:
        float* _a;
        float* _d;
        mat getJacobianMatrixCoordsfromRRR(mat coordsMatrix);
};


#endif //NUMTRAECTORY_JACOBIAN_H
