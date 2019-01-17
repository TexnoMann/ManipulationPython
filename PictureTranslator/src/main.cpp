#include <iostream>
#include "parser/SVGReader.h"
#include "figurs/Curve.h"
#include "util/Time_Parametrized.h"
#include "kinematics/ManipulatorKinematic.h"
#include <armadillo>
#include <memory>

int main() {
    SVGReader reader("/home/texnoman/Pictures/test.svg");
    vector<Curve> c = reader.getCurves();

    Time_Parametrized timeParametrized(0.05, 0.05);
    fmat dh = {{0.055, 0.17, 0, 0},
               {0.15,  0.0,  0, 0},
               {0.21,  0.0,  0, 0}};
    ManipulatorKinematic manipulatorKinematic(dh);

    vector<frowvec> trjRelSpace;

    for (int j = 0; j < c.size(); j++) {
        vector<frowvec> trj = timeParametrized.curveTimeParametrized(c[j]);
        for (int i = 0; i < trj.size(); i++) {
            frowvec absCoords = (frowvec) trj[i].cols(0, 2);
            frowvec absSpeeds = (frowvec) trj[i].cols(3, 5);
            fcolvec relCoords = manipulatorKinematic.getRelCoordinats(trans(absCoords));
            fcolvec relSpeed = manipulatorKinematic.getRelSpeed(trans(absSpeeds), relCoords);
            frowvec point = {relCoords[0], relCoords[1], relCoords[2], relSpeed[0], relSpeed[1], relSpeed[2]};
            trjRelSpace.push_back(point);
            cout << point << endl;
        }

    }
}
