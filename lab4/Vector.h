#pragma once

class Vector {
private:
    double x, y, z;

public:
    Vector(double x = 0, double y = 0, double z = 0);

    // Методи доступу до приватних полів x, y, z
    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double value);
    void setY(double value);
    void setZ(double value);

    // Оператори
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator-() const;
    double operator*(const Vector& other) const;
    Vector operator*(double scalar) const;

    // Методи для обчислення довжини вектора та його нормалізації
    double length() const;
    Vector normalized() const;

    // Метод для перевірки колінеарності векторів
    bool isCollinear(const Vector& other) const;

    // Оператор порівняння
    bool operator==(const Vector& other) const;
};
