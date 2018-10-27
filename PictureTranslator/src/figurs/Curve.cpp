//
// Created by texnoman on 21.08.18.
//

#include "Curve.h"

//Curve is base container for continuous Spline

Curve::Curve(vector<Figure *> segments, int type):
        type(type){
    _segments=segments;
    if(type<0 || type>3) std::perror("Invalid type Figure");
}

vector <Figure *> Curve::getSegments() {
    return _segments;
}

float Curve::getLengthCurve() {
    float length = 0;
    float EndDistanceForSegment=0;
    for(int i=0;i<getSize();i++){
        length += _segments[i]->getLength();
        EndDistanceForSegment=length;
        //cout<<EndDistanceForSegment<<endl;
        _EndDistanceForSegments.push_back(EndDistanceForSegment);
    }
    return length;
}

float Curve::_getDistanceForSegments(long numberSegments){
    if(numberSegments<0 || numberSegments>_EndDistanceForSegments.size()) std::perror("Curve:: NumberSegments in curve error. Invalid index");
    return _EndDistanceForSegments[numberSegments];
}

long Curve::getSize(){
    return _segments.size();
}

frowvec Curve::getPointinDistance(float distance) {
    int pointnumber=-1;
    for(int i=0;i<getSize();i++){
        if(distance<=_getDistanceForSegments(i)){
            pointnumber=i;
            break;
        }
        else if(i==0){
            pointnumber=0;
        }
    }
    if (pointnumber==-1) std::perror("Curve:: Error in find distance!");
    frowvec desiredPoint=_segments[pointnumber]->getPointinDistance(distance-_EndDistanceForSegments[pointnumber-1]);
   //cout<<desiredPoint<<endl;
    return desiredPoint;
}
