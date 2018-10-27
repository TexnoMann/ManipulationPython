#include <iostream>
#include "parser/SVGReader.h"
#include "figurs/Curve.h"
#include "util/Time_Parametrized.h"
#include <armadillo>
#include <memory>

int main() {
    SVGReader reader("/home/texnoman/Pictures/test.svg");
    vector<Curve> c=reader.getCurves();

    Time_Parametrized timeParametrized(0.05,0.05);
    vector<frowvec> trj= timeParametrized.curveTimeParametrized(c[1]);
    vector<Figure *> f=c[0].getSegments();
    Path* p = dynamic_cast<Path *>(f[0]);

}