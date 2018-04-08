#include <iostream>
#include <armadillo>
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
//    TrajectoryPlaner planer(config,"/media/files/Man/NumTraectory/test", "/media/files/Man/NumTraectory/test");
//    planer.getFullCordinatsJoints();
//    cout<<"===================================================================================================";
//    cout<<"=                                        Trajectory Generated                                     =";
//    cout<<"===================================================================================================";

    CoordsTranslatorRRR coordsTranslatorRRR(config);
    float x=0.2;
    float y=0.3;
    float z=0.1;
    colvec abscoord={x,y,z};
    colvec relcoords=coordsTranslatorRRR.getRelativeCoords(abscoord);
    cout<<relcoords<<endl;
    cout<<coordsTranslatorRRR.getAbsCoords(relcoords);



    return 0;
}
