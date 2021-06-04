#ifndef COLOUR_H
#define COLOUR_H

#include "vec3d.h"
#include <iostream>

void write_colour(std::ostream& out, colour pixel_colour) {
    /*
        Writes out the RGB colour to output.
        Used to create a PPM file.
    */
    out << static_cast<int>(255.999 * pixel_colour.x()) << ' '
        << static_cast<int>(255.999 * pixel_colour.y()) << ' '
        << static_cast<int>(255.999 * pixel_colour.z()) << '\n';
}

#endif