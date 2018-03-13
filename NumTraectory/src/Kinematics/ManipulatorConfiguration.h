//
// Created by texnoman on 13.03.18.
//

#ifndef NUMTRAECTORY_MANIPULATORCONFIGURATION_H
#define NUMTRAECTORY_MANIPULATORCONFIGURATION_H


class ManipulatorConfiguration {
    public:
        ManipulatorConfiguration(float a[], float d[]);
        int numberJoint;
        float aM[];
        float dM[];
        float* getdM();
        float* getaM();
        void setdM(float* a);
        void setaM(float* d);
};



#endif //NUMTRAECTORY_MANIPULATORCONFIGURATION_H
