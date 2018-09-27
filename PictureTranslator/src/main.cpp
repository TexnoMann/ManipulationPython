#include <iostream>
#include "parser/SVGReader.h"
#include "figurs/Curve.h"
#include <armadillo>
#include <memory>

int main() {
    SVGReader reader("/home/texnoman/Pictures/drawing.svg");
    vector<Curve> c=reader.getCurves();
    vector<Figure *> f=c[0].getSegments();
    Path* p = dynamic_cast<Path *>(f[0]);

}