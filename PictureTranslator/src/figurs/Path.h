//
// Created by texnoman on 02.08.18.
//

#ifndef PICTURETRANSLATOR_PATH_H
#define PICTURETRANSLATOR_PATH_H


#include "Figure.h"
using namespace arma;

class Path: public Figure {
public:
    Path(float x0, float y0, bool fill, bool absCoords, double rgb[], long id, double stroke);
    void initCubicBezie(frowvec firstP, frowvec secondP, frowvec endP);
    fmat getPointinTime(float time);
private:
    fmat _pointMatrix;
    fmat _bezieMatrix;
    frowvec _startP;
    frowvec _firstP;
    frowvec _secondP;
    frowvec _endP;
};


#endif //PICTURETRANSLATOR_PATH_H
