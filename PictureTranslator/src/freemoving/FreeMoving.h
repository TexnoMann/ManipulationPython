//
// Created by texnoman on 07.11.18.
//

#ifndef PICTURETRANSLATOR_FREEMOVING_H
#define PICTURETRANSLATOR_FREEMOVING_H

#include <armadillo>

using namespace arma;
using namespace std;

class FreeMoving {

public:
    FreeMoving(float maxA, float maxV);
    vector<frowvec> getTrajectoryBetweenPoints(frowvec point1, frowvec point2);
private:
    float _maxA;
    float _maxV;

    float _upDistance;
    vector<frowvec> _getMoveUpTrajectory(frowvec point);
    vector<frowvec> _getMoveDownTrajectory(frowvec point);
    vector<frowvec> _getMoveTrajectoryinLine(frowvec point);
    void _initTime(frowvec fpoint,frowvec spoint);
    frowvec _getPointinTime(float time);

};


#endif //PICTURETRANSLATOR_FREEMOVING_H
