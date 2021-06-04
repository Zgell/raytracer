#ifndef VEC3D_H
#define VEC3D_H

#include <iostream>
#include <cmath>

/*
    Vec3D Declaration
    A class that represents a 3-dimensional vector.
*/
class Vec3D {
private:
    double i;
    double j;
    double k;
public:
    /* Constructors */
    Vec3D() {
        this->i = 0;
        this->j = 0;
        this->k = 0;
    }
    Vec3D(double a, double b, double c) {
        this->i = a;
        this->j = b;
        this->k = c;
    }

    /* Member Access Functions (Getters/Setters) */
    double x() const {
        return this->i;
    }
    double y() const {
        return this->j;
    }
    double z() const {
        return this->k;
    }
    void set_x(double xx) {
        this->i = xx;
    }
    void set_y(double yy) {
        this->j == yy;
    }
    void set_z(double zz) {
        this->k == zz;
    }

    /* Important Math Functions */
    double length() const {
        return std::sqrt(i*i + j*j + k*k);
    }
    double length_squared() const {
        return i*i + j*j + k*k;
    }

    /* Relevant Operator Overloads */
    Vec3D operator-() const {
        return Vec3D(-i, -j, -k);
    }
    Vec3D& operator+=(const Vec3D rhs) {
        this->i += rhs.i;
        this->j += rhs.j;
        this->k += rhs.k;
        return *this;
    }
    inline friend Vec3D operator+(const Vec3D &u, const Vec3D &v) {
        Vec3D w(u.i + v.i, u.j + v.j, u.k + v.k);
        return w;
    }
    inline friend Vec3D operator-(const Vec3D u, const Vec3D v) {
        Vec3D w(u.i - v.i, u.j - v.j, u.k - v.k);
        return w;
    }
    /*
    Vec3D operator*(const double k) {
        Vec3D v(k * i, k * j, k * k);
        return v;
    }
    */
    inline friend Vec3D operator*(double k, const Vec3D &v) {
        return Vec3D(k*v.i, k*v.j, k*v.k);
    }
    inline friend Vec3D operator*(const Vec3D &v, double k) {
        return k * v;
    }
    Vec3D& operator*=(const double k) {
        this->i *= k;
        this->j *= k;
        this->k *= k;
        return *this;
    }
    inline friend Vec3D operator/(Vec3D v, double k) {
        return (1/k) * v;
    }
    Vec3D& operator/=(const double k) {
        return (*this *= 1/k);
    }
    inline friend std::ostream& operator<<(std::ostream& out, const Vec3D &v) {
        out << "[" << v.i << ", " << v.j << ", " << v.k << "]";
        return out;
    }
};

/* Miscellaneous Important Operations */
inline double dot(const Vec3D& u, const Vec3D& v) {
    double dot_product = u.x()*v.x() + u.y()*v.y() + u.z()*v.z();
    return dot_product;
}
inline Vec3D cross(const Vec3D& u, const Vec3D& v) {
    double a = (u.y() * v.z()) - (u.z() * v.y());
    double b = (u.z() * v.x()) - (u.x() * v.z());
    double c = (u.x() * v.y()) - (u.y() * v.x());
    return Vec3D(a, b, c);
}
inline Vec3D unit_vector(Vec3D v) {
    return v / v.length();
}

using point3 = Vec3D;
using colour = Vec3D;

#endif