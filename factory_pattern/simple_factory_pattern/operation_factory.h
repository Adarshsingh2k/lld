#pragma once
#include "operation.h"
#include <string>


class OperationFactory{
public:
    static Operation *createOperation(const std::string &operatorSymbol);
};