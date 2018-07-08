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
    fcolvec getRelativeAcceleration(fcolvec relativeSpeed, fcolvec absoluteAcceleration, fmat Jacobian, fcolvec relativeCoords);

private:
        ManipulatorConfiguration _configuration;
        fmat getDerivatedJacodian(fcolvec relativeAngle);
        fcolvec getDerivatedComponent(fcolvec absoluteAcceleration, fcolvec derivatedJacobian, fcolvec relativeSpeed);

    };


#endif //NUMTRAECTORY_ACCELERATIONTRANSLATOR_H
