#include "KeyboardTrainer.h"
#include <iostream>

using namespace std;

KeyboardTrainer::KeyboardTrainer()
{
    p = 0;
    srand(time(NULL));
    int c = 50 + rand() % (80 - 50 + 1);

    s = new char[c];
    s_size = c;
    s[c] = '\0';

    for (int i = 0; i < c; i++)
        s[i] = char('a' + rand() % ('z' - 'a'));
}

KeyboardTrainer::KeyboardTrainer(const KeyboardTrainer& keyboardTrainer)
{
    s_size = keyboardTrainer.s_size;
    p = keyboardTrainer.p;

    s = new char[s_size];
    s[s_size] = '\0';
    for (int i = s_size - 1, g = 0; i >= 0 && g < s_size; i--,g++)
        s[i] = keyboardTrainer.s[g];
}

KeyboardTrainer::~KeyboardTrainer()
{
    delete[] s;
}

void KeyboardTrainer::Start()
{
    cout << "Штрафний бал за кожну помилку - 100 | Кожна правильна літера +10 балів" << endl;
    cout << s << endl;

    string input = "";
    std::cin >> input;

    int mistakes_count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (s[i] != input[i])
        {
            mistakes_count++;
            p -= 100;
        }
        else
            p += 10;
    }

    cout << "Помилки: " << mistakes_count << endl;
    cout << "Кількість балів: " << p << endl;
}