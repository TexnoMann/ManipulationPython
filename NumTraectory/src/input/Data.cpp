//
// Created by texnoman on 27.02.18.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Data.h"

Data::Data(string filename){
    _filename=  filename;
    _file.open(filename);
    if(!_file) {
        std::perror("File opening failed");
    }
    else{
        _convertDataToMatrix();
    }

}

void Data::_convertDataToMatrix(){
    std::string line;
    std::string splitter=" ";
    std::cout<<"Reading file...... " << "\n";
    vector <float> num;
    while(getline(_file,line)){
        num= _splitLine(line,splitter);
    }
}


vector <float> Data::_splitLine(string line, string splitter){
    vector <float> number;
    char* cline = new char[line.length()+1];
    strcpy(cline,line.c_str());
    char* token = strtok(cline, splitter.c_str());
    while(token != NULL){
        number.push_back(atof(token));
        token=strtok(NULL,splitter.c_str());
    }
    free(cline);
    free(token);
    return number;
}


