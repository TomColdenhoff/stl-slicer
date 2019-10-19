//
// Created by Tom Coldenhoff on 18/10/2019.
//

#ifndef STL_SLICER_SLICER_H
#define STL_SLICER_SLICER_H

class Model;
class Point;

class Slicer {
public:
    static void SliceAndExport(Model *model, const char *fileName, int sliceAmount, int resolution);

private:
};


#endif //STL_SLICER_SLICER_H
