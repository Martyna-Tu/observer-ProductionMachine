#pragma once

#include "ProductionDependent.hpp"


class ProductionManager : public ProductionDependent {
public:

    ProductionManager() = default;
    ~ProductionManager() = default;

    void react() override {
        std::cout << "ProductionManager checks the quality of the product and the workplace\n";
    }
};

