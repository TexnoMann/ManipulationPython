//
// Created by texnoman on 13.03.18.
//

#include "ManipulatorConfiguration.h"
#include "../input/Data.h"

ManipulatorConfiguration::ManipulatorConfiguration(float* a, float* d) {

    _numberJoint= sizeof(a)/ sizeof(*a);
    _aM=a;
    _dM=d;
}

float* ManipulatorConfiguration::getaM() {
    return _aM;
}

float* ManipulatorConfiguration::getdM() {
    return _dM;
}

void ManipulatorConfiguration::setaM(float* a) {
    _aM=a;
}

void ManipulatorConfiguration::setdM(float* d) {
    _dM=d;
}

int ManipulatorConfiguration::getNumberJoint() {
    return _numberJoint;
}
