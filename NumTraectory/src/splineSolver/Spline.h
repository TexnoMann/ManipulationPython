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
        Spline(int n, float normTime);
        fcolvec getCoefficient(fcolvec initCoords);

    private:
        float _normTime;
        int _n;
        fcolvec _a;
        fmat _Q;
        int _fact(int count);
        fmat _make_Q(float t);
};



#endif //MANNUM_SPLINE_H
