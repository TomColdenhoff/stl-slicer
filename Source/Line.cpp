//
// Created by Tom Coldenhoff on 19/10/2019.
//

#include "../Header/Line.h++"

Line::Line(Coordinate start, Coordinate end) : start(start), end(end) {}

Coordinate Line::GetStartPoint() {
    return this->start;
}

Coordinate Line::GetEndPoint() {
    return this->end;
}
