//
// Created by texnoman on 27.02.18.
//

#include "Spline.h"

using namespace std;
using namespace arma;

Spline::Spline(int n, int t) {
    _n = n;
    _t=t;

    _a=mat(_n, 1);
    _a.fill(0.0);
    _Q = make_Q(time, _n ); // Normir time
    _Q=mat(_n, n);
    _Q.fill(0.0);
    cout<<_Q;
}

mat Spline::getA(mat initCoords){
    _a=inv(_Q)* initCoords;
    return _a;
    }

int Spline::_fact(int count){
    int d=1;
    for(int i=1;i<=count;i++) d*=i;
    return d;
}

mat Spline::get_q(mat _a, float t, int n){
    return make_Q(t, n)*_a;
}

mat Spline:: make_Q(float t,int  n){   // Create Q
    mat Q;
    float TT; // Current degree of time                                  There |
    for(int j=0;j<n;j++) Q(0,j)=(j==0)? 1: 0;                                //|
                                                                             //|
    for (int i = 1; i < n; i++) {                                            //|
        for (int j = 0; j < n; j++) {                                        //|
            if(i<n/2){                                                       //|
                Q(i,j)=  (i==j)? _fact(i): 0;                                //|
            }                                                                //|
            else if(i==n/2){                                                 //|
                Q(i,j)=pow(t,j-(i-n/2));                                     //|
            }                                                                //|
            else {                                                           //|
                TT = pow(t, j-(i-n/2));                //<=====================+
                Q(i, j) = TT*(j-(i-1-n/2))*Q(i-1, j)/(TT*t);
            }
        }
    }
    Q(n/2,0)=1.0;
    return Q;
}


