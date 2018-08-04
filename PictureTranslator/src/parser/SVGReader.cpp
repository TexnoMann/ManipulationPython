//
// Created by texnoman on 28.07.18.
//

#include "SVGReader.h"
#include "../figurs/Path.h"

SVGReader::SVGReader(string str) {
    _filename=str;
    _file.open(str);
    if(!_file) std::perror("File is not open!");
    _readFile();
    _file.close();
}

vector<Figure> SVGReader::getSegments() {
    return _segments;
}

 void SVGReader::_readFile() {
     string line;
     string splitter=" ";
     _fileWords.clear();
     while(getline(_file,line)){
         vector<string> s;
         s=_splitLine(line,splitter);
         _fileWords.insert(_fileWords.end(),s.begin(),s.end());
     }
 }

vector <string> SVGReader::_splitLine(string line, string splitter){
    vector <string> sen;
    char* cline = new char[line.length()+1];
    strcpy(cline,line.c_str());
    char* token = strtok(cline, splitter.c_str());
    while(token != NULL){
        string s(token);
        sen.push_back(s);
        token=strtok(NULL,splitter.c_str());
    }
    free(cline);
    free(token);
    return sen;
}

int SVGReader::_getWordType(string word) {
    if(word=="<rect") return RECT;
    if(word=="<ellipse") return ELLIPSE;
    if(word=="<line") return LINE;
    if(word=="<path") return PATH;
    if(word=="/>") return ENDFIGURE;
    if(word=="<?xml") return XML;
    if(word=="<g") return LAY;
    if(word=="</g>") return ENDLAY;
    if(word=="<svg") return SVG;
    if(word=="</svg>") return ENDSVG;
    return NONE;
}

void SVGReader::_wordsParse(){
    if(_getWordType(_fileWords[0])!=SVG) std::perror("Svg file is not correct!");
    int figureType= NONE;
    vector <string> stringFigure;

    for( int i=1; i<_fileWords.size(); i++){
        if(figureType!= NONE) stringFigure.push_back(_fileWords[i]);

        if(_getWordType(_fileWords[i])<=5) figureType=_getWordType(_fileWords[i]);

        else if(_getWordType(_fileWords[i])==ENDFIGURE){
            switch(figureType){
                case PATH:
                    _pathParser(stringFigure);
                    break;
            }
            figureType=NONE;
    }
}

Figure SVGReader::_pathParser(vector <string> path){
    for(int i=0;i<path.size();i++){

    }
}




