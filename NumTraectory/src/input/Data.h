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
    vector<fmat> getDesiredCoords();
    float getNormTime();
    float getControllerUpdateTime();
    int getCountCoords();
    int getCountParameters();
    int getCountPoints();

private:
    vector <fmat> _desiredCoords;
    string _filename;
    ifstream _file;
    long _n;
    long _countParameters;
    float _normTime;
    float _controllerUpdateTime;
    void _convertDataToMatrix();
    vector <float> _splitLine(string line, string splitter);
};


#endif //MANNUM_DATA_H
