//
// Created by texnoman on 16.03.18.
//

#ifndef NUMTRAECTORY_COORDSTRANSLATOR_H
#define NUMTRAECTORY_COORDSTRANSLATOR_H


#include <armadillo>
#include "ManipulatorConfiguration.h"

using namespace std;
using namespace arma;

class CoordsTranslatorRRR {
    public:
        CoordsTranslatorRRR(ManipulatorConfiguration configuration);
        fcolvec getAbsCoords(fcolvec relativeCoords);
        fcolvec getRelativeCoords(fcolvec absoluteCoords);
    private:
        ManipulatorConfiguration _configuration;
        float _getX(fcolvec relativeCoords);
        float _getY(fcolvec relativeCoords);
        float _getZ(fcolvec relativeCoords);


};


#endif //NUMTRAECTORY_COORDSTRANSLATOR_H
