//
// Created by Tom Coldenhoff on 18/10/2019.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <thread>
#include "../Header/Slicer.h++"
#include "../Header/Point.h++"
#include "../Header/Model.h++"
#include "../Header/Triangle.h++"
#include "../Header/Coordinate.h++"
#include "../Header/Line.h++"
#include "../Header/Exporter.h++"

void Slicer::SliceAndExport(Model *model, const char *fileName, int sliceAmount, int resolution) {

    // Apparently the model has the Z facing up instead of the Y axis

    float lowestZ = model->GetBoundingBoxStart().GetZ();
    float highestZ = model->GetBoundingBoxEnd().GetZ();
    float height = highestZ - lowestZ;


    std::list<Triangle*> triangles = model->GetTriangles();

    for (int i = 0; i < sliceAmount; ++i)
    {
        std::vector<Point> points;

        float clippingLineZ = (height / (float)sliceAmount) * (float)(i);

        for (auto it = triangles.begin(); it != triangles.end();) {

            if ((*it)->GetHighestZ() < clippingLineZ){
                it = triangles.erase(it);
                continue;
            }
            else if ((*it)->GetLowestZ() > clippingLineZ){
                break;
            }

            Coordinate* coordinates[] = {(*it)->GetCoordinate(0), (*it)->GetCoordinate(1), (*it)->GetCoordinate(2)};

            Line lines[] = {Line(*coordinates[0], *coordinates[1]), Line(*coordinates[1], *coordinates[2]),
                           Line(*coordinates[2], *coordinates[0])};

            for (auto & line : lines)
            {
                if (line.GetEndPoint().GetZ() > clippingLineZ && line.GetStartPoint().GetZ() > clippingLineZ)
                    continue;

                float xDistance = line.GetEndPoint().GetX() - line.GetStartPoint().GetX();
                float yDistance = line.GetEndPoint().GetY() - line.GetStartPoint().GetY();
                float zDistance = line.GetEndPoint().GetZ() - line.GetStartPoint().GetZ();
                float zDifference = clippingLineZ - line.GetStartPoint().GetZ();

                float ratio = zDifference / zDistance;

                float xPosition = line.GetStartPoint().GetX() + (xDistance * ratio);
                float yPosition = line.GetStartPoint().GetY() + (yDistance * ratio);

                points.push_back(Point(xPosition, yPosition));

            }

            ++it;
        }

        std::stringstream ss;
        ss << fileName << "-" << i << ".bmp";

        std::thread thread(&Exporter::Export, Exporter(), model, points, ss.str(), resolution);
        thread.detach();

        std::cout << clippingLineZ  << "%" << std::endl;
    }
}
