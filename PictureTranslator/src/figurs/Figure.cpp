//
// Created by texnoman on 28.07.18.
//

#include "Figure.h"

Figure::Figure(float x0, float y0, bool fill, bool absCoord, double *rgb, long id, double stroke) {
    this->_x0=x0;
    this->_y0=y0;
    this->_fill=fill;
    this->_rgb=rgb;
    this->_id=id;
}

