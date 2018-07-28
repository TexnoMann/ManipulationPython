//
// Created by texnoman on 28.07.18.
//

#include "Ellipses.h"

Ellipses::Ellipses(float x0, float y0, float rx, float ry, bool fill, double *rgb):
        Figure(x0,y0,fill, rgb) {
    this->rx=rx;
    this->ry=ry;
}
