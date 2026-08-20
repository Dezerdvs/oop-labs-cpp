#include <iostream>
#include "OPfas3.h"

using namespace std;

int main() {
    system("chcp 65001");
    int a = 1;
    cout << "Номер варіанту: 15" << endl;
    cout << "Виконавець: Скрипніков Віктор " << endl;
    cout << "Рівень складності: середній" << endl;

    double x;
    char choice;
    do {
        cout << "Введіть значення змінної x: ";
        cin >> x;

        Function* f = new Exponenta(x);
        double expResult = f->calc();
        delete f;

        f = new NaturalLogarifm(x);
        double lnResult = f->calc();
        delete f;

        cout << "Результат обчислення експоненти: " << expResult << endl;
        cout << "Результат обчислення натурального логарифму: " << lnResult << endl;

        cout << "Бажаєте продовжити роботу програми? (y/n): ";
        cin >> choice;
    }
    while (a == 1);

    return 0;
}
