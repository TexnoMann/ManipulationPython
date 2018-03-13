//
// Created by texnoman on 13.03.18.
//

#include "ManipulatorConfiguration.h"

ManipulatorConfiguration::ManipulatorConfiguration(float a[], float d[]) {
    numberJoint= sizeof(a)/ sizeof(*a);
    aM=a;
    dM=d;
}

float* ManipulatorConfiguration::getaM() {
    return aM;
}

float* ManipulatorConfiguration::getdM() {
    return dM;
}

void ManipulatorConfiguration::setaM(float* a) {
    aM=a;
}

void ManipulatorConfiguration::setdM(float* d) {
    dM=d;
}
