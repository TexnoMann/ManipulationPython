#include <iostream>
#include <armadillo>
#include "input/Data.h"
#include "output/DataOut.h"

#include "kinematics/ManipulatorConfiguration.h"
#include "kinematics/KinematicSolver.h"


using namespace std;


int main() {
    float a[] ={0.055, 0.15, 0.20};
    float d[] ={0.17, 0.0, 0.0};
    Data data("/media/files/Man/NumTraectory/test");
    DataOut out("test.out");
    ManipulatorConfiguration config(a,d);
    KinematicSolver solver(config);
    mat vv=solver.getfullCoordsfromPlaning(data.getDesiredCoords()[0],data.getDesiredCoords()[1]);
    cout<<vv;

    return 0;
}
