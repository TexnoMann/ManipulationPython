//
// Created by texnoman on 07.03.18.
//

#include "TraectoryPlaner.h"
#include "../Kinematics/CoordsTranslator.h"

TraectoryPlaner::TraectoryPlaner(string filename, ManipulatorConfiguration configuration)
        :_data(_filename),
         _spline(_data.getN(),
         _data.getNormTime()),
         _solver(_data.getN())
{
    _filename=filename;
    _data=Data(_filename);

}

mat TraectoryPlaner::_generateSplineSegment(mat initCoords) {
    _data.getNormTime();
}

