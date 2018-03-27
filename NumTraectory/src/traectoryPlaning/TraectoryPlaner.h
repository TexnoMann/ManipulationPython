//
// Created by texnoman on 07.03.18.
//
#include <armadillo>
#include "../input/Data.h"
#include "../solver/Spline.h"
#include "../solver/Solver.h"
#include "../kinematics/ManipulatorConfiguration.h"
#include "../output/DataOut.h"
#include "../kinematics/KinematicSolver.h"

#ifndef NUMTRAECTORY_TRAECTORYPLANER_H
#define NUMTRAECTORY_TRAECTORYPLANER_H


using namespace arma;
using namespace std;

class TraectoryPlaner {
    public:
        TraectoryPlaner(string filename, ManipulatorConfiguration configuration);
        vector <colvec> generateTrajectory(DataOut out);

    private:
        float _n;
        string _filename;
        colvec _coeff;


        Data _data;
        Solver _solver;
        Spline _spline;
        KinematicSolver _kinematicSolver;

        colvec _getPolyValue(colvec initCoords, float currentTime);
        float tuneTime(float time);
        mat InverseTaskKinematicSolv(mat relCoords);

};


#endif //NUMTRAECTORY_TRAECTORYPLANER_H
