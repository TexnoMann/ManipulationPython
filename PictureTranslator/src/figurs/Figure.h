//
// Created by texnoman on 28.07.18.
//

#ifndef PICTURETRANSLATOR_FIGURE_H
#define PICTURETRANSLATOR_FIGURE_H

#include <array>
#include <vector>

using namespace std;

class Figure {
public:
    Figure(float x0, float y0, bool fill, double rgb[]);
    vector<fcolvec> getPonts();
private:
    float _x0;
    float _y0;
    double* _rgb;
    double _fill;
};


#endif //PICTURETRANSLATOR_FIGURE_H
