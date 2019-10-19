//
// Created by Tom Coldenhoff on 18/10/2019.
//

#include "../Header/Model.h++"
#include "../Header/Triangle.h++"

Model::Model(std::list<Triangle *> triangles, Point3 boundingBoxStart, Point3 boundingBoxEnd) {
    this->triangles = triangles;
    this->boundingBoxStart = boundingBoxStart;
    this->boundingBoxEnd = boundingBoxEnd;

    SortTriangles();
}

std::list<Triangle *> Model::GetTriangles() {

    return triangles;
}

void Model::SortTriangles() {
    this->triangles.sort([] (Triangle * lTri, Triangle * rTri) { return lTri->GetLowestZ() < rTri->GetLowestZ(); });
}

Point3 Model::GetBoundingBoxStart() {
    return this->boundingBoxStart;
}

Point3 Model::GetBoundingBoxEnd() {
    return this->boundingBoxEnd;
}
