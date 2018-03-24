//
// Created by texnoman on 07.03.18.
//
#include <armadillo>
#include "../input/Data.h"
#include "../solver/Spline.h"
#include "../solver/Solver.h"
#include "../kinematics/ManipulatorConfiguration.h"
#include "../output/DataOut.h"

#ifndef NUMTRAECTORY_TRAECTORYPLANER_H
#define NUMTRAECTORY_TRAECTORYPLANER_H


using namespace arma;
using namespace std;

class TraectoryPlaner {
    public:
        TraectoryPlaner(string filename, ManipulatorConfiguration configuration);
        void generateTrajectory(DataOut out);

    private:
        Data _data;
        Solver _solver;
        Spline _spline;

        float _n;
        string _filename;
        mat _poly;
        mat _coeff;
        mat _getPolyValue(mat initCoords, float currentTime);
        float tuneTime(float time);
        mat InverseTaskKinematicSolv(mat relCoords);
};


#endif //NUMTRAECTORY_TRAECTORYPLANER_H
