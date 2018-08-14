//
// Created by texnoman on 02.08.18.
//

#include "Path.h"

Path::Path(float x0, float y0, bool fill, bool absCoords, double *rgb, long id, double stroke) :
        Figure(x0, y0, fill, absCoords, rgb, id) {
    _startP.resize(1,2);
    _startP(0)=x0;
    _startP(1)=y0;
    _pointMatrix.resize(4,2);
    _pointMatrix.fill(0);
    _bezieMatrix={{-1, 3, -3, 1},
                  { 3, -6, 3, 0},
                  {-3, 3, 0,  0},
                  { 1, 0, 0,  0}};
}

fmat Path::getPointinTime(float time) {
    fmat timeMatrix={{powf(time,3), powf(time,2), time, 1.0}};
    fmat coords(1,2);
    coords=timeMatrix * _bezieMatrix* _pointMatrix;
    return 0;
}

void  Path::initCubicBezie(frowvec firstP, frowvec secondP, frowvec endP) {
    _firstP = firstP;
    _secondP = secondP;
    _endP = endP;
    _pointMatrix.row(0) = _startP;
    _pointMatrix.row(1) = _firstP;
    _pointMatrix.row(2) = _secondP;
    _pointMatrix.row(3) = _endP;
}
