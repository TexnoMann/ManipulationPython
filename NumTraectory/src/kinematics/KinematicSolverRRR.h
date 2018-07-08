//
// Created by texnoman on 31.03.18.
//

#ifndef NUMTRAECTORY_KINEMATICSOLVER_H
#define NUMTRAECTORY_KINEMATICSOLVER_H

#include <armadillo>
#include "ManipulatorConfiguration.h"
#include "CoordsTranslatorRRR.h"
#include "SpeedTranslatorRRR.h"
#include "AccelerationTranslatorRRR.h"

using namespace std;
using namespace arma;

class KinematicSolver {


public:
    KinematicSolver(const ManipulatorConfiguration config);
    fmat _getRelCoords(fmat point);

private:
    ManipulatorConfiguration _config;
    CoordsTranslatorRRR _relCoords;
    SpeedTranslatorRRR _relSpeed;
    AccelerationTranslator _relAcc;

};


#endif //NUMTRAECTORY_KINEMATICSOLVER_H
