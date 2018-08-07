//
// Created by texnoman on 28.07.18.
//

#include "Ellipses.h"

Ellipses::Ellipses(float x0, float y0, float rx, float ry, bool fill, bool absCoords, double *rgb, long id, double stroke):
        Figure(x0, y0, fill, absCoords, rgb, id, stroke) {
    this->_rx=rx;
    this->_ry=ry;
}
