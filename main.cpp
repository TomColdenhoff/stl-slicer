#include <iostream>
#include "Header/Model.h++"
#include "Header/ModelLoader.h++"
#include "Header/Slicer.h++"
#include <chrono>

int main(int argc, const char* argv[]) {

    if (argc != 4)
    {
        std::cout << "Incorrect usage of program uaage: \n stl-slicer <file.stl> <slice-amount f.e 1063> <resolution f.e 200>";
        return 1;
    }

    std::cout << "Starting model loading..." << std::endl;
    auto begin = std::chrono::high_resolution_clock::now();

    ModelLoader modelLoader;
    Model* model = modelLoader.Load(argv[1]);

    auto end = std::chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    if (model == nullptr)
    {
        return 2;
    }

    std::cout << "Done model loading... Time needed in ms: " << ms << std::endl;

    std::cout << "Starting slicing and exporting..." << std::endl;
    begin = std::chrono::high_resolution_clock::now();

    Slicer::SliceAndExport(model, argv[1], atoi(argv[2]), atoi(argv[3]));

    end = std::chrono::high_resolution_clock::now();
    dur = end - begin;
    ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << "Done slicing and exporting... Time needed in ms: " << ms << std::endl;

    delete(model);

    return 0;
}