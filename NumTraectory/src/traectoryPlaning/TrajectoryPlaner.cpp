//
// Created by texnoman on 31.03.18.
//

#include "TrajectoryPlaner.h"

TrajectoryPlaner::TrajectoryPlaner(ManipulatorConfiguration config, string datainput, string dataout)
            :_config(config),
             _dataout(DataOut(dataout)),
             _datainput(Data(datainput)),
             _kinematicSolver(_config),
             _spline(Spline(_datainput.getCountCoords()/_config.getNumberJoint()*2,_datainput.getNormTime())),
             _solver(Solver(_datainput.getCountCoords()/_config.getNumberJoint()*2))
            {
}

mat TrajectoryPlaner:: getStartAndFinishPositionJoint(int startNumberPointPosition, int finishNumberPointPosition){
    mat pos=_kinematicSolver.getfullCoordsfromPlaning(_datainput.getDesiredCoords()[startNumberPointPosition], _datainput.getDesiredCoords()[finishNumberPointPosition]);

    return pos;
}


void TrajectoryPlaner::getCoordinatsOneSegment(int startNumberPointPosition, int finishNumberPointPosit){

    mat position=getStartAndFinishPositionJoint(startNumberPointPosition,finishNumberPointPosit);

    colvec a[_config.getNumberJoint()];
    for(int i=0;i<_config.getNumberJoint();i++){
        a[i]=_spline.getCoefficient(position.col(i));

    }

        for (float time = 0; time < _datainput.getNormTime(); time += _datainput.getControllerUpdateTime()) {
            mat currentPos(_datainput.getCountCoords()/_config.getNumberJoint()*2,_config.getNumberJoint());
            currentPos.fill(0.0);
            for(int i=0;i<_config.getNumberJoint();i++){
                colvec coords= _solver.getCoords(time, a[i]);
                currentPos.col(i)=coords;
            }
            _dataout.putToFile((rowvec)(currentPos.row(0)),(rowvec)(currentPos.row(1)));
        }

}

void TrajectoryPlaner::getFullCordinatsJoints() {
    for(int segmentCount=0;segmentCount<_datainput.getCountPoints();segmentCount++) {
        getCoordinatsOneSegment(segmentCount, segmentCount + 1);
    }
    _dataout.writeClose();
}