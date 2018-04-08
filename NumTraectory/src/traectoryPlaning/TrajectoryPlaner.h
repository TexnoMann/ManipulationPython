//
// Created by texnoman on 31.03.18.
//

#ifndef NUMTRAECTORY_TRAEJECTORYPLANER_H
#define NUMTRAECTORY_TRAEJECTORYPLANER_H


#include "../output/DataOut.h"
#include "../solver/Spline.h"
#include "../solver/Solver.h"
#include "../kinematics/ManipulatorConfiguration.h"
#include "../kinematics/KinematicSolverRRR.h"

class TrajectoryPlaner {

public:
    TrajectoryPlaner(ManipulatorConfiguration config, string datainput, string dataout);
    void getFullCordinatsJoints();

private:
    ManipulatorConfiguration _config;
    DataOut _dataout;
    Data _datainput;
    KinematicSolver _kinematicSolver;
    Spline _spline;
    Solver _solver;
    void getCoordinatsOneSegment(int startNumberPointPosition, int finishNumberPointPosition);
    mat getStartAndFinishPositionJoint(int startNumberPointPosition, int finishNumberPointPosition);




};


#endif //NUMTRAECTORY_TRAEJECTORYPLANER_H
