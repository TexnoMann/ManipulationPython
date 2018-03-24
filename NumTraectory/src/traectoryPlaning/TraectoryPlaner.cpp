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

    int numberPoint = _data.getDesiredCoords().size();
    int numberCoords=_data.getDesiredCoords()[0].size();

    vector <mat> relCoordsList;


    for(int i=1;i<numberPoint;i++){
        mat coordsAbsFirst=_data.getDesiredCoords()[i-1];
        mat coordsAbsSecond= _data.getDesiredCoords()[i];
        mat absCoords(numberCoords,1);
        for (int j=0;j<numberCoords;j++){
            absCoords(j,0) = coordsAbsFirst(j,0);
            absCoords(j+numberCoords,0) = coordsAbsSecond(j,0);


        }
    }
}

float TraectoryPlaner:: tuneTime(float time){
    float newTime= time-(fmod(time, _data.getNormTime()));
    return newTime;
}


mat TraectoryPlaner::_getPolyValue(mat initCoords, float currentTime){
    _coeff= _spline.getCoefficient(initCoords);
    mat coords=_solver.getCoords(currentTime,_coeff);
    return coords;
}

mat TraectoryPlaner::InverseTaskKinematicSolv(mat relCoords) {

}

