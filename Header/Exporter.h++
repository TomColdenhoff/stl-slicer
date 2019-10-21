//
// Created by Tom Coldenhoff on 19/10/2019.
//

#ifndef STL_SLICER_EXPORTER_H
#define STL_SLICER_EXPORTER_H


#include <vector>

class Point;
class Model;

class Exporter {

public:
    void Export(Model* model, std::vector<Point> points, std::basic_string<char, std::char_traits<char>, std::allocator<char>> filename, int resolution);
};


#endif //STL_SLICER_EXPORTER_H
