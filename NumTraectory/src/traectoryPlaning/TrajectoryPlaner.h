//
// Created by texnoman on 31.03.18.
//

#ifndef NUMTRAECTORY_TRAEJECTORYPLANER_H
#define NUMTRAECTORY_TRAEJECTORYPLANER_H


#include "../output/DataOut.h"
#include "../solver/Spline.h"
#include "../solver/Solver.h"
#include "../kinematics/ManipulatorConfiguration.h"

class TrajectoryPlaner {

public:
    TrajectoryPlaner(ManipulatorConfiguration config);
    vector <colvec> getFullCordinats();

private:
    ManipulatorConfiguration _config;
    Spline _spline;
    Solver _solver;
    colvec getCoordinatsfromJoint(float time);

};


#endif //NUMTRAECTORY_TRAEJECTORYPLANER_H
