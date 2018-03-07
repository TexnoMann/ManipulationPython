//
// Created by texnoman on 27.02.18.
//

#include <string.h>
#include <array>

#ifndef MANNUM_DATA_H
#define MANNUM_DATA_H

using namespace std;

class Data {
public:
    Data(string filename);
    void getData(string filename);

private:
    string _filename;
    ifstream _file;
    void _convertDataToMatrix();
    vector <float> _splitLine(string line, string splitter);
};


#endif //MANNUM_DATA_H
