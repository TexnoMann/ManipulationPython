//
// Created by texnoman on 09.07.18.
//

#ifndef NUMTRAECTORY_LSPB_H
#define NUMTRAECTORY_LSPB_H

#include <armadillo>

using namespace arma;

class LSPBWorkSpace {

    public:
        LSPBWorkSpace(int countJoint);
        fmat getCoordinats(float currentTime);
        void setSegmentsFunction(fcolvec startCoords, fcolvec finishCoords, float linSpeed, float firstTime, float secondTime);

    private:
        int _countJoint;
        fcolvec _velocity;
        fcolvec _acceleration;
        float _finalTime;
        float _initTime;
        fcolvec _timeBlend;
        fcolvec _startCoords;
        fcolvec _finishCoords;
    };


#endif //NUMTRAECTORY_LSPB_H
