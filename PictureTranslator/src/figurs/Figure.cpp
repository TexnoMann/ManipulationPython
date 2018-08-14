//
// Created by texnoman on 12.08.18.
//

#include "Figure.h"

Figure::Figure(float x0, float y0, bool fill, bool absCoords, double *rgb, long id) {
    _x0=x0;
    _y0=y0;
    _fill=fill;
    _rgb=rgb;
    _id=id;
    _absCoords=absCoords;

}
