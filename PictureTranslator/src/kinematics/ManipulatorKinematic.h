//
// Created by texnoman on 13.03.18.
//

#ifndef NUMTRAECTORY_MANIPULATORCONFIGURATION_H
#define NUMTRAECTORY_MANIPULATORCONFIGURATION_H

#include <armadillo>

using namespace arma;

class ManipulatorKinematic {
    public:
        ManipulatorKinematic(fmat param);
        frowvec getAbsCoordinats(frowvec relCoords);
        frowvec getAbsSpeed(frowvec relSpeeds);
        frowvec getAbsAcceleration(frowvec relAcceleration);

        fcolvec getRelCoordinats(fcolvec absCoords);
        fcolvec getRelSpeed(fcolvec absSpeeds, fcolvec relCoords);
        fcolvec getRelAcceleration(frowvec absAcceleration);
    private:
        frowvec _a;
        frowvec _d;
        frowvec _alpha;
        unsigned int _numberJoint;
        fmat _getJacobian(fcolvec angles);
};



#endif //NUMTRAECTORY_MANIPULATORCONFIGURATION_H
