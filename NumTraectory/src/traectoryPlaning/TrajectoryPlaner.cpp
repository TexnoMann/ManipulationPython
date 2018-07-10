//
// Created by texnoman on 31.03.18.
//

#include "TrajectoryPlaner.h"

TrajectoryPlaner::TrajectoryPlaner(ManipulatorConfiguration config, string datainput, string dataout)
            :_config(config),
             _dataout(DataOut(dataout)),
             _datainput(Data(datainput)),
             _kinematicSolver(_config),
             _spline(Spline(_datainput.getCountParameters()*2,_datainput.getNormTime())),
             _solver(SolverSpline(_datainput.getCountParameters()*2))
            {

}



void TrajectoryPlaner::getCoordinatsOneSplineSegment(fmat firstPos, fmat secondPos){

    fmat firstRelCoords = _kinematicSolver._getRelCoords(firstPos);
    fmat secondRelCoords = _kinematicSolver._getRelCoords(secondPos);
    fmat FSPosition = arma::join_rows(firstRelCoords,secondRelCoords);
    fcolvec a[_config.getNumberJoint()];
    for(int i=0;i<_config.getNumberJoint();i++){
        a[i]=_spline.getCoefficient(trans(FSPosition.row(i)));

    }

        for (float time = 0; time < _datainput.getNormTime(); time += _datainput.getControllerUpdateTime()) {
            fmat currentPos(_config.getNumberJoint(),_datainput.getCountParameters());
            currentPos.fill(0.0);
            for(int i=0;i<_config.getNumberJoint();i++){
                fcolvec coords = _solver.getCoords(time, a[i]).rows(0,_datainput.getCountParameters()-1);
                currentPos.row(i)=trans(coords);
            }
            _dataout.putToFile(currentPos);
        }

}

void TrajectoryPlaner::getFullCordinatsJoints() {
    for(int segmentCount=0;segmentCount<_datainput.getCountPoints()-1;segmentCount++) {
        getCoordinatsOneSplineSegment(_datainput.getDesiredCoords()[segmentCount],
                                      _datainput.getDesiredCoords()[segmentCount + 1]);
    }
    _dataout.writeClose();
}