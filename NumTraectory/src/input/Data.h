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
    vector<mat> getDesiredCoords();
    float getNormTime();
    int getN();

private:
    vector <mat> _desiredCoords;
    string _filename;
    ifstream _file;
    int _n;
    float _normTime;
    void _convertDataToMatrix();
    vector <float> _splitLine(string line, string splitter);
};


#endif //MANNUM_DATA_H
