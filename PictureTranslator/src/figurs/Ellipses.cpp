//
// Created by texnoman on 28.07.18.
//

#include "Ellipses.h"

Ellipses::Ellipses(float x0, float y0, float rx, float ry, bool fill, double *rgb, int id):
        Figure(x0,y0,fill, rgb, id) {
    this->_rx=rx;
    this->_ry=ry;
}
