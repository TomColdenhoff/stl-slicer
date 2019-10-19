//
// Created by Tom Coldenhoff on 18/10/2019.
//

#include <vector>
#include <iostream>
#include "../Header/ModelLoader.h++"
#include "../Header/stl_reader.h"
#include "../Header/Model.h++"
#include "../Header/Coordinate.h++"
#include "../Header/Triangle.h++"

Model *ModelLoader::Load(const char *filepath) {
    std::vector<float> coords, normals;
    std::vector<unsigned int> tris, solids;

    std::list<Triangle*> triangles;

    float lowestX = INT_MAX, highestX = INT_MIN;
    float lowestY = INT_MAX, highestY = INT_MIN;
    float lowestZ = INT_MAX, highestZ = INT_MIN;



    try {
        stl_reader::ReadStlFile (filepath, coords, normals, tris, solids);
        const size_t numTris = tris.size() / 3;
        for(size_t itri = 0; itri < numTris; ++itri) {
            std::vector<Coordinate*> coordinates;
            for(size_t icorner = 0; icorner < 3; ++icorner) {
                float* c = &coords[3 * tris [3 * itri + icorner]];
                coordinates.push_back(new Coordinate(c[0], c[1], c[2]));

                lowestX = c[0] < lowestX ? c[0] : lowestX;
                highestX = c[0] > highestX ? c[0] : highestX;
                lowestY = c[1] < lowestY ? c[1] : lowestY;
                highestY = c[1] > highestY ? c[1] : highestY;
                lowestZ = c[2] < lowestZ ? c[2] : lowestZ;
                highestZ = c[2] > highestZ ? c[2] : highestZ;
            }
            triangles.push_back(new Triangle(coordinates));
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return new Model(triangles, Point3(lowestX, lowestY, lowestZ), Point3(highestX, highestY, highestZ));
}
