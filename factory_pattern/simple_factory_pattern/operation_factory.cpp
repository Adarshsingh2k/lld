#include "operation_factory.h"
#include "basic_operations.h"
#include <stdexcept>

Operation * OperationFactory::createOperation(const std::string& operatorSymbol){
    if(operatorSymbol=="+"){
        return new Addition();
    }
    else if(operatorSymbol== "-"){
        return new Substraction();
    }
    else if(operatorSymbol=="*"){
        return new Multiplication();
    }
    else if(operatorSymbol=="/"){
        return new Divison();
    }
    else{
        throw std::invalid_argument("Invlid Operation");
    }
}