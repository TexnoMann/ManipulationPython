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
        _defaultRelAcceleration = 0.3;
        _defaultRelSpeed= 0.8;
        
}

mat KinematicSolver::getRelativeCoords(mat absCoords) {
    int numberCoords = absCoords.size();
    mat relCoords(numberCoords,1);
    relCoords.fill(0);
    if(numberCoords<2) {
        cout<< "Error init coords.";
        exit(0);
    }
    else if(numberCoords==2){

    }

}
