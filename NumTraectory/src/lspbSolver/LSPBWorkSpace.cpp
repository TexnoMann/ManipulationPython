//
// Created by texnoman on 09.07.18.
//

#include "LSPBWorkSpace.h"

LSPBWorkSpace::LSPBWorkSpace(int countJoint) {
    _countJoint=countJoint;
    _acceleration = {0,0,0};
    _finalTime = 0;
    _initTime = 0;
    _timeBlend = {0,0,0};
    _velocity = {0,0,0};
    _startCoords={0,0,0};
    _finishCoords={0,0,0};
}

fmat LSPBWorkSpace::getCoordinats(float currentTime) {
    float time = currentTime-_initTime;
    fcolvec coords0 = _startCoords + powf(time,2)/2.0*_acceleration;
    fcolvec coords1 = (_startCoords + _finishCoords - _finalTime*_velocity)/2.0 + _velocity*time;
    fcolvec coords2 = _finishCoords - _acceleration*powf(_finalTime,2)/2.0 + _acceleration*_finalTime*time-_acceleration*powf(time,2)/2.0;

    fcolvec speeds0 = time*_acceleration;
    fcolvec speeds1 = _velocity;
    fcolvec speeds2 = _acceleration*_finalTime - _acceleration*time;

    fcolvec coords={0,0,0};
    fcolvec speeds={0,0,0};
    for(int i=0;i<3;i++){
        if(time<_timeBlend(i)) {
            coords(i) = coords0(i);
            speeds(i) = speeds0(i);
        }

        if(time<(_finalTime-_timeBlend(i)) && time>_timeBlend(i)){
            coords(i) = coords1(i);
            speeds(i) = speeds1(i);
        }

        if(time>(_finalTime-_timeBlend(i))){
            coords(i) = coords2(i);
            speeds(i) = speeds2(i);
        }
    }
    fmat fullcoords = arma::join_rows(coords.t(),speeds.t());
    return fullcoords;

}

void LSPBWorkSpace::setSegmentsFunction(fcolvec startCoords, fcolvec finishCoords, float linSpeed, float firstTime, float secondTime) {
    _startCoords = startCoords;
    _finishCoords = finishCoords;
    _initTime = firstTime;
    fcolvec coordsVector=finishCoords-startCoords;
    float coordVectorLength=sqrtf(powf(coordsVector(0),2) + powf(coordsVector(1),2) + powf(coordsVector(2),2));

    float cosx = coordsVector(0)/coordVectorLength;
    float cosy = coordsVector(1)/coordVectorLength;
    float cosz = coordsVector(2)/coordVectorLength;

    _velocity = {cosx*linSpeed, cosy*linSpeed, cosz*linSpeed};
    cout<<_velocity;

    _finalTime = secondTime-firstTime;
    _timeBlend= (_startCoords - _finishCoords + _finalTime*_velocity)/_velocity;
    _acceleration = (_velocity/_timeBlend);
}
