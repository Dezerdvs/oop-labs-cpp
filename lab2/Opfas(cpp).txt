#include "OPfas2.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point(int x1, int y1) : x1(x1), y1(y1) {}

Sircle::Sircle(int x1, int y1, int x2, int y2) : Point(x1, y1) {}

int Sircle::SquareSircle() {

    Radius = ( 3.14 * sqrt( pow((x2 - x1), 2) + pow((y2 - y1), 2)) );
    return Radius;

}

void Sircle::PrintSquareSircle() {
    cout << "Площа Круга:" << SquareSircle() << endl;
}

Cylinder::Cylinder( int x1, int y1, int x2, int y2, int height) : height(height), Sircle(x1, y1, x2, y2) {}

int Cylinder::SquareCylinder() {
    value_SquareCylinder = 2 * (3.14 * SquareSircle() * height) + 2 * (3.14 * pow(SquareSircle(), 2));
    return value_SquareCylinder;
}

void Cylinder::PrintSquareCylinder() {
    cout << "Площа циліндра: " << SquareCylinder() << endl;
}
