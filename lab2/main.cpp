#include <iostream>
#include "OPfas2.h"

using namespace std;

int main() {
    system("chcp 65001");

    int a = 1, x1 = 0, y1 = 0, x2 = 0, y2 = 0, height = 0;

    do {
        cout << "Введіть координати 1 точки: ";
        cin >> x1;
        cin >> y1;

        cout << "Введіть координати 2 точки: ";
        cin >> x2;
        cin >> y2;

        cout << "Введіть висоту: ";
        cin >> height;

        Point dot1 (x1, y1);

        Sircle dot2 (x1, y1, x2, y2);

        Cylinder heeight (x1, y1, x2, y2, height);

        dot2.PrintSquareSircle();

        heeight.PrintSquareCylinder();

        cout << "Перезапустити програму ?(1 - Yes, 2 - No): ";
        cin >> a;

    }
    while (a == 1);

    return 0;
}

