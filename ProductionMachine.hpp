#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class ProductionDependent;

constexpr size_t dailyProductionLimit = 15;
constexpr size_t subLimit = 5;


class ProductionMachine {
public:
    ProductionMachine() = default;

    ProductionMachine(size_t productCounter, std::vector<ProductionDependent*> vec)
    : productCounter_(productCounter)
    , vec_(vec) 
    {}

    ~ProductionMachine() = default;
    
    // Add subscription
    void attach(ProductionDependent* subscriber);

    // Cancels subscription
    bool detach(ProductionDependent* subscriber);

    void runMachine();

    void notify();


private:
    std::vector<ProductionDependent*> vec_ = {};
    
    size_t productCounter_ = 0;

};      
