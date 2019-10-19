//
// Created by Tom Coldenhoff on 18/10/2019.
//

#ifndef STL_SLICER_MODEL_H
#define STL_SLICER_MODEL_H

#include <list>
#include "Point.h++"
#include "Point3.h++"

class Triangle;


class Model {

public:
    Model(std::list<Triangle *> triangles, Point3 boundingBoxStart, Point3 boundingBoxEnd);
    std::list<Triangle*> GetTriangles();

    Point3 GetBoundingBoxStart();
    Point3 GetBoundingBoxEnd();

private:
    std::list<Triangle*> triangles;

    Point3 boundingBoxStart = Point3(0, 0, 0), boundingBoxEnd = Point3(0, 0, 0);

    void SortTriangles();
};


#endif //STL_SLICER_MODEL_H
