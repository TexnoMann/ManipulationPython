//
// Created by texnoman on 27.02.18.
//
#include "Spline.h"
#include "../input/Data.h"
#include <armadillo>

#ifndef MANNUM_SOLVER_H
#define MANNUM_SOLVER_H

using namespace arma;
using namespace std;

class Solver {
    public:
        Solver(int n);


    mat getCoords(float currentTime, mat a);

    private:
        mat _Q;
        int _n;
        mat _coords;
        mat _getPoly(float currentTime);


};


#endif
