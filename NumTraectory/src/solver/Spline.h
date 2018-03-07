//
// Created by texnoman on 27.02.18.
//
#include <armadillo>
#ifndef MANNUM_SPLINE_H
#define MANNUM_SPLINE_H

using namespace std;
using namespace arma;
class Spline {
    public:
        Spline(int n, int t);
        float* getA(mat initCoords);

    private:
        mat initCoords;
        int _n;
        mat _a;
        mat _Q;
        int _t;
        int _fact(int count);
};



#endif //MANNUM_SPLINE_H
