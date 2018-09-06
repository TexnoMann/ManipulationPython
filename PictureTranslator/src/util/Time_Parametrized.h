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

private:
    float getTimeinDistance;
    float _maxV;
    float _maxA;

};


#endif //PICTURETRANSLATOR_TIME_PARAMETRIZED_H
