//
// Created by texnoman on 31.03.18.
//

#include "KinematicSolverRRR.h"

KinematicSolver::KinematicSolver(ManipulatorConfiguration config)
        : _config(config),
          _relCoords(CoordsTranslatorRRR(config)),
          _relSpeed(SpeedTranslatorRRR(config)),
          _relAcc(AccelerationTranslator(config)){

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
    mat solvmatrix(_config.getNumberJoint(),((colvec)(dataMatrix.col(1))).size());

    if (((colvec)(dataMatrix.col(1))).size()<=6){
        colvec startXYZ = {dataMatrix(0,0),dataMatrix(0,1),dataMatrix(0,2)};
        colvec startSpeedXYZ = {dataMatrix(0,3), dataMatrix(0,4), dataMatrix(0,5)};
        colvec startq1q2q3= _relCoords.getRelativeCoords(startXYZ);
        colvec startSpeedq1q2q3 = _relSpeed.getRelativeCoordsSpeed(startq1q2q3,startSpeedXYZ);

        colvec finishXYZ = {dataMatrix(1,0),dataMatrix(1,1),dataMatrix(1,2)};
        colvec finishSpeedXYZ = {dataMatrix(1,3), dataMatrix(1,4), dataMatrix(1,5)};
        colvec finishq1q2q3= _relCoords.getRelativeCoords(finishXYZ);
        colvec finishSpeedq1q2q3 = _relSpeed.getRelativeCoordsSpeed(finishq1q2q3,finishSpeedXYZ);

        solvmatrix={{startq1q2q3(0), startSpeedq1q2q3(0),finishq1q2q3(0),finishSpeedq1q2q3(0)},
                    {startq1q2q3(1), startSpeedq1q2q3(1),finishq1q2q3(1),finishSpeedq1q2q3(1)},
                    {startq1q2q3(2), startSpeedq1q2q3(2),finishq1q2q3(2),finishSpeedq1q2q3(2)}};

    }
    else if(((colvec)(dataMatrix.col(1))).size()<=9){
        colvec startXYZ = {dataMatrix(0,0),dataMatrix(0,1),dataMatrix(0,2)};
        colvec startSpeedXYZ = {dataMatrix(0,3), dataMatrix(0,4), dataMatrix(0,5)};
        colvec startAccelerationXYZ={dataMatrix(0,6), dataMatrix(0,7), dataMatrix(0,8)};

        colvec startq1q2q3= _relCoords.getRelativeCoords(startXYZ);
        colvec startSpeedq1q2q3 = _relSpeed.getRelativeCoordsSpeed(startq1q2q3,startSpeedXYZ);
        colvec startAccelerationq1q2q3=_relAcc.getRelativeAcceleration(startSpeedq1q2q3, startAccelerationXYZ, _relSpeed.getJacobianMatrixCoordsfromRRR(startq1q2q3), startq1q2q3);
        //TODO: DerivatedJacobian


        colvec finishXYZ = {dataMatrix(1,0),dataMatrix(1,1),dataMatrix(1,2)};
        colvec finishSpeedXYZ = {dataMatrix(1,3), dataMatrix(1,4), dataMatrix(1,5)};
        colvec finishAccelerationXYZ={dataMatrix(1,6), dataMatrix(1,7), dataMatrix(1,8)};
        colvec finishq1q2q3= _relCoords.getRelativeCoords(finishXYZ);
        colvec finishSpeedq1q2q3 = _relSpeed.getRelativeCoordsSpeed(finishq1q2q3,finishSpeedXYZ);
        colvec finishAccelerationq1q2q3=_relAcc.getRelativeAcceleration(finishSpeedq1q2q3, finishAccelerationXYZ, _relSpeed.getJacobianMatrixCoordsfromRRR(finishq1q2q3), finishq1q2q3);
        //TODO: DerivatedJacobian

        solvmatrix={{startq1q2q3(0), startSpeedq1q2q3(0),startAccelerationq1q2q3(0),finishq1q2q3(0),finishSpeedq1q2q3(0), finishAccelerationq1q2q3(0)},
                    {startq1q2q3(1), startSpeedq1q2q3(1),startAccelerationq1q2q3(1),finishq1q2q3(1),finishSpeedq1q2q3(1), finishAccelerationq1q2q3(1)},
                    {startq1q2q3(2), startSpeedq1q2q3(2),startAccelerationq1q2q3(2),finishq1q2q3(2),finishSpeedq1q2q3(2), finishAccelerationq1q2q3(2)}};

    }
    else {
        cout<< "Error KinematicSolver: error dimension";
        exit(202);
    }

    return trans(solvmatrix);
}
