//
// Created by texnoman on 28.07.18.
//

#include "MovingHandler.h"

MovingHandler::MovingHandler() {
    this->_startTime=0;
    this->_finishTime=0;
    this->_deltaTime=0;
    this->_finishCoords={0,0};
    this->_startCoords={0,0};
    this->_linAcceleration=0;
    this->_linVelocity=0;
    this->_tb=0;
}

fmat MovingHandler::getCoordinats() {

}

void MovingHandler::_setSegmentsFunction(float startTime, float finishTime, fcolvec startCoords, fcolvec finishCoords, float linVelocity){
    _startTime=startTime;
    _finishTime=finishTime;
    _startCoords=startCoords;
    _finishCoords=finishCoords;
    _linVelocity=linVelocity;
    _deltaTime=_finishTime - _startTime;

}
