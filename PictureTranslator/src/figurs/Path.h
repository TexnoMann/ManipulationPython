//
// Created by texnoman on 02.08.18.
//

#ifndef PICTURETRANSLATOR_PATH_H
#define PICTURETRANSLATOR_PATH_H


#include "Figure.h"

class Path: public Figure {
public:
    Path(float x0, float y0, bool fill, bool absCoords, double rgb[], long id, double stroke);
private:
    
};


#endif //PICTURETRANSLATOR_PATH_H
