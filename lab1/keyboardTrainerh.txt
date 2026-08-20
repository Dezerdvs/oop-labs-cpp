#pragma once

class KeyboardTrainer
{
public:
    KeyboardTrainer();
    KeyboardTrainer(const KeyboardTrainer& keyboardTrainer);
    virtual ~KeyboardTrainer();

    int GetP() const { return  p; }
    void Start();

private:
    char* s;
    int s_size;

    int p;
};