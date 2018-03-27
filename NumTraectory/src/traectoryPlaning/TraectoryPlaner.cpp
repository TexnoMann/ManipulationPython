//
// Created by texnoman on 07.03.18.
//

#include "TraectoryPlaner.h"
#include "../kinematics/CoordsTranslator.h"
#include "../output/DataOut.h"

TraectoryPlaner::TraectoryPlaner(string filename, ManipulatorConfiguration configuration)
        :_data(_filename),
         _spline(_data.getN(), _data.getNormTime()),
         _solver(_data.getN()),
         _kinematicSolver(configuration){

    _filename=filename;
    _data=Data(_filename);
    _solver=Solver(_data.getN());
    _kinematicSolver=KinematicSolver(configuration);

}

vector <colvec> TraectoryPlaner:: generateTrajectory(DataOut out){
    int pointCounts=_data.getDesiredCoords().size();
    int countKnowCoords= _data.getDesiredCoords()[0].size();
    colvec a;
    vector <colvec> finalCoordinats;
    colvec firstRelCoords(countKnowCoords);
    colvec secondRelCoords(countKnowCoords);
    for(int i=0;i<pointCounts; i++){
        firstRelCoords = _kinematicSolver.getVectorMoving(_data.getDesiredCoords()[i]);// q1, q2, q3, q1', q2' ,q3' ,q1'', q2'',q3''
        secondRelCoords =_kinematicSolver.getVectorMoving( _data.getDesiredCoords()[i+1]);
        colvec Joint1coords;
        colvec Joint2coords;
        colvec Joint3coords;

        colvec a1;
        colvec a2;
        colvec a3;

        if(firstRelCoords.size()>6){
            Joint1coords={firstRelCoords(0,0),firstRelCoords(3,0), firstRelCoords(6,0),secondRelCoords(0,0),secondRelCoords(3,0), secondRelCoords(6,0)};
            Joint2coords={firstRelCoords(1,0),firstRelCoords(4,0), firstRelCoords(7,0),secondRelCoords(1,0),secondRelCoords(4,0), secondRelCoords(7,0)};
            Joint3coords= {firstRelCoords(2, 0), firstRelCoords(5, 0), firstRelCoords(8, 0), secondRelCoords(2, 0), secondRelCoords(5, 0), secondRelCoords(8, 0)};
        }
        else{
            Joint1coords={firstRelCoords(0,0),firstRelCoords(3,0),secondRelCoords(0,0),secondRelCoords(3,0)};
            Joint2coords={firstRelCoords(1,0),firstRelCoords(4,0),secondRelCoords(1,0),secondRelCoords(4,0)};
            Joint3coords= {firstRelCoords(2,0), firstRelCoords(5,0), secondRelCoords(2,0), secondRelCoords(5,0)};

        }

        a1 =_spline.getCoefficient(Joint1coords);
        a2 =_spline.getCoefficient(Joint2coords);
        a3 =_spline.getCoefficient(Joint2coords);

        colvec fullfinalCoords(firstRelCoords.size(),0);
        colvec finalcoordsJoint1;
        colvec finalcoordsJoint2;
        colvec finalcoordsJoint3;

        for (int time=0;time<_data.getNormTime();time+=_data.getControllerUpdateTime()){
            finalcoordsJoint1 = _solver.getCoords(time,a1);
            finalcoordsJoint2 = _solver.getCoords(time,a2);
            finalcoordsJoint3 = _solver.getCoords(time,a3);

            for(int j=0;j<finalcoordsJoint1.size();j++){
                fullfinalCoords(j,0)=finalcoordsJoint1(j,0);
                fullfinalCoords(j+finalcoordsJoint1.size(),0)=finalcoordsJoint2(j,0);
                fullfinalCoords(j+2*finalcoordsJoint1.size(),0)=finalcoordsJoint3(j,0);
            }
            finalCoordinats.push_back(fullfinalCoords);
        }


    }

    return finalCoordinats;
}




