//
// Created by Tom Coldenhoff on 18/10/2019.
//

#ifndef STL_SLICER_POINT3_H
#define STL_SLICER_POINT3_H


struct Point3 {
public:
    Point3(float x, float y, float z);

    float GetX();
    float GetY();
    float GetZ();

private:
    float x, y, z;
};


#endif //STL_SLICER_POINT3_H
