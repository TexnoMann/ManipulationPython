//
// Created by texnoman on 28.07.18.
//

#ifndef PICTURETRANSLATOR_MOVINGPARAM_H
#define PICTURETRANSLATOR_MOVINGPARAM_H

#include <armadillo>

using namespace arma;

class MovingHandler {
public:
    MovingHandler();
    fmat getCoordinats();

private:
    float _deltaTime;
    float _linVelocity;
    float _linAcceleration;
    float _tb;
    float _startTime;
    float _finishTime;
    fcolvec _startCoords;
    fcolvec _finishCoords;

    void _setSegmentsFunction(float startTime, float finishTime, fcolvec startCoords, fcolvec finishCoords, float linVelocity);
};


#endif //PICTURETRANSLATOR_MOVINGPARAM_H
