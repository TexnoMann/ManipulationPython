//
// Created by texnoman on 29.11.18.
//

#ifndef PICTURETRANSLATOR_LINE_H
#define PICTURETRANSLATOR_LINE_H


#include "Figure.h"
#include "Path.h"

class Line: public Figure {

public:
    Line(frowvec startxy, bool fill, bool absCoords, double rgb[], long id, double stroke);
    void virtual initLine(frowvec secondPoint);
    frowvec getPoint(float t);
    frowvec getKeyPoint(int numberPoint);
    vector <frowvec> getPointsinDistance();
private:
    void _findLength();


};


#endif //PICTURETRANSLATOR_LINE_H
