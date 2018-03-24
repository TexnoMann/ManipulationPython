cmake_minimum_required(VERSION 3.9)
project(NumTraectory)

set(CMAKE_CXX_STANDARD 11)

add_executable(NumTraectory src/main.cpp src/solver/Solver.cpp src/solver/Solver.h src/solver/Spline.cpp src/solver/Spline.h src/input/Data.cpp src/input/Data.h src/Test.cpp src/traectoryPlaning/TraectoryPlaner.cpp src/traectoryPlaning/TraectoryPlaner.h src/kinematics/Jacobian.cpp src/kinematics/Jacobian.h src/kinematics/ManipulatorConfiguration.cpp src/kinematics/ManipulatorConfiguration.h src/kinematics/CoordsTranslator.cpp src/kinematics/CoordsTranslator.h src/output/DataOut.cpp src/output/DataOut.h src/kinematics/KinematicSolver.cpp src/kinematics/KinematicSolver.h)
