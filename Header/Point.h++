//
// Created by Tom Coldenhoff on 18/10/2019.
//

#ifndef STL_SLICER_POINT_H
#define STL_SLICER_POINT_H


struct Point {
public:
    Point(float x, float y);

    float GetX();
    float GetY();

private:
    float x, y;
};


#endif //STL_SLICER_POINT_H
