//
// Created by texnoman on 27.02.18.
//
#include "Spline.h"
#include "../input/Data.h"

#ifndef MANNUM_SOLVER_H
#define MANNUM_SOLVER_H

class Solver {
    public:
        Solver(int n, Data data);
        void getSpline(float q0[], float q1[]);

    private:
        Data _data();
        float _q0;
        float _q1;
        int _n;
        Spline _spline(int n);

};


#endif
