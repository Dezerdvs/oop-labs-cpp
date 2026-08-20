#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    system("chcp 65001");

    cout << "Номер варіанту: 15" << endl;
    cout << "Виконавець: Скрипніков Віктор Сергійович " << endl;
    cout << "Рівень складності: Рівень В (максимальна оцінка «відмінно»)" << endl;

    int choice = 1;

    while (choice == 1) {
        try {
            // Запит на введення координат вектора v1
            double x1 = 0, y1 = 0, z1 = 0;
            cout << "Введіть координати першого вектора (x y z): ";
            cin >> x1 >> y1 >> z1;
            Vector v1(x1, y1, z1);

            if(cin.fail()) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Невірний тип даних!");
            }
            else{
                if (x1 <= 0 || y1 <= 0 || z1 <= 0 ) {
                    throw invalid_argument(" змінні вектора v1 повинні бути більше 0!");
                }
            }

            // Запит на введення координат вектора v2
            double x2 = 0, y2 = 0, z2 = 0;
            cout << "Введіть координати другого вектора (x y z): ";
            cin >> x2 >> y2 >> z2;
            Vector v2(x2, y2, z2);

            if(cin.fail()) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Невірний тип даних!");
            }
            else{
                if (x2 <= 0 || y2 <= 0 || z2 <= 0 ) {
                    throw invalid_argument(" змінні вектора v2 повинні бути більше 0!");
                }
            }

            // Демострація векторні операції

            // Вивести координати векторів v1 і v2
            cout << "Вектор v1: (" << v1.getX() << ", " << v1.getY() << ", " << v1.getZ() << ")" << endl;
            cout << "Вектор v2: (" << v2.getX() << ", " << v2.getY() << ", " << v2.getZ() << ")" << endl;

            // Вектор додавання
            Vector v3 = v1 + v2;
            cout << "Сума векторів v1 та v2: (" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << ")" << endl;

            // Векторне віднімання
            v3 = v1 - v2;
            cout << "Різниця векторів v1 та v2: (" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << ")"
                 << endl;

            // Перехресний добуток
            Vector crossProduct = Vector(y1 * z2 - z1 * y2, z1 * x2 - x1 * z2, x1 * y2 - y1 * x2);
            cout << "Векторний добуток v1 та v2: (" << crossProduct.getX() << ", " << crossProduct.getY() << ", "
                 << crossProduct.getZ() << ")" << endl;

            // Скалярне множення
            double scalar = 3.0;
            v3 = v1 * scalar;
            cout << "Множення вектора v1 на скаляр " << scalar << ": (" << v3.getX() << ", " << v3.getY() << ", "
                 << v3.getZ() << ")" << endl;


            // Унарний мінус
            v3 = -v1;
            cout << "Операція унарний мінус для вектора v1: (" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ()
                 << ")" << endl;

            // Логічна операція "=="
            bool areEqual = (v1 == v2);
            cout << "Логічна операція '==' для векторів v1 та v2: " << (areEqual ? "true" : "false") << endl;

            // Перевірте колінеарність
            bool areCollinear = v1.isCollinear(v2);
            cout << "Перевірка колінеарності векторів v1 та v2: " << (areCollinear ? "true" : "false") << endl;


        }
        catch (exception& ex ) {
            cout << "Виникла помилка: " << ex.what() << endl;
            cout << "Спробуйте ще раз!" << endl;
        }

        // Запитайте користувача, чи хочуть вони продовжити
        cout << "Бажаєте продовжити роботу програми? (1/2): " << endl;
        cin >> choice;
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
            throw invalid_argument("Невірний тип даних!");
        }

        if (choice != 1 && choice != 2 ) {
            throw invalid_argument("Введено невірне значення для продовження програми!");
        }

    }
    return 0;
}