cmake_minimum_required(VERSION 3.9)
project(PictureTranslator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -larmadillo -fPIC")
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(PictureTranslator src/main.cpp src/figurs/Figure.h src/util/MovingHandler.cpp src/util/MovingHandler.h src/parser/SVGReader.cpp src/parser/SVGReader.h src/figurs/Path.cpp src/figurs/Path.h src/util/Time_Parametrized.cpp src/util/Time_Parametrized.h src/figurs/Figure.cpp src/figurs/Curve.cpp src/figurs/Curve.h src/util/Configuration.h src/parser/CoordsTranslator.cpp src/parser/CoordsTranslator.h)
target_link_libraries(PictureTranslator ${ARMADILLO_LIBRARIES})