#include <stdio.h>

using namespace std;

class Function {
protected:
    double variable;

public:
    Function() {}
    Function(double var) : variable(var) {}
    virtual double calc() = 0;
};

class Exponenta : public Function {
public:
    Exponenta() {}
    Exponenta(double var) : Function(var) {}
    double calc() override {
        double result = 1;
        double term = 1;
        for (int i = 1; i <= 20; i++) {
            term *= variable / i;
            result += term;
        }
        return result;
    }
};

class NaturalLogarifm : public Function {
public:
    NaturalLogarifm() {}
    NaturalLogarifm(double var) : Function(var) {}
    double calc() override {
        double result = 0;
        double term = (variable - 1) / variable;
        for (int i = 1; i <= 20; i++) {
            result += term / i;
            term *= (variable - 1) / variable;
        }
        return result;
    }
};

