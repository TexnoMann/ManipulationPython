//
// Created by texnoman on 25.09.18.
//

#ifndef PICTURETRANSLATOR_COORDSTRANSLATOR_H
#define PICTURETRANSLATOR_COORDSTRANSLATOR_H

#include <armadillo>

using namespace arma;

class CoordsTranslator {
public:
    CoordsTranslator(frowvec manipulatorPosition);
    void initSizeField(frowvec XYmaxGraph, frowvec XYmaxWork);
    frowvec getPointinWorkField(frowvec point);
private:
    frowvec _XYmaxGraphField;
    frowvec _XYmaxWorkField;
    frowvec _K;
    frowvec _manipulatorPosition;

};


#endif //PICTURETRANSLATOR_COORDSTRANSLATOR_H
