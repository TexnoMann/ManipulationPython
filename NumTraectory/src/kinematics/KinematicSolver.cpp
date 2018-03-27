//
// Created by texnoman on 24.03.18.
//

#include "KinematicSolver.h"

KinematicSolver::KinematicSolver(ManipulatorConfiguration configuration) :
        _configuration(configuration),
        _coordsTranslator(CoordsTranslator(_configuration)),
        _jacobian(Jacobian(_configuration)){

}

colvec KinematicSolver::getVectorMoving(colvec initCoords) { //Matrix initCoords: (time, X,Y,Z, X',Y',Z', X'',Y'',Z'')


    colvec absCoordinats = {initCoords(0,0),initCoords(1,0),initCoords(2,0)};
    colvec relCoordinats = _coordsTranslator.getRelativeCoords(absCoordinats);

    colvec absSpeed = { initCoords(3,0),initCoords(4,0), initCoords(5,0)};
    colvec relSpeed = _jacobian.getRelativeCoordsSpeed(relCoordinats, absSpeed);

    colvec moving(initCoords.size());

    if(initCoords.size()>6) {
        colvec absAcceleration = {initCoords(6,0), initCoords(7,0), initCoords(8,0)}; //TODO Derivated Jacobian
        colvec relAcceleration;

        moving = {relCoordinats(0,0), relCoordinats(1,0), relCoordinats(2,0),
                         relSpeed(0,0), relSpeed(1,0), relSpeed(2,0),
                         relAcceleration(0,0), relAcceleration(1,0), relAcceleration(2,0)};
    }

    else {
        moving = {relCoordinats(0,0), relCoordinats(1,0), relCoordinats(2,0),
                         relSpeed(0,0), relSpeed(1,0), relSpeed(2,0)};
    }

    return moving;

    }


