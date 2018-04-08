cmake_minimum_required(VERSION 3.9)
project(NumTraectory)

set(CMAKE_CXX_STANDARD 11)

add_executable(NumTraectory src/main.cpp src/solver/Solver.cpp src/solver/Solver.h src/solver/Spline.cpp src/solver/Spline.h src/input/Data.cpp src/input/Data.h src/Test.cpp src/kinematics/SpeedTranslatorRRR.cpp src/kinematics/SpeedTranslatorRRR.h src/kinematics/ManipulatorConfiguration.cpp src/kinematics/ManipulatorConfiguration.h src/kinematics/CoordsTranslatorRRR.cpp src/kinematics/CoordsTranslatorRRR.h src/output/DataOut.cpp src/output/DataOut.h src/kinematics/KinematicSolverRRR.cpp src/kinematics/KinematicSolverRRR.h src/traectoryPlaning/TrajectoryPlaner.cpp src/traectoryPlaning/TrajectoryPlaner.h src/kinematics/AccelerationTranslatorRRR.cpp src/kinematics/AccelerationTranslatorRRR.h)
