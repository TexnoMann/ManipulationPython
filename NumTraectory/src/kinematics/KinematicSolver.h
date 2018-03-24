//
// Created by texnoman on 24.03.18.
//

#ifndef NUMTRAECTORY_KINEMATICSOLVER_H
#define NUMTRAECTORY_KINEMATICSOLVER_H

#include <armadillo>
#include "Jacobian.h"
#include "CoordsTranslator.h"
#include "ManipulatorConfiguration.h"

using namespace arma;
using namespace std;

class KinematicSolver {
    public:
        KinematicSolver (ManipulatorConfiguration configuration);
        colvec getRelativeCoords(colvec absCoords);
        colvec getAbsCoords(colvec relCoords);
    private:
        ManipulatorConfiguration _configuration;
        Jacobian _jacobian;
        CoordsTranslator _coordsTranslator;
        float _defaultAbsLinearSpeed;
        float _defaultAbsLinearAcceleration;

};


#endif //NUMTRAECTORY_KINEMATICSOLVER_H
