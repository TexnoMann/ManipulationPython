//
// Created by texnoman on 27.02.18.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Data.h"
#include <armadillo>

using namespace std;
using namespace arma;

Data::Data(string filename){
    _n=0;
    _normTime=0;    //TODO: get normTime and scalePolynome in file.
    _filename=  filename;
    _file.open(_filename);
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
        num = _splitLine(line,splitter);
        mat coords(num.size(),1);
        coords.fill(0.0);
        for(int i=0;i<num.size();i++){
            coords(i,1)=num[i];
        }
        _desiredCoords.push_back(coords);
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

int Data::getN(){
    return _n;
}

vector <mat> Data::getDesiredCoords(){

};

float Data::getNormTime() {
    return _normTime;
}

