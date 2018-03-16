//
// Created by texnoman on 07.03.18.
//
#include <armadillo>
#include "../input/Data.h"
#include "../solver/Spline.h"
#include "../solver/Solver.h"
#include "../Kinematics/ManipulatorConfiguration.h"
#include "../Kinematics/Jacobian.h"

#ifndef NUMTRAECTORY_TRAECTORYPLANER_H
#define NUMTRAECTORY_TRAECTORYPLANER_H


using namespace arma;
using namespace std;

class TraectoryPlaner {
    public:
        TraectoryPlaner(string filename, ManipulatorConfiguration configuration);

    private:
        Data _data;
        Solver _solver;
        Spline _spline;
        float _normTime;
        float _n;
        string _filename;
        mat _generateSplineSegment(mat initCoords);
};


#endif //NUMTRAECTORY_TRAECTORYPLANER_H
