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
        Spline(int n);
        mat getA(mat initCoords);
        mat get_q(mat _a, float t, int n);
        mat make_Q(float t, int n);

    private:
        mat initCoords;
        float time; //Normir time. Change how you want!
        int _n;
        mat _a;
        mat _Q;
        int _t;
        int _fact(int count);
};



#endif //MANNUM_SPLINE_H
