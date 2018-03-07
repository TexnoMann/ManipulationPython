//
// Created by texnoman on 27.02.18.
//
#import <stdio.h>
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
    FILE*_file;
    float** _data;
    void _convertToData(FILE*);
};


#endif //MANNUM_DATA_H
