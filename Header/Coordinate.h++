//
// Created by Tom Coldenhoff on 18/10/2019.
//

#ifndef STL_SLICER_COORDINATE_H
#define STL_SLICER_COORDINATE_H


class Coordinate {

public:
    Coordinate(float x, float y, float z);

    float GetX();
    float GetY();
    float GetZ();

private:
    float x;
    float y;
    float z;
};


#endif //STL_SLICER_COORDINATE_H
