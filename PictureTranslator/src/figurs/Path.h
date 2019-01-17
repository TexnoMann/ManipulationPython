//
// Created by texnoman on 02.08.18.
//

#ifndef PICTURETRANSLATOR_PATH_H
#define PICTURETRANSLATOR_PATH_H


#include "Figure.h"
using namespace arma;

class Path: public Figure {
public:
    Path(frowvec startxy, bool fill, bool absCoords, double rgb[], long id, double stroke);
    void virtual initCubicBezie(frowvec firstP, frowvec secondP, frowvec endP);
    frowvec getPoint(float t);
    frowvec getKeyPoint(int numberPoint);
    vector <frowvec> getPointsinDistance();

private:
    fmat _pointMatrix;
    fmat _bezieMatrix;
    frowvec _startP;
    frowvec _firstP;
    frowvec _secondP;
    frowvec _endP;
    void _findLength();
};


#endif //PICTURETRANSLATOR_PATH_H
