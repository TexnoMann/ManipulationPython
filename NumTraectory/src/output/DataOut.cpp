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

void DataOut::putToFile(rowvec lastAngle, rowvec lastSpeed ) {
    rowvec temp(lastAngle.size()*2);
    for( int i=0; i<lastAngle.size();i++) {
        temp[i] = lastAngle[i];
        if (isnan(temp[i])) temp[i]=0;
    }
    for( int i=0; i<lastSpeed.size();i++){
        temp[i+lastAngle.size()]=lastSpeed[i];
        if (isnan(temp[i])) temp[i]=0;
    }
    _fileOut << temp;
}


void DataOut::writeClose() {
    _fileOut.flush();
    _fileOut.close();

}