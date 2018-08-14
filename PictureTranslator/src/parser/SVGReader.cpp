//
// Created by texnoman on 28.07.18.
//


#include <regex>
#include "SVGReader.h"
#include "../figurs/Path.h"

SVGReader::SVGReader(string str) {
    _filename=str;
    _file.open(str);
    if(!_file) std::perror("File is not open!");
    _readFile();
    _wordsParse();
    _file.close();
}

vector<Figure> SVGReader::getSegments() {
    return _segments;
}

 void SVGReader::_readFile() {
     string line;
     string splitter=" \"";
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
    smatch s;
    std::regex id("id=");
    std::regex mm("\"m");
    std::regex Mm("\"M");
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
    if(regex_search(word.c_str(),id)) return IDFIGURE;
    if(word=="m") return moveto;
    if(word=="M") return MOVETO;
    if(word=="c") return cubicBezie;
    if(word=="C") return CUBICBEZIE;
    if(word=="l") return l;
    if(word=="L") return L;
    if(_isFloat(word)) return NUMBER;
    return NONE;
}

bool SVGReader::_isFloat(string word){
    std :: stringstream sstr (word);
    float f ;
    return ! (( sstr >> noskipws >> f ). rdstate () ^ ios_base :: eofbit );
}


void SVGReader::_wordsParse() {
    if (_getWordType(_fileWords[0]) != XML) std::perror("Svg file is not correct!");
    int figureType = NONE;
    vector<string> stringFigure;

    for (int i = 1; i < _fileWords.size(); i++) {
        if (_getWordType(_fileWords[i]) == ENDFIGURE) {
            switch (figureType) {
                case PATH:
                    _pathParser(stringFigure);
                    break;
            }
            figureType = NONE;
            stringFigure.clear();
        }
        else if (_getWordType(_fileWords[i]) < 5 && _getWordType(_fileWords[i]) != 0) figureType = _getWordType(_fileWords[i]);
        else if(figureType!=NONE) stringFigure.push_back(_fileWords[i]);
    }
}

void SVGReader::_pathParser(vector <string> path){
    float xStart=0;
    float yStart=0;
    bool fill=false;
    int rgb[3]={0,0,0};
    int pathStart=0;
    bool absoluteCoords=true;
    float startxy[]={0,0};
    float fpoint[]={0,0};
    float spoint[]={0,0};
    float endxy[]={0,0};

    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" "<< _getWordType(path[i])<< endl;
        if ((_getWordType(path[i]) == moveto) || (_getWordType(path[i])==MOVETO)){
            if(_getWordType(path[i]) == MOVETO) absoluteCoords=true;
            else absoluteCoords=false;
            vector <string> m = _splitLine(path[i+1],",");
            cout << path[i+1]<<endl;
            startxy[0]=stof(m[0]);
            startxy[1]=stof(m[1]);
            i+=1;
            pathStart=1;
        }

        else if(_getWordType(path[i])==CUBICBEZIE || _getWordType(path[i])==cubicBezie){
            if(_getWordType(path[i]) == CUBICBEZIE) absoluteCoords=true;
            else absoluteCoords=false;
            vector <string> fp = _splitLine(path[i+1],",");
            vector <string> sp = _splitLine(path[i+2],",");
            vector <string> ep = _splitLine(path[i+3],",");
            cout << path[i+1]<<"\n"<<path[i+2]<<"\n"<<path[i+3]<<endl;
            fpoint[0]=stof(fp[0]);
            fpoint[1]=stof(fp[1]);
            spoint[0]=stof(sp[0]);
            spoint[1]=stof(sp[1]);
            endxy[0]=stof(ep[0]);
            endxy[1]=stof(ep[1]);
            i+=3;
            double rgbColor[]={0,0,0};
            Path pathn(startxy[0],startxy[1], false, absoluteCoords,rgbColor,_segments.size(),0);
            _segments.push_back(pathn);
            pathStart=2;
            startxy[0]=endxy[0];
            startxy[1]=endxy[1];
        }
        else if(_getWordType(path[i])==NUMBER){
            if(pathStart==1){
                //add Line
            }
            else if(pathStart==2){
                cout <<"W"<<path[i+2]<<endl;
                vector <string> fp = _splitLine(path[i],",");
                vector <string> sp = _splitLine(path[i+1],",");
                vector <string> ep = _splitLine(path[i+2],",");
                fpoint[0]=stof(fp[0]);
                fpoint[1]=stof(fp[1]);
                spoint[0]=stof(sp[0]);
                spoint[1]=stof(sp[1]);
                endxy[0]=stof(ep[0]);
                endxy[1]=stof(ep[1]);
                i+=2;
                double rgbColor[]={0,0,0};
                Path pathn(startxy[0],startxy[1], false, absoluteCoords,rgbColor,_segments.size(),0);
                _segments.push_back(pathn);
                pathStart=2;
                startxy[0]=endxy[0];
                startxy[1]=endxy[1];
            }
        }
    }

}




