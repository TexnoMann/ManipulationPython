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
        fcolvec getRelativeCoordsSpeed(fcolvec relativeCoords, fcolvec absoluteSpeed);
        fcolvec getRelativeCoordsOrientation(fcolvec absoluteCoords, fcolvec absoluteSpeedOrientation);
        fcolvec getAbsoluteCoordsSpeed(fcolvec relativeCoords, fcolvec relativeSpeed);
        fcolvec getAbsoluteCoordsOrientation(fcolvec relativeCoords, fcolvec relativeSpeedOrientation);
        fmat getJacobianMatrixCoordsfromRRR(fcolvec coordsMatrix);

    private:
        ManipulatorConfiguration _configuration;

};


#endif //NUMTRAECTORY_JACOBIAN_H
