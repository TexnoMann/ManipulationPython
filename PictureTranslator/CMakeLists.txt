cmake_minimum_required(VERSION 3.9)
project(PictureTranslator)

set(CMAKE_CXX_STANDARD 11)

add_executable(PictureTranslator main.cpp src/figurs/Figure.cpp src/figurs/Figure.h src/figurs/Ellipses.cpp src/figurs/Ellipses.h src/util/MovingHandler.cpp src/util/MovingHandler.h src/parser/SVGParser.cpp src/parser/SVGParser.h src/input/SVGReader.cpp src/input/SVGReader.h)