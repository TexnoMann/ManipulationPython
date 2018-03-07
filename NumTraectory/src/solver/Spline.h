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
<<<<<<< HEAD
        Spline(int n);
        mat getA(mat initCoords);
        mat get_q(mat _a, float t, int n);
        mat make_Q(float t, int n);
=======
        Spline(int n, int t);
        float* getA(mat initCoords);

>>>>>>> e7b1abdb9887dd26f57dce0ce9a0764e1583755f
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
