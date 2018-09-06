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
    Figure(float x0, float y0, bool fill, bool absCoords, double *rgb, long id);
    virtual frowvec getPoint(float param1);
    virtual frowvec getKeyPoint(int numberPoint);
    virtual float getLength();
    virtual vector <frowvec> getPointsinDistance();

protected:

    float _x0;
    float _y0;
    double* _rgb;
    double _fill;
    long _id;
    bool _absCoords;
    float _length;
    vector <frowvec> _points;

    virtual void _findLength();
};


#endif //PICTURETRANSLATOR_FIGURE_H
