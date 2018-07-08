//
// Created by texnoman on 17.03.18.
//

#include <iomanip>
#include "DataOut.h"

DataOut::DataOut(string filenameOut) {

    _filenameOut = filenameOut;
    _fileOut.open(_filenameOut);

    if(!_fileOut){
        cout<<"Creating File!...... "<<_filenameOut<<endl;
    }
}

void DataOut::putToFile(fmat lastCoord) {

    frowvec temp(lastCoord.n_rows*lastCoord.n_cols);
    temp.fill(0.0);

    for( int i=0; i<(lastCoord.n_rows*lastCoord.n_cols);i++) {
        temp(i) = lastCoord(i%lastCoord.n_rows,i/lastCoord.n_rows);
        if (isnan(temp[i])) temp[i]=0;
    }
    _fileOut<<std::fixed<<std::setprecision(8)<<temp;
}


void DataOut::writeClose() {
    _fileOut.flush();
    _fileOut.close();

}