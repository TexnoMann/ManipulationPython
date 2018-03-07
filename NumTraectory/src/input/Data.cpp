//
// Created by texnoman on 27.02.18.
//

#include <iostream>
#include "Data.h"

Data::Data(string filename){
    _filename=  filename;
    _file.open(filename);
    if(!_file) {
        std::perror("File opening failed");
    }
    else{
        _convertToData(_file);
    }


}

void Data::_convertToData(FILE* file) {
    std::cout<<"Reading file...... " << "\n";
    vector <float> num;
    while(getline(file,line)){
        num= splitLine(line, " ");
    }
}


vector <float> splitLine(string line, string splitter){
    vector <float> number;
    char* cline = new char[line.length()+1];
    strcpy(cline,line.c_str());
    char* token = strtok(cline, splitter.c_str());
    while(token != NULL){
        cout<<"sdd";
        number.push_back(atof(token));
        token=strtok(NULL,splitter.c_str());
    }
    free(cline);
    free(token);
    return number;
}


