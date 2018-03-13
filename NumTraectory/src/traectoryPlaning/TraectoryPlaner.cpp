//
// Created by texnoman on 07.03.18.
//

#include "TraectoryPlaner.h"
#include "../Kinematics/Jacobian.h"

TraectoryPlaner::TraectoryPlaner(string filename, ManipulatorConfiguration configuration){
    _filename=filename;
    Data _data(_filename);
    Jacobian jacobian();
}

mat TraectoryPlaner::_translateAbsToRelativeCoords(mat absCoord) {
    
}
