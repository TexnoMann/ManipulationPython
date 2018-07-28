//
// Created by texnoman on 28.07.18.
//

#ifndef PICTURETRANSLATOR_CIRCLE_H
#define PICTURETRANSLATOR_CIRCLE_H


#include "Figure.h"

class Ellipses: public Figure {
public:
    Ellipses(float x0, float y0, float rx, float ry, bool fill, double rgb[]);
private:
    float _rx;
    float _ry;
};


#endif //PICTURETRANSLATOR_CIRCLE_H
