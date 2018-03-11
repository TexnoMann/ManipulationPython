//
// Created by texnoman on 27.02.18.
//
#include "Spline.h"
#include "../input/Data.h"
#include "Solver.h"
#include <armadillo>

using namespace std;
using namespace arma;



Solver::Solver(int n) {
    _n=n;
    _Q=mat(_n, _n);
    _Q.fill(0.0);
    _coords=mat(_n,1);
    _coords.fill(0.0);
}

mat Solver::getCoords(float currentTime, mat a){
    _coords=(_getPoly(currentTime) * a);
}


mat Solver::_getPoly(float currentTime) {
    _Q.fill(0.0);
    float TT; // Current degree of time
    for(int j=0;j<_n;j++) _Q(0,j)=(j==0)? 1: 0;

    for (int i = 0; i <_n; i++) {
        for (int j = 0; j <_n; j++) {
            if(i==0) _Q(i, j) = pow(time, j - i);
            else if(i==_n/2) _Q(i, j) = pow(time, j - (i - _n / 2));

            else if (i>_n/2) {
                TT = pow(time, j-(i-_n/2));
                _Q(i, j) = TT*(j-(i-1-_n/2))*_Q(i-1, j)/(TT*currentTime);
                _Q(i-_n/2, j) = TT*(j-(i-1-_n/2))*_Q(i-1, j)/(TT*currentTime);
            }
        }
    }
    return _Q;
}




