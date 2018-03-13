//
// Created by texnoman on 07.03.18.
//
#include <armadillo>
#include "../input/Data.h"
#include "../solver/Spline.h"
#include "../solver/Solver.h"
#include "../Kinematics/ManipulatorConfiguration.h"

#ifndef NUMTRAECTORY_TRAECTORYPLANER_H
#define NUMTRAECTORY_TRAECTORYPLANER_H


using namespace arma;
using namespace std;

class TraectoryPlaner {
    public:
        TraectoryPlaner(string filename, ManipulatorConfiguration configuration);
    private:
        float _normTime;
        float _n;
        string _filename;


        mat _translateAbsToRelativeCoords(mat absCoord);
        mat _transtateRelativeToAbsCoords(mat relCoord);
};


#endif //NUMTRAECTORY_TRAECTORYPLANER_H
