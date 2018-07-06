//
// Created by texnoman on 27.02.18.
//

#include <string.h>
#include <array>
#include <vector>
#include <armadillo>


#ifndef MANNUM_DATA_H
#define MANNUM_DATA_H

using namespace std;
using namespace arma;

class Data {
public:
    Data(string filename);
    vector<colvec> getDesiredCoords();
    float getNormTime();
    float getControllerUpdateTime();
    int getCountCoords();
    int getCountPoints();

private:
    vector <colvec> _desiredCoords;
    string _filename;
    ifstream _file;
    long _n;
    float _normTime;
    float _controllerUpdateTime;
    void _convertDataToMatrix();
    vector <float> _splitLine(string line, string splitter);
};


#endif //MANNUM_DATA_H
