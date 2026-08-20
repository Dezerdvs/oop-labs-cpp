#include <iostream>
#define NOMINMAX
#include <windows.h>
#include <fstream>
#include <thread>
#include <vector>
#include <cmath>

using namespace std;

double integrate_ractangle(double start_point, double end_point, double step, int num_threads) {
    double integral = 0.0;
    vector<thread> threads(num_threads);

    auto function = [](double x) { return pow(x, 3) / sqrt(pow(x * x + 9, 3)); };

    for (int i = 0; i < num_threads; i++) {
        double first_th = start_point + i * (end_point - start_point) / num_threads;
        double second_th = start_point + (i + 1) * (end_point - start_point) / num_threads;
        threads[i] = thread([first_th, second_th, step, &integral, function]() {
            double thread_integral = 0.0;
            for (double x = first_th; x < second_th; x += step) {
                thread_integral += 0.5 * step * (function(x) + function(x + step));
            }
            integral += thread_integral;
        });
    }

    for (int i = 0; i < num_threads; i++) {
        threads[i].join();
    }

    return integral;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    double start_p = 2;
    double end_p = 3;
    vector<double> h_values = {0.00001, 0.0001};

    double true_value = sqrt(start_p * start_p + 9) + 9 / sqrt(start_p * start_p + 9) - sqrt(end_p * end_p + 9) - 9 / sqrt(start_p * start_p + 9);

    cout << "Потоки \t Крок \t Час \t Пришвидшення \t Єфективність \t Похибка \n";

    ofstream fin;
    fin.open("data.txt");
    fin << "Потоки \t|\t Час(сек) \n";

    for (double h: h_values) {
        fin << "Jump: " << h << "\n";
        cout << endl;
        double prev_time = 1.0;
        for (int amount = 1; amount <= thread::hardware_concurrency(); amount++) {
            auto start = chrono::steady_clock::now();
            double result = integrate_ractangle(start_p, end_p, h, amount);
            auto end = chrono::steady_clock::now();

            double time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            time /= 1000;
            if (amount == 1)
                prev_time = time;

            double err = abs(result - true_value);

            double speedUp = prev_time - time;
            double efficiency = speedUp / amount;

            cout << amount << "\t" << h << "\t" << time << "\t" << speedUp << "\t" << efficiency << "\t" << err << "\n";
            prev_time = time;

            fin << amount << "\t" << time << "\n";
        }

    }
    fin.close();

    return 0;
}