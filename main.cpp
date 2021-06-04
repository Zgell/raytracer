#include "headermain.h"

#include <iostream>

#include "colour.h"
#include "hittable_list.h"
#include "sphere.h"

struct Resolution {
    double width;
    double height;
};

double hit_sphere(const point3& center, double radius, const Ray& r) {
    /*
        A method that checks if a ray intersects a given sphere.
    */
   Vec3D oc = r.origin() - center;
   // Compute coefficients of the quadratic
   auto a = r.direction().length_squared();
   auto half_b = dot(oc, r.direction());
   auto c = oc.length_squared() - radius*radius;
   auto discriminant = half_b*half_b - a*c;
   if (discriminant < 0) {
       return -1.0;
   } else {
       return (-half_b - sqrt(discriminant) ) / a;
   }
}

colour ray_colour(const Ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + colour(1, 1, 1));
    }
    Vec3D unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*colour(1.0, 1.0, 1.0) + t*colour(0.5, 0.7, 1.0);
}

int main() {
    // Image Parameters
    Resolution main_res;
    const auto aspect_ratio = 16.0 / 9.0;

    main_res.width = 400;
    main_res.height = 400 / aspect_ratio;
    const int image_width = static_cast<int>(main_res.width);
    const int image_height = static_cast<int>(main_res.height);

    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = Vec3D(viewport_width, 0, 0);
    auto vertical = Vec3D(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3D(0, 0, focal_length);

    // Render
    std::cout << "P3" << std::endl;
    std::cout << image_width << ' ' << image_height << std::endl;
    std::cout << "255" << std::endl;
    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width-1);
            auto v = double(j) / (image_height-1);
            Ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            colour pixel_colour = ray_colour(r, world);
            write_colour(std::cout, pixel_colour);
        }
    }

    std::cerr << "\nDone.\n";
}