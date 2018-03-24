//
// Created by texnoman on 17.03.18.
//

#ifndef NUMTRAECTORY_DATAOUT_H
#define NUMTRAECTORY_DATAOUT_H

#include <string.h>
#include <array>
#include <armadillo>

using namespace std;
using namespace arma;

class DataOut {
    public:
        DataOut(string filename);
    private:
        string _filename;
        vector <mat> _input;
        int _numberLine;
};


#endif //NUMTRAECTORY_DATAOUT_H
