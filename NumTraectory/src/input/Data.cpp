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
    _normTime=0;
    _controllerUpdateTime=0;
    _filename = filename;
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
    std::cout<<"Reading file...... " << _filename<< "\n";
    vector <float> num;
    getline(_file,line);
    num= _splitLine(line,splitter);
    _normTime=num[0];
    _controllerUpdateTime=num[1];
    while(getline(_file,line)){
        num = _splitLine(line,splitter);
        colvec coords(num.size());
        _n= num.size();
        coords.fill(0.0);

        for(int i=0;i<_n;i++){
            coords(i,0)=num[i];
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

int Data::getCountCoords(){
    return _n;
}

vector <colvec> Data::getDesiredCoords(){ // (X, Y, Z, fullspeed, fullaceleration)
    return _desiredCoords;
};

int Data:: getCountPoints(){
    return _desiredCoords.size();
}

float Data::getNormTime() {
    return _normTime;
}

float Data::getControllerUpdateTime() {
    return _controllerUpdateTime;
}

