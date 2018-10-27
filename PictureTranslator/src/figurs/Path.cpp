//
// Created by texnoman on 02.08.18.
//

#include "Path.h"
#include "../util/Configuration.h"

Path::Path(frowvec startxy, bool fill, bool absCoords, double *rgb, long id, double stroke) :
        Figure(startxy, fill, absCoords, rgb, id) {
    _length=0;
    _startP.resize(1,2);
    _startP=startxy;
    _pointMatrix.resize(4,2);
    _pointMatrix.fill(0);
    _bezieMatrix={{-1, 3, -3, 1},
                  { 3, -6, 3, 0},
                  {-3, 3, 0,  0},
                  { 1, 0, 0,  0}};
}

frowvec Path::getPoint(float t) {
    fmat timeMatrix={{powf(t,3), powf(t,2), t, 1.0}};
    fmat coords(1,2);
    coords=timeMatrix * _bezieMatrix* _pointMatrix;
    return coords;
}


void Path::initCubicBezie(frowvec firstP, frowvec secondP, frowvec endP) {
    _firstP = firstP;
    _secondP = secondP;
    _endP = endP;
    _pointMatrix.row(0) = _startP;
    _pointMatrix.row(1) = _firstP;
    _pointMatrix.row(2) = _secondP;
    _pointMatrix.row(3) = _endP;
    _findLength();
}

frowvec Path::getKeyPoint(int numberPoint){
    if(numberPoint>=0 && numberPoint<=3) return (frowvec)_pointMatrix.row(numberPoint);
    return 0;
}

void Path::_findLength() {
    frowvec initP=getPoint(0);
    frowvec p={initP(0),initP(1),0,0};
    _points.push_back(p);
    for (float t=TIMEPATH_PRECISION; t<=1+TIMEPATH_PRECISION; t+=TIMEPATH_PRECISION){
        frowvec currentPoint=getPoint(t);
        frowvec v=getPoint(t)-getPoint(t-TIMEPATH_PRECISION);
        frowvec av=abs(v);
        _length+=sqrt(pow(av[0],2) + pow(av[1],2));
        frowvec p={currentPoint[0],currentPoint[1],t,_length};
        _points.push_back(p);
    }
}
