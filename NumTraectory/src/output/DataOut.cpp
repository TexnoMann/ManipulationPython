//
// Created by texnoman on 17.03.18.
//

#include "DataOut.h"

DataOut::DataOut(string filenameOut) {

    _filenameOut = filenameOut;
    _fileOutAngle.open(_filenameOut+".angle.out");
    _fileOutSpeed.open(_filenameOut+".speed.out");

    if(!_fileOutAngle){
        cout<<"Creating File from Angle!......";
    }

    if(!_fileOutSpeed){
        cout<<"Creating File from Speed!......";
    }
}

void DataOut::putToFileAngle(rowvec lastCoords) {
    _fileOutAngle << lastCoords;
}

void DataOut::putToFileSpeed(rowvec lastSpeed) {
    _fileOutSpeed << lastSpeed;
}
void DataOut::writeClose() {
    _fileOutAngle.flush();
    _fileOutSpeed.flush();
    _fileOutAngle.close();
    _fileOutSpeed.close();
}