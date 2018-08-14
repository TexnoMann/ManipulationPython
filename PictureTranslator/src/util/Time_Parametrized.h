//
// Created by texnoman on 09.08.18.
//

#ifndef PICTURETRANSLATOR_TIME_PARAMETRIZED_H
#define PICTURETRANSLATOR_TIME_PARAMETRIZED_H

#include <armadillo>

using namespace arma;
using namespace std;

class Time_Parametrized {
public:
    vector <fcolvec> figurTimeParametrized();

private:
    float maxV;
    float maxA;

};


#endif //PICTURETRANSLATOR_TIME_PARAMETRIZED_H
