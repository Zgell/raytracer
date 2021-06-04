#ifndef HEADERMAIN_H
#define HEADERMAIN_H

#include <cmath>
#include <limits>
#include <memory>

// Using statements

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Useful Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Commonly-used Headers

#include "ray.h"
#include "vec3d.h"

#endif