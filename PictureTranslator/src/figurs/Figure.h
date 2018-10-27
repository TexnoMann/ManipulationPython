//
// Created by texnoman on 28.07.18.
//

#ifndef PICTURETRANSLATOR_FIGURE_H
#define PICTURETRANSLATOR_FIGURE_H

#include <array>
#include <vector>
#include <armadillo>


using namespace std;
using namespace arma;

class Figure {
public:
    Figure(frowvec startxy, bool fill, bool absCoords, double *rgb, long id);
    virtual frowvec getPoint(float param1);
    virtual frowvec getKeyPoint(int numberPoint);
    virtual float getLength();
    virtual frowvec getPointinDistance(float param1);

protected:

    frowvec _startxy;
    double* _rgb;
    double _fill;
    long _id;
    bool _absCoords;
    float _length;
    vector <frowvec> _points;

    virtual void _findLength();
};


#endif //PICTURETRANSLATOR_FIGURE_H
