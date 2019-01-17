//
// Created by texnoman on 12.08.18.
//

#include "Figure.h"

Figure::Figure(frowvec startxy, bool fill, bool absCoords, double *rgb, long id) {
    _startxy=startxy;
    _fill=fill;
    _rgb=rgb;
    _id=id;
    _absCoords=absCoords;
    _length=0;

}

frowvec Figure::getPoint(float param1) {
    frowvec p={0,0};
    return p;
}

frowvec Figure::getKeyPoint(int numberPoint) {
    frowvec p={0,0};
    return p;
}

float Figure::getLength() {
    return _length;
}

void Figure::_findLength() {}

frowvec Figure::getPointsinDistance(float distance) {
    int pointNumber=_points.size()-1;
    for(int i=1;i<_points.size();i++){
        float currentLength=_points[i](3);
        if(currentLength>=distance){
            pointNumber=i-1;
            break;
        }
    }
    return _points[pointNumber];
}