//
// Created by texnoman on 27.02.18.
//
#include "Spline.h"
#include "../input/Data.h"
#include <armadillo>

#ifndef MANNUM_SOLVER_H
#define MANNUM_SOLVER_H

using namespace arma;

class Solver {
    public:
        Solver( Data data, float normTime);
        mat getCoords(float currentTime, mat a);

    private:
        mat _Q;
        int _n;
        mat _normTime;
        Data _data(string filename);
        Spline _spline(int n, float normTime);
        mat _getPoly(float currentTime);
        int _fact(int count);

};


#endif
