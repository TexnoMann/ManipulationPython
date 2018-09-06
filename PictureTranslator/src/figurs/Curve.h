//
// Created by texnoman on 21.08.18.
//

#ifndef PICTURETRANSLATOR_CURVE_H
#define PICTURETRANSLATOR_CURVE_H


#include "Figure.h"

class Curve {
public:
    Curve(vector<Figure *> segments, int type);
    vector <Figure *> getSegments();
    frowvec getPointinDistance(float distance);
    float getLengthCurve();
    enum TYPE{PATH=0,LINE=1,RECT=2,ELLIPSE=3};
    const int type;
private:
    vector <Figure *> _segments;
    vector<float> _EndDistanceForSegments;
    long getSize();
    float _getDistanceForSegments(long numberSegments);

};


#endif //PICTURETRANSLATOR_CURVE_H
