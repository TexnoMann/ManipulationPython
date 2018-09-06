//
// Created by texnoman on 09.08.18.
//

#include "Time_Parametrized.h"
#include "Configuration.h"

Time_Parametrized::Time_Parametrized(float maxV, float maxA) {
    _maxA=maxA;
    _maxV=maxV;
}

vector <frowvec> Time_Parametrized::curveTimeParametrized(Curve curve) {
    vector <frowvec> trajectory;
    float figL =curve.getLengthCurve();
    for(float l=0;l<figL;l+=DISTANCE_PRECISION){
        frowvec point=figure.getPointinTime(time);
        trajectory.push_back(point);
    }
    return trajectory;
}