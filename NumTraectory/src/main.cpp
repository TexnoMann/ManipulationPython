#include <armadillo>
#include <iostream>
#include "input/Data.h"
#include "output/DataOut.h"

#include "kinematics/ManipulatorConfiguration.h"
#include "kinematics/KinematicSolverRRR.h"
#include "traectoryPlaning/TrajectoryPlaner.h"
#include "lspbSolver/LSPBWorkSpace.h"


using namespace std;


int main() {
    float a[] ={0.055, 0.15, 0.20};
    float d[] ={0.17, 0.0, 0.0};
    ManipulatorConfiguration config(a,d, sizeof(a)/sizeof(*a));
    TrajectoryPlaner planer(config,"/media/files/ManipulatorProject/Man/NumTraectory/test", "/media/files/ManipulatorProject/Man/NumTraectory/test.out");
    planer.getFullCordinatsJoints();
//    cout<<"===================================================================================================";
//    cout<<"=                                        Trajectory Generated                                     =";
//    cout<<"===================================================================================================";
//    LSPBWorkSpace lspb =LSPBWorkSpace(3);
//    fcolvec startcoord={0.1,0.1,0};
//    fcolvec finishcoord={0.15,0.2,0};
//
//    DataOut dout=DataOut("/media/files/ManipulatorProject/Man/NumTraectory/test.out");
//    lspb.setSegmentsFunction(startcoord,finishcoord,0.02,0,9);
//    for (float time=0;time<9;time+=0.05){
//        dout.putToFile(lspb.getCoordinats(time));
//    }
//    dout.writeClose();

    return 0;
}
