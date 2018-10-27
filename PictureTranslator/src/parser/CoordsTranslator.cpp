//
// Created by texnoman on 25.09.18.
//

#include "CoordsTranslator.h"

CoordsTranslator::CoordsTranslator(frowvec manipulatorPosition) {
    _manipulatorPosition=manipulatorPosition;
}

void CoordsTranslator::initSizeField(frowvec XYmaxGraph, frowvec XYmaxWork) {
    _XYmaxGraphField=XYmaxGraph;
    _XYmaxWorkField=XYmaxWork;
    _K=_XYmaxWorkField/_XYmaxGraphField;
}

frowvec CoordsTranslator::getPointinWorkField(frowvec point) {
    frowvec workPoint=point%_K+_manipulatorPosition;
    return workPoint;
}
