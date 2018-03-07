//
// Created by texnoman on 27.02.18.
//
#include "Spline.h"
#include "Solver.h"
#include <armadillo>

using namespace std;
using namespace arma;

Solver::Solver(Data data) {
    int n;
    Spline _spline(_n);
    _spline = getSpline(data.q0, data.q1 );
    mat _a = _spline.getA(/*MATI INITCORDINATI*/);






}
Spline getSpline(/*MATI INITCORDINATI*/int n){
    Spline spline(n);

    return spline;
}
