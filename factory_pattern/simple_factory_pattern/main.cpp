#include "Calculator.h"
#include <iostream>

int main() {
    Calculator calc;

    double result = calc.calculate(5, 3, "*");
    std::cout << "Result: " << result << std::endl;
     double result2 = calc.calculate(result, 3, "/");
    std::cout << "Result: " << result2 << std::endl;

    for (const auto& operation : calc.getHistory()) {
        std::cout << operation << std::endl;
    }


    return 0;
}
