//
// Created by texnoman on 07.03.18.
//

#ifndef NUMTRAECTORY_JACOBIAN_H
#define NUMTRAECTORY_JACOBIAN_H


#include <armadillo>
#include "ManipulatorConfiguration.h"


using namespace arma;

class SpeedTranslatorRRR {
    public:
        SpeedTranslatorRRR(ManipulatorConfiguration configuration);
        colvec getRelativeCoordsSpeed(colvec relativeCoords, colvec absoluteSpeed);
        colvec getRelativeCoordsOrientation(colvec absoluteCoords, colvec absoluteSpeedOrientation);
        colvec getAbsoluteCoordsSpeed(colvec relativeCoords, colvec relativeSpeed);
        colvec getAbsoluteCoordsOrientation(colvec relativeCoords, colvec relativeSpeedOrientation);
        mat getJacobianMatrixCoordsfromRRR(colvec coordsMatrix);

    private:
        ManipulatorConfiguration _configuration;

};


#endif //NUMTRAECTORY_JACOBIAN_H
