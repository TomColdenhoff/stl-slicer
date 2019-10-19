//
// Created by Tom Coldenhoff on 18/10/2019.
//

#include "../Header/Coordinate.h++"

Coordinate::Coordinate(float x, float y, float z) : x(x), y(y), z(z) {}

float Coordinate::GetX() {
    return this->x;
}

float Coordinate::GetY() {
    return this->y;
}

float Coordinate::GetZ() {
    return this->z;
}
