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

class SolverSpline {
    public:
        SolverSpline(int n);


    fcolvec getCoords(float currentTime, fcolvec a);

    private:
        fmat _Q;
        int _n;
        fcolvec _coords;
        fmat _getPoly(float currentTime);


};


#endif
