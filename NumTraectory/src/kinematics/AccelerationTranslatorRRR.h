//
// Created by texnoman on 07.04.18.
//

#ifndef NUMTRAECTORY_ACCELERATIONTRANSLATOR_H
#define NUMTRAECTORY_ACCELERATIONTRANSLATOR_H

#include <armadillo>
#include "ManipulatorConfiguration.h"

using namespace arma;

class AccelerationTranslator {
    public:
        AccelerationTranslator(ManipulatorConfiguration configuration);
        colvec getRelativeAcceleration(colvec relativeSpeed, colvec absoluteAcceleration);
    private:
        ManipulatorConfiguration _configuration;
        mat getDerivatedJacodian(colvec relativeAngle);
        mat getDerivatedComponent(colvec absoluteAcceleration, colvec derivatedJacobian, colvec relativeSpeed);

};


#endif //NUMTRAECTORY_ACCELERATIONTRANSLATOR_H
