//
// Created by texnoman on 09.08.18.
//

#include "Time_Parametrized.h"
#include "Configuration.h"

Time_Parametrized::Time_Parametrized(float maxV, float maxA) {
    _maxA=maxA;
    _maxV=maxV;
    _timeTb=0;
    _finalTime=0;
}

vector <frowvec> Time_Parametrized::curveTimeParametrized(Curve curve) {
    vector <frowvec> trajectory;
    _finishLength=curve.getLengthCurve();
    _initTime(_finishLength);
    frowvec paramDistanceandVelocity={0,0};
    for(float time=0;time<=_finalTime;time+=MANIPULATOR_TIME_DESCRET){
        paramDistanceandVelocity=_getDistanceandVelocityinTime(time);
        float l=paramDistanceandVelocity[0];
        float v=paramDistanceandVelocity[1];
        frowvec point=curve.getPointinDistance(l);
        frowvec manipulatorPoint={point[0],point[1],time};
        cout<<manipulatorPoint<<endl;
        trajectory.push_back(manipulatorPoint);
    }
    return trajectory;
}

void Time_Parametrized::_initTime(float finishLength) {
    _finalTime=((powf(_maxV,2)/_maxA)+finishLength)/_maxV;
    _timeTb=(_maxV*_finalTime -finishLength)/_maxV;
}

frowvec Time_Parametrized::_getDistanceandVelocityinTime(float time) {
    frowvec paramDistanceandVelocity={0,0};
    if(time<0 || time>_finalTime) std::perror("Time is Negative or very big");
    else if(time<_timeTb){
        paramDistanceandVelocity[0]=_maxA*powf(time,2)/2;
        paramDistanceandVelocity[1]=_maxA*time;
    }
    else if(time<(_finalTime-_timeTb) && time>_timeTb){
        paramDistanceandVelocity[0]=(_finishLength-_maxV*_finalTime)/2+_maxV*time;
        paramDistanceandVelocity[1]=_maxV;
    }
    else if(time>(_finalTime-_timeTb)){
        paramDistanceandVelocity[0]=_finishLength - (_maxA*powf(_finalTime,2))/2 + _maxA*_finalTime*time- (_maxA*powf(time,2)/2);
        paramDistanceandVelocity[1]=_maxA*(_finalTime-time);
    }
    return paramDistanceandVelocity;
}


frowvec Time_Parametrized::_getVelocityVector(float linVelocity, frowvec firstPoint, frowvec secondPoint){

    frowvec dVec=secondPoint-firstPoint;
    float moddVec=sqrtf(powf(dVec[0],2)+ powf(dVec[1],2));
    frowvec eyeVector=dVec/moddVec;

    return eyeVector*linVelocity;
}