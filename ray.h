#ifndef RAY_H
#define RAY_H

#include "vec3d.h"

class Ray {
private:
    point3 ray_origin;
    Vec3D ray_dir;
public:
    Ray() {

    }
    Ray(const point3& orig, const Vec3D& direction) {
        this->ray_origin = orig;
        this->ray_dir = direction;
    }
    point3 origin() const {
        return this->ray_origin;
    }
    Vec3D direction() const {
        return this->ray_dir;
    }
    point3 at(double t) const {
        /*
            Returns the point that the Ray instance is at given time t.
        */
        return this->ray_origin + t*this->ray_dir;
    }
};

#endif