//
// Created by Tom Coldenhoff on 18/10/2019.
//

#ifndef STL_SLICER_TRIANGLE_H
#define STL_SLICER_TRIANGLE_H

#include <vector>
#include <climits>

class Coordinate;

class Triangle {
public:
    Triangle(std::vector<Coordinate*> coordinates);

    Coordinate* GetCoordinate(int index);
    float GetLowestY();
    float GetHighestY();
    float GetLowestZ();
    float GetHighestZ();

private:
    std::vector<Coordinate*> coordinates;

    float lowestY = INT_MAX, highestY = INT_MIN;
    float lowestX = INT_MAX, highestX = INT_MIN;
    float lowestZ = INT_MAX, highestZ = INT_MIN;
};


#endif //STL_SLICER_TRIANGLE_H
