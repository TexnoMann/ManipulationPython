//
// Created by texnoman on 27.02.18.
//
#include <armadillo>
#include "Spline.h"


using namespace std;
using namespace arma;

Spline::Spline(int n) {
    _n = n;

    _a=mat(_n, 1);
    _a.fill(0.0);

    _Q=mat(_n, n);
    _Q.fill(0.0);
    int linepair = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) {
                if (linepair == 0) _Q(i, 0) = 1;
                else if (j == linepair) _Q(i, j) = _fact(j);
                else _Q(i,j)=0;
                linepair++;
            }
        }
    }
    cout<<_Q;
}

float* Spline::getA(mat initCoords){
    _a=inv(_Q)* initCoords;
    }


int Spline::_fact(int count){
    int d=1;
    for(int i=1;i<=count;i++) d*=i;
    return d;
}


