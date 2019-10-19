//
// Created by Tom Coldenhoff on 18/10/2019.
//

#include "../Header/Point.h++"

Point::Point(float x, float y) : x(x), y(y) {}

float Point::GetX() {
    return this->x;
}

float Point::GetY() {
    return this->y;
}
