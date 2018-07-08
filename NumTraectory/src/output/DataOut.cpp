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

void DataOut::putToFile(fmat lastCoord) {

    frowvec temp(lastCoord.n_elem);
    for( int i=0; i<lastCoord.n_elem;i++) {
        temp(i) = lastCoord(i%lastCoord.n_rows,i/lastCoord.n_rows);
        if (isnan(temp[i])) temp[i]=0;
    }
    _fileOut << temp;
}


void DataOut::writeClose() {
    _fileOut.flush();
    _fileOut.close();

}