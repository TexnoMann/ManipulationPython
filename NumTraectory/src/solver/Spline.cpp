//
// Created by texnoman on 27.02.18.
//

#include "Spline.h"

using namespace std;
using namespace arma;

Spline::Spline(int n, float normTime) {
    _n = n;
    _normTime=normTime;
    _a=colvec(_n, 1);
    _a.fill(0.0);
    _Q=mat(_n, _n);
    _Q.fill(0.0);
}

colvec Spline::getCoefficient(colvec initCoords){
    _a=inv( _make_Q(_normTime) ) * initCoords;
    return _a;
    }


mat Spline:: _make_Q(float time){

    _Q.fill(0.0);
    float TT; // Current degree of time
    for(int j=0;j<_n;j++) _Q(0,j)=(j==0)? 1: 0;
    for (int i = 1; i <_n; i++) {
        for (int j = 0; j <_n; j++) {
            if(i<_n/2){
                _Q(i,j)=  (i==j)? _fact(i): 0;
            }
            else if(i==_n/2){
                _Q(i,j)=pow(time,j-(i-_n/2));
            }
            else {
                TT = pow(time, j-(i-_n/2));
                _Q(i, j) = TT*(j-(i-1-_n/2))*_Q(i-1, j)/(TT*time);
            }
        }
    }

    _Q(_n/2,0)=1.0;
    return _Q;
}

int Spline::_fact(int count){
    int d=1;
    for(int i=1;i<=count;i++) d*=i;
    return d;
}





