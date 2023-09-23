#pragma once
#include "operation.h"
#include <stdexcept>

class Addition : public Operation{
    public:
    double execute(double a, double b)override{
        return a + b;
    }
};

class Substraction: public Operation{
 public:
  double execute(double a, double b)override{
        return a - b;
  }

};

class Multiplication: public Operation{
    public:
  double execute(double a, double b)override{
        return a * b;
  }
};

class Divison: public Operation{
public:
  double execute(double a, double b)override{
     if (b == 0) throw std::runtime_error("Division by zero");
     return a / b;
  }


};