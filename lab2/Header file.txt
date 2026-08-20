#include <stdio.h>

using namespace std;

class Point {

protected:
    int x1 = 0;
    int y1 = 0;

public:
    Point (int x1, int y1);

};

class Sircle : public Point {

protected:
    int Radius = 0;
    int x2 = 0;
    int y2 = 0;

public:
    Sircle(int x1, int y1, int x2, int y2);
    int SquareSircle();
    void PrintSquareSircle();
};

class Cylinder : public Sircle {

protected:
    int height = 0;
    int value_SquareCylinder = 0;

public:
    Cylinder ( int x1, int y1, int x2, int y2, int height);
    int SquareCylinder ();
    void PrintSquareCylinder ();
};