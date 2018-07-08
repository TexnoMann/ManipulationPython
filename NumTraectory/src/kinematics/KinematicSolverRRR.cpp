//
// Created by texnoman on 31.03.18.
//

#include "KinematicSolverRRR.h"

KinematicSolver::KinematicSolver(const ManipulatorConfiguration config)
        : _config(config),
          _relCoords(CoordsTranslatorRRR(config)),
          _relSpeed(SpeedTranslatorRRR(config)),
          _relAcc(AccelerationTranslator(config)){
}


fmat KinematicSolver::_getRelCoords(fmat absPoint){
    fmat jointRelCoords(_config.getNumberJoint(), absPoint.n_cols);
    jointRelCoords.fill(0.0);
    jointRelCoords.col(0) = _relCoords.getRelativeCoords(absPoint.col(0));
    if(absPoint.n_cols > 1) {
        jointRelCoords.col(1) = _relSpeed.getRelativeCoordsSpeed(jointRelCoords.col(0), absPoint.col(1));
        if(absPoint.n_cols > 2){
            //#TODO:Acceleration
        }
    }
    return jointRelCoords;
}





