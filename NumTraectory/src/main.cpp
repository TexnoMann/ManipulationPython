#include <armadillo>
#include <iostream>
#include "input/Data.h"
#include "output/DataOut.h"

#include "kinematics/ManipulatorConfiguration.h"
#include "kinematics/KinematicSolverRRR.h"
#include "traectoryPlaning/TrajectoryPlaner.h"


using namespace std;


int main() {
    float a[] ={0.055, 0.15, 0.20};
    float d[] ={0.17, 0.0, 0.0};
    ManipulatorConfiguration config(a,d);
    TrajectoryPlaner planer(config,"/media/files/Man/NumTraectory/test", "/media/files/Man/NumTraectory/test.out");
    planer.getFullCordinatsJoints();
//    cout<<"===================================================================================================";
//    cout<<"=                                        Trajectory Generated                                     =";
//    cout<<"===================================================================================================";

    return 0;
}
