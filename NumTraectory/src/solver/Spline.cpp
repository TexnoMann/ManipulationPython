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
   float TT; // Current degree of time                                  There |
    for(int j=0;j<n;j++) _Q(0,j)=(j==0)? 1: 0;                              //|
                                                                            //|
    for (int i = 1; i < n; i++) {                                           //|
        for (int j = 0; j < n; j++) {                                       //|
            if(i<n/2){                                                      //|
                _Q(i,j)=  (i==j)? _fact(i): 0;                              //|
            }                                                               //|
            else if(i==n/2){                                                //|
                _Q(i,j)=pow(t,j-(i-n/2));                                   //|
            }                                                               //|
            else {                                                          //|
                TT = pow(t, j-(i-n/2));                //<====================+
                _Q(i, j) = TT*(j-(i-1-n/2))*_Q(i-1, j)/(TT*t);
            }
        }
    }
    _Q(n/2,0)=1.0;
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


