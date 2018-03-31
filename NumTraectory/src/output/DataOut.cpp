//
// Created by texnoman on 17.03.18.
//

#include "DataOut.h"

DataOut::DataOut(string filenameOut) {

    _filenameOut = filenameOut;
    _fileOut.open(_filenameOut);
    if(!_fileOut){
        cout<<"Creating File!......";
    }
}

void DataOut::putToFile(vector <colvec> lastCoords) {
    cout<<"=================================================================================\n";
    cout<<" Traectory Generated                                                            |\n";
    cout<<"=================================================================================\n";

    _fileOut<<"=================================================================================\n";
    _fileOut<<" Traectory Generated                                                            |\n";
    _fileOut<<"=================================================================================\n";
    for(int i=0;i<lastCoords.size(); i++) {
        _fileOut << trans(lastCoords[i]);
        cout<<trans(lastCoords[i]);
    }
    _fileOut.flush();
    _fileOut.close();
}