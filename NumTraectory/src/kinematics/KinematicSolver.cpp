//
// Created by texnoman on 31.03.18.
//

#include "KinematicSolver.h"

KinematicSolver::KinematicSolver(ManipulatorConfiguration config)
        : _config(config),
          _relCoords(CoordsTranslatorRRR(config)),
          _relSpeed(JacobianRRR(config)){

}


mat KinematicSolver::_translateDataLineToCoords(colvec startPos, colvec finishPos) {
    mat coordsfromSolv(2,startPos.size());

    coordsfromSolv.fill(0.0);
    for(int i=0; i<startPos.size(); i++){
        coordsfromSolv(0,i)=startPos(i);
        coordsfromSolv(1,i)=finishPos(i);
    }

    return coordsfromSolv;
}

mat KinematicSolver::getfullCoordsfromPlaning(colvec startPos, colvec finishPos) {
    mat dataMatrix= _translateDataLineToCoords(startPos,finishPos);
    mat fullCoords= _solvDataMatrix(dataMatrix);
    return fullCoords;
}

mat KinematicSolver::_solvDataMatrix(mat dataMatrix) {
    mat solvmatrix(2,((colvec)(dataMatrix.col(1))).size());

    if (((colvec)(dataMatrix.col(1))).size()<=6){
        colvec startXYZ = {dataMatrix(0,0),dataMatrix(0,1),dataMatrix(0,2)};
        colvec startderivatedXYZ = {dataMatrix(0,3), dataMatrix(0,4), dataMatrix(0,5)};
        colvec startq1q2q3= _relCoords.getRelativeCoords(startXYZ);
        colvec startderivatedq1q2q3 = _relSpeed.getRelativeCoordsSpeed(startq1q2q3,startderivatedXYZ);

        colvec finishXYZ = {dataMatrix(1,0),dataMatrix(1,1),dataMatrix(1,2)};
        colvec finishderivatedXYZ = {dataMatrix(1,3), dataMatrix(1,4), dataMatrix(1,5)};
        colvec finishq1q2q3= _relCoords.getRelativeCoords(finishXYZ);
        colvec finishderivatedq1q2q3 = _relSpeed.getRelativeCoordsSpeed(finishq1q2q3,finishderivatedXYZ);

        solvmatrix={{startq1q2q3(0), startderivatedq1q2q3(0),startq1q2q3(1), startderivatedq1q2q3(1),startq1q2q3(2), startderivatedq1q2q3(2)},
                    {finishq1q2q3(0),finishderivatedq1q2q3(0),finishq1q2q3(1),finishderivatedq1q2q3(1),finishq1q2q3(2),finishderivatedq1q2q3(2)}};

    }
    else if(((colvec)(dataMatrix.col(1))).size()<=9){
        colvec startXYZ = {dataMatrix(0,0),dataMatrix(0,1),dataMatrix(0,2)};
        colvec startderivatedXYZ = {dataMatrix(0,3), dataMatrix(0,4), dataMatrix(0,5)};
        colvec startq1q2q3= _relCoords.getRelativeCoords(startXYZ);
        colvec startderivatedq1q2q3 = _relSpeed.getRelativeCoordsSpeed(startq1q2q3,startderivatedXYZ);
        //TODO: DerivatedJacobian


        colvec finishXYZ = {dataMatrix(1,0),dataMatrix(1,1),dataMatrix(1,2)};
        colvec finishderivatedXYZ = {dataMatrix(1,3), dataMatrix(1,4), dataMatrix(1,5)};
        colvec finishq1q2q3= _relCoords.getRelativeCoords(startXYZ);
        colvec finishderivatedq1q2q3 = _relSpeed.getRelativeCoordsSpeed(startq1q2q3,startderivatedXYZ);
        //TODO: DerivatedJacobian

        solvmatrix={{startq1q2q3(0), startderivatedq1q2q3(0),startq1q2q3(1), startderivatedq1q2q3(1),startq1q2q3(2), startderivatedq1q2q3(2)},
                    {finishq1q2q3(0),finishderivatedq1q2q3(0),finishq1q2q3(1),finishderivatedq1q2q3(1),finishq1q2q3(2),finishderivatedq1q2q3(2)}};


    }
    else {
        cout<< "Error KinematicSolver: error dimension";
        exit(0);
    }

    return trans(solvmatrix);
}
