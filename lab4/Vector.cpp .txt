
#include "Vector.h"
#include <cmath>

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector::getX() const {
    return x;
}

double Vector::getY() const {
    return y;
}

double Vector::getZ() const {
    return z;
}

void Vector::setX(double value) {
    x = value;
}

void Vector::setY(double value) {
    y = value;
}

void Vector::setZ(double value) {
    z = value;
}

Vector Vector::operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator-() const {
    return Vector(-x, -y, -z);
}

double Vector::operator*(const Vector& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector Vector::operator*(double scalar) const {
    return Vector(x * scalar, y * scalar, z * scalar);
}

double Vector::length() const {
    return sqrt(x * x + y * y + z * z);
}

Vector Vector::normalized() const {
    double len = length();
    return Vector(x / len, y / len, z / len);
}

bool Vector::isCollinear(const Vector& other) const {
    Vector normalizedThis = normalized();
    Vector normalizedOther = other.normalized();

    return (normalizedThis == normalizedOther || normalizedThis == -normalizedOther);
}

bool Vector::operator==(const Vector& other) const {
    return (x == other.x && y == other.y && z == other.z);
}