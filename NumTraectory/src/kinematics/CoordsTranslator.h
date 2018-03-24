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
        colvec getAbsCoords(colvec relativeCoords);
        colvec getRelativeCoords(colvec absoluteCoords);
    private:
        ManipulatorConfiguration _configuration;
        float _getX(colvec relativeCoords);
        float _getY(colvec relativeCoords);
        float _getZ(colvec relativeCoords);


};


#endif //NUMTRAECTORY_COORDSTRANSLATOR_H
