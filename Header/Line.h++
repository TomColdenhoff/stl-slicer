//
// Created by Tom Coldenhoff on 19/10/2019.
//

#ifndef STL_SLICER_LINE_H
#define STL_SLICER_LINE_H

#include "Coordinate.h++"

struct Line {
public:
    Line(Coordinate start, Coordinate end);

    Coordinate GetStartPoint();
    Coordinate GetEndPoint();

private:
    Coordinate start;
    Coordinate end;
};


#endif //STL_SLICER_LINE_H
