//
// Created by texnoman on 28.07.18.
//

#ifndef PICTURETRANSLATOR_SVGREADER_H
#define PICTURETRANSLATOR_SVGREADER_H

#include <string>
#include <vector>
#include <armadillo>
#include "../figurs/Figure.h"

using namespace std;
using namespace arma;

class SVGReader {
public:
    SVGReader(char *str);
    string filename;
    vector<Figure> getSegments();
private:
    ifstream _file;
    vector<Figure> _segment;
};


#endif //PICTURETRANSLATOR_SVGREADER_H
