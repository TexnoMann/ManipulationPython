//
// Created by texnoman on 13.03.18.
//

#ifndef NUMTRAECTORY_MANIPULATORCONFIGURATION_H
#define NUMTRAECTORY_MANIPULATORCONFIGURATION_H


class ManipulatorConfiguration {
    public:
        ManipulatorConfiguration(float a[], float d[]);
        float* getdM();
        float* getaM();
        int getNumberJoint();
        void setdM(float* a);
        void setaM(float* d);

    private:
        float* _aM;
        float* _dM;
        int _numberJoint;
};



#endif //NUMTRAECTORY_MANIPULATORCONFIGURATION_H
