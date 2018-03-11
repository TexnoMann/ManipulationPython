//
// Created by texnoman on 07.03.18.
//
#include <armadillo>
#include "../input/Data.h"
#include "../solver/Spline.h"
#include "../solver/Solver.h"

#ifndef NUMTRAECTORY_TRAECTORYPLANER_H
#define NUMTRAECTORY_TRAECTORYPLANER_H


using namespace arma;
using namespace std;

class TraectoryPlaner {
    public:
        TraectoryPlaner(string filename);
    private:
        float _normTime;
        float _n;
        string _filename;
        Data _data(string filename);
        Spline _spline(int n, float normTime);
        Solver _solver(int n);


        mat _translateAbsToRelativeCoords(mat absCoord);

        mat _transtateRelativeToAbsCoords(mat relCoord);
};


#endif //NUMTRAECTORY_TRAECTORYPLANER_H
