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
    Data();
    void getData(char* filename);

private:
    string _filename;
    FILE _p;
    float** _data;
};


#endif //MANNUM_DATA_H
