#include <iostream>
#include "KeyboardTrainer.h"
#include "windows.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    KeyboardTrainer keyboardTrainer = KeyboardTrainer();;
    keyboardTrainer.Start();
    return 0;
}
