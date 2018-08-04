//
// Created by texnoman on 28.07.18.
//

#ifndef PICTURETRANSLATOR_SVGREADER_H
#define PICTURETRANSLATOR_SVGREADER_H

#include <string>
#include <vector>
#include <armadillo>
#include <jmorecfg.h>
#include "../figurs/Figure.h"

using namespace std;
using namespace arma;

class SVGReader {
public:
    SVGReader(string str);
    vector<Figure> getSegments();
private:
    enum _keyWordType{NONE=0, RECT=1, ELLIPSE=2, LINE=3, PATH=4, ENDFIGURE=5, XML=6, SVG=7,ENDSVG=8, LAY=9,ENDLAY=10};
    enum _keyWordSVG{VERSION=100, IDSVG=101, VIEWBOX=102, HEIGHT=103, WIDTH=104, OTHER=105};
    enum _keyWordLayer{STYLE=1001, IDLAYER=1002};
    enum _keyWordFigure{ID=10000, D=10001, STYLEFIGURE=10002};
    vector <string> _fileWords;
    string _filename;
    ifstream _file;
    vector<Figure> _segments;
    vector<string> _splitLine(string line, string splitter);
    void _readFile();
    void _wordsParse();
    boolean _getWordType(string word);
    Figure _pathParser(vector <string>);
};


#endif //PICTURETRANSLATOR_SVGREADER_H
