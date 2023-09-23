#pragma once
#include "operation_factory.h"
#include <vector>
#include <string>

class Calculator {

private:
    std::vector<std::string> history;

public:
    double calculate(double a, double b, const std::string& operatorSymbol) {
        Operation* op = OperationFactory::createOperation(operatorSymbol);
        double result = op->execute(a, b);
        delete op;

         std::string operation = std::to_string(a) + " " + operatorSymbol + " " + std::to_string(b) + " = " + std::to_string(result);
         addToHistory(operation);

         return result;
    }

     void addToHistory(const std::string& operation) {
        history.push_back(operation);
    }

    std::vector<std::string> getHistory() const {
        return history;
    }

     void clearHistory() {
        history.clear();
    }
};
