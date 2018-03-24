//
// Created by texnoman on 07.03.18.
//

#include "TraectoryPlaner.h"
#include "../kinematics/CoordsTranslator.h"
#include "../output/DataOut.h"

TraectoryPlaner::TraectoryPlaner(string filename, ManipulatorConfiguration configuration)
        :_data(_filename),
         _spline(_data.getN(),
         _data.getNormTime()),
         _solver(_data.getN())
{
    _filename=filename;
    _data=Data(_filename);
    _spline=Spline(_data.getN(),_data.getNormTime());
    _solver=Solver(_data.getN());

}

void TraectoryPlaner:: generateTrajectory(DataOut out){

}

float TraectoryPlaner:: tuneTime(float time){
    float newTime= time-(fmod(time, _data.getNormTime()));
    return newTime;
}


colvec TraectoryPlaner::_getPolyValue(colvec initCoords, float currentTime){
    _coeff= _spline.getCoefficient(initCoords);
    colvec coords=_solver.getCoords(currentTime,_coeff);
    return coords;
}

mat TraectoryPlaner::InverseTaskKinematicSolv(mat) {

}

