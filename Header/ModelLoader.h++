//
// Created by Tom Coldenhoff on 18/10/2019.
//

#ifndef STL_SLICER_MODELLOADER_H
#define STL_SLICER_MODELLOADER_H

class Model;

class ModelLoader {
public:
    Model* Load(const char* filepath);
};


#endif //STL_SLICER_MODELLOADER_H
