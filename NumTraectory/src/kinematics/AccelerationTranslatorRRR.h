//
// Created by texnoman on 07.04.18.
//

#ifndef NUMTRAECTORY_ACCELERATIONTRANSLATOR_H
#define NUMTRAECTORY_ACCELERATIONTRANSLATOR_H

#include <armadillo>
#include "ManipulatorConfiguration.h"
#include "SpeedTranslatorRRR.h"

using namespace arma;

class AccelerationTranslator {
    public:
        AccelerationTranslator(ManipulatorConfiguration configuration);
    colvec getRelativeAcceleration(colvec relativeSpeed, colvec absoluteAcceleration, mat Jacobian, colvec relativeCoords);

private:
        ManipulatorConfiguration _configuration;
        mat getDerivatedJacodian(colvec relativeAngle);
        colvec getDerivatedComponent(colvec absoluteAcceleration, colvec derivatedJacobian, colvec relativeSpeed);

    };


#endif //NUMTRAECTORY_ACCELERATIONTRANSLATOR_H
