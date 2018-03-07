//
// Created by texnoman on 27.02.18.
//

#include <iostream>
#include "Data.h"

Data::Data(string filename){
    _filename=  filename;
    _file= fopen(filename.c_str(),"r");
    std::perror("File opening failed");
    if(!_file) {
        std::perror("File opening failed");
    }
    else{
        _convertToData(_file);
    }


}

void Data::_convertToData(FILE *) {
    while(c=)

}
