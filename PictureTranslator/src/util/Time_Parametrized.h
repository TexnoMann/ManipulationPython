//
// Created by texnoman on 09.08.18.
//

#ifndef PICTURETRANSLATOR_TIME_PARAMETRIZED_H
#define PICTURETRANSLATOR_TIME_PARAMETRIZED_H

#include <armadillo>
#include "../figurs/Curve.h"

using namespace arma;
using namespace std;

class Time_Parametrized {
public:
    Time_Parametrized(float maxV, float maxA);
    vector <frowvec> curveTimeParametrized(Curve curve);
    vector <frowvec> freeMovingParametrized(frowvec point1, frowvec point2);


private:
    frowvec _getDistanceandVelocityinTime(float time);
    frowvec _getVelocityVector(float linVelocity, frowvec firstPoint,frowvec secondPoint);
    float _timeTb;
    float _finalTime;
    float _maxV;
    float _maxA;
    float _finishLength;
    void _initTime(float finishLength);


};


#endif //PICTURETRANSLATOR_TIME_PARAMETRIZED_H
