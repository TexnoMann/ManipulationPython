//
// Created by texnoman on 27.02.18.
//
#include "Spline.h"
#include "../input/Data.h"
#include "Solver.h"
#include <armadillo>

using namespace std;
using namespace arma;



Solver::Solver(Data data, float normTime) {
    _Q=mat(_n, _n);
    _Q.fill(0.0);
}

mat Solver::getCoords(float currentTime, mat a){
    return (_getPoly(currentTime) * a);
}


mat Solver::_getPoly(float currentTime) {
    _Q.fill(0.0);
    float TT; // Current degree of time
    for(int j=0;j<_n;j++) _Q(0,j)=1*pow(currentTime,j);

    for (int i = 1; i <_n; i++) {
        for (int j = 0; j <_n; j++) {
            if(i<_n/2){
                _Q(i,j)=  (i==j)? _fact(i): 0;
            }
            else if(i==_n/2){
                _Q(i,j)=pow(currentTime,j-(i-_n/2));
            }
            else {
                TT = pow(currentTime, j-(i-_n/2));
                _Q(i, j) = TT*(j-(i-1-_n/2))*_Q(i-1, j)/(TT*currentTime);
            }
        }
    }
    _Q(_n/2,0)=1.0;
    return _Q;
}

int Solver::_fact(int count){
    int d=1;
    for(int i=1;i<=count;i++) d*=i;
    return d;
}

