cmake_minimum_required(VERSION 3.9)
project(NumTraectory)

set(CMAKE_CXX_STANDARD 11)

add_executable(NumTraectory src/main.cpp src/solver/Solver.cpp src/solver/Solver.h src/solver/Spline.cpp src/solver/Spline.h src/input/Data.cpp src/input/Data.h src/Test.cpp src/traectoryPlaning/TraectoryPlaner.cpp src/traectoryPlaning/TraectoryPlaner.h src/Kinematics/Jacobian.cpp src/Kinematics/Jacobian.h src/Kinematics/ManipulatorConfiguration.cpp src/Kinematics/ManipulatorConfiguration.h src/Kinematics/CoordsTranslator.cpp src/Kinematics/CoordsTranslator.h)
