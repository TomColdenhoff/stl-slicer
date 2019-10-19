//
// Created by Tom Coldenhoff on 19/10/2019.
//

#include <iostream>
#include "../Header/Exporter.h++"
#include "../Header/bitmap_image.hpp"
#include "../Header/Model.h++"

void Exporter::Export(Model* model, std::vector<Point> points, std::basic_string<char, std::char_traits<char>, std::allocator<char>> filename, int resolution)
{
    float factor = resolution / (model->GetBoundingBoxEnd().GetX() - model->GetBoundingBoxStart().GetX());

    int startX = model->GetBoundingBoxStart().GetX();
    int startY = model->GetBoundingBoxStart().GetY();

    bitmap_image image(resolution,resolution);

    // set background to white
    image.set_all_channels(255, 255, 255);

    image_drawer draw(image);

    for (auto & point : points)
    {
        draw.pen_width(1);
        draw.pen_color(0, 0, 0);
        draw.rectangle((point.GetX() - startX) * factor, (point.GetY() - startY) * factor, (point.GetX() - startX) * factor, (point.GetY() - startY) * factor);
    }

    image.save_image(filename);
}

