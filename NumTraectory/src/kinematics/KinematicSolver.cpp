//
// Created by texnoman on 24.03.18.
//

#include "KinematicSolver.h"

KinematicSolver::KinematicSolver(ManipulatorConfiguration configuration) :
        _configuration(configuration),
        _jacobian(Jacobian(_configuration)),
        _coordsTranslator(CoordsTranslator(_configuration)){

        _defaultAbsLinearAcceleration = 0.02;
        _defaultAbsLinearSpeed = 0.1;

}

colvec KinematicSolver::getRelativeCoords(colvec initCoords) { //Matrix initCoords: (X,Y,Z,timetravel)
    float X=initCoords(0,0);
    float Y=initCoords(1,0);
    float Z=initCoords(2,0);

    colvec absCoordinats = {X,Y,Z};


    return absCoordinats;

    }


