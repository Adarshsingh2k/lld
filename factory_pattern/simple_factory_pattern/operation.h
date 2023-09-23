#pragma once

class Operation{
    public:
     virtual double execute(double a, double b)=0;
     virtual ~Operation() {}
};