//
// Created by texnoman on 28.07.18.
//


#include <regex>
#include "SVGReader.h"
#include "../figurs/Path.h"
#include "../util/Configuration.h"


SVGReader::SVGReader(string str):
_coordsTranslator({MANIPULATOR_POSITION_X,MANIPULATOR_POSITION_Y})
{
    _segmentcount=0;
    _filename=str;
    _file.open(str);
    if(!_file) std::perror("File is not open!");
    _readFile();
    _wordsParse();
    _file.close();
}


vector<Curve> SVGReader::getCurves() {
    return _curves;
}

//Read File and split lines
 void SVGReader::_readFile() {
     string line;
     string splitter="\" ";
     _fileWords.clear();
     while(getline(_file,line)){
         vector<string> s;
         s=_splitLine(line,splitter);
         _fileWords.insert(_fileWords.end(),s.begin(),s.end());
     }
 }

//Split line with diferent splitter template.
// Create "vector" with words.

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

//Check that word is keyword and return keyword type of enum list.

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
    if(word=="height=") return HEIGHT;
    if(word=="width=") return WIDTH;
    if(_isFloat(word)) return NUMBER;
    return NONE;
}


bool SVGReader::_isFloat(string word){
    vector <string> ws =_splitLine(word,",");
    std :: stringstream sstr (ws[0]);
    float f ;
    return ! (( sstr >> noskipws >> f ). rdstate () ^ ios_base :: eofbit );
}

//Base code part. Read svg file and base algorithm detect and write curves in vector.
void SVGReader::_wordsParse() {
    if (_getWordType(_fileWords[0]) != XML) std::perror("Svg file is not correct!");
    int figureType = NONE;
    vector<string> stringFigure;
    frowvec imageSize = {0,0};
    for (int i = 1; i < _fileWords.size(); i++) {
        //cout<<_fileWords[i]<<"    "<< _getWordType(_fileWords[i])<<endl;
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
        else if ((_getWordType(_fileWords[i])) == HEIGHT){
            imageSize(1)=stof(_fileWords[i+1]);
            i++;
            _coordsTranslator.initSizeField(imageSize,{WORKSPACE_SIZE_X, WORKSPACE_SIZE_Y});
        }
        else if ((_getWordType(_fileWords[i])) == WIDTH){
            imageSize(0)=stof(_fileWords[i+1]);
            i++;
            _coordsTranslator.initSizeField(imageSize,{WORKSPACE_SIZE_X, WORKSPACE_SIZE_Y});
        }
        else if(figureType!=NONE) stringFigure.push_back(_fileWords[i]);
    }
}

//Specific parser for path: Read keywords after word "path"
// and generate line or Cubic Bezie Spline with absoluteCoordinats.

void SVGReader::_pathParser(vector <string> path){
    _segmentcount=0;
    _segments.clear();
    cout<<"   ";
    float xStart=0;
    float yStart=0;
    bool fill=false;
    int pathStart=0;
    bool absoluteCoords=true;
    frowvec startxy={0,0};
    frowvec fpoint={0,0};
    frowvec spoint={0,0};
    frowvec endxy={0,0};

    for(int i=0;i<path.size();i++){
        if ((_getWordType(path[i]) == moveto) || (_getWordType(path[i])==MOVETO)){
            absoluteCoords= _getWordType(path[i]) == MOVETO;
            vector <string> m = _splitLine(path[i+1],",");
            startxy={stof(m[0]),stof(m[1])};
            i+=1;
            pathStart=1;
        }

        else if(_getWordType(path[i])==CUBICBEZIE || _getWordType(path[i])==cubicBezie){
            absoluteCoords= _getWordType(path[i]) == CUBICBEZIE;
            vector <string> fp = _splitLine(path[i+1],",");
            vector <string> sp = _splitLine(path[i+2],",");
            vector <string> ep = _splitLine(path[i+3],",");
            if(absoluteCoords){
                fpoint = {stof(fp[0]), stof(fp[1])};
                spoint = {stof(sp[0]), stof(sp[1])};
                endxy = {stof(ep[0]), stof(ep[1])};
            }
            else {
                fpoint = {stof(fp[0]) + startxy[0], stof(fp[1]) + startxy[1]};
                spoint = {stof(sp[0]) + startxy[0], stof(sp[1]) + startxy[1]};
                endxy = {stof(ep[0]) + startxy[0], stof(ep[1]) + startxy[1]};
            }
            frowvec startxyP=_coordsTranslator.getPointinWorkField(startxy);
            frowvec fpointP=_coordsTranslator.getPointinWorkField(fpoint);
            frowvec spointP=_coordsTranslator.getPointinWorkField(spoint);
            frowvec endxyP=_coordsTranslator.getPointinWorkField(endxy);
            i+=3;
            double rgbColor[]={0,0,0};
            cout<<startxyP[0]<<" "<<startxyP[1]<<" "<<fpointP[0]<<" "<< fpointP[1]<<" "<<spointP[0]<<" "<< spointP[1]<<" "<<endxyP[0]<<" "<< endxyP[1]<<endl;
            Path pathn(startxyP, false, absoluteCoords,rgbColor,_segmentcount,0);
            pathn.initCubicBezie(fpointP,spointP,endxyP);
            _segments.push_back(new Path(pathn));
            _segmentcount++;
            pathStart=2;
            startxy=endxy;
        }

        else if(_getWordType(path[i])==NUMBER){
            if(pathStart==1){
                //add Line
            }
            else if(pathStart==2){
                vector <string> fp = _splitLine(path[i],",");
                vector <string> sp = _splitLine(path[i+1],",");
                vector <string> ep = _splitLine(path[i+2],",");
                if(absoluteCoords){
                    fpoint = {stof(fp[0]), stof(fp[1])};
                    spoint = {stof(sp[0]), stof(sp[1])};
                    endxy = {stof(ep[0]), stof(ep[1])};
                }
                else {
                    fpoint = {stof(fp[0]) + startxy[0], stof(fp[1]) + startxy[1]};
                    spoint = {stof(sp[0]) + startxy[0], stof(sp[1]) + startxy[1]};
                    endxy = {stof(ep[0]) + startxy[0], stof(ep[1]) + startxy[1]};
                }
                frowvec startxyP=_coordsTranslator.getPointinWorkField(startxy);
                frowvec fpointP=_coordsTranslator.getPointinWorkField(fpoint);
                frowvec spointP=_coordsTranslator.getPointinWorkField(spoint);
                frowvec endxyP=_coordsTranslator.getPointinWorkField(endxy);
                i+=2;
                double rgbColor[]={0,0,0};
                cout<<startxyP[0]<<" "<<startxyP[1]<<" "<<fpointP[0]<<" "<< fpointP[1]<<" "<<spointP[0]<<" "<< spointP[1]<<" "<<endxyP[0]<<" "<< endxyP[1]<<endl;
                Path pathn(startxyP, false, absoluteCoords,rgbColor,_segmentcount,0);
                pathn.initCubicBezie(fpointP,spointP,endxyP);
                _segments.push_back(new Path(pathn));
                _segmentcount++;
                pathStart=2;
                startxy=endxy;
            }
        }
        else continue;
    }
    Curve curve(_segments,Curve::PATH);
    _curves.push_back(curve);
}




