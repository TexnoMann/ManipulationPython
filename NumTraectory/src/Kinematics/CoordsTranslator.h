//
// Created by texnoman on 16.03.18.
//

#ifndef NUMTRAECTORY_COORDSTRANSLATOR_H
#define NUMTRAECTORY_COORDSTRANSLATOR_H


#include <armadillo>
#include "ManipulatorConfiguration.h"

using namespace std;
using namespace arma;

class CoordsTranslator {
    public:
        CoordsTranslator(ManipulatorConfiguration configuration);
        mat getAbsCoords(mat relativeCoords);
        mat getRelativeCoords(mat absoluteCoords);
    private:
        float* _a;
        float* _d;
        int _numberJoint;
        float _getX(mat relativeCoords);
        float _getY(mat relativeCoords);
        float _getZ(mat relativeCoords);


};


#endif //NUMTRAECTORY_COORDSTRANSLATOR_H
