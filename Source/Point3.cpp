//
// Created by Tom Coldenhoff on 18/10/2019.
//

#include "../Header/Point3.h++"

Point3::Point3(float x, float y, float z) : x{x}, y{y}, z{z} {}

float Point3::GetX() {
    return this->x;
}

float Point3::GetY() {
    return this->y;
}

float Point3::GetZ() {
    return this->z;
}
