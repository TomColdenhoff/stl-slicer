//
// Created by Tom Coldenhoff on 18/10/2019.
//

#include <utility>

#include "../Header/Triangle.h++"
#include "../Header/Coordinate.h++"

Triangle::Triangle(std::vector<Coordinate *> coordinates) {
    this->coordinates = std::move(coordinates);

    for (int i = 0; i < 3; ++i) {

        float x = this->coordinates[i]->GetX(), y = this->coordinates[i]->GetY(), z = this->coordinates[i]->GetZ();

        lowestX = x < lowestX ? x : lowestX;
        highestX = x > highestX ? x : highestX;
        lowestY = y < lowestY ? y : lowestY;
        highestY = y > highestY ? y : highestY;
        lowestZ = z < lowestZ ? z : lowestZ;
        highestZ = z > highestZ ? z : highestZ;

    }
}

Coordinate *Triangle::GetCoordinate(int index) {
    return coordinates[index];
}

float Triangle::GetLowestY() {
    return this->lowestY;
}

float Triangle::GetHighestY() {
    return this->highestY;
}

float Triangle::GetLowestZ() {
    return this->lowestZ;
}

float Triangle::GetHighestZ() {
    return this->highestZ;
}


