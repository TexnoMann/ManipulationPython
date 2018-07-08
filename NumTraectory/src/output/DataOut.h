//
// Created by texnoman on 17.03.18.
//

#ifndef NUMTRAECTORY_DATAOUT_H
#define NUMTRAECTORY_DATAOUT_H

#include <string.h>
#include <array>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;

class DataOut {
    public:
        DataOut(string filenameOut);
        void putToFile(fmat lastCoord);
        void writeClose();
    private:
        string _filenameOut;
        vector <fmat> _inputCoords;
        int _numberLine;
        ofstream _fileOut;

};


#endif //NUMTRAECTORY_DATAOUT_H
