#include <iostream>
#include "KeyboardTrainer.h"
#define NOMINMAX
#include "windows.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    KeyboardTrainer keyboardTrainer = KeyboardTrainer();;
    keyboardTrainer.Start();
    return 0;
}
