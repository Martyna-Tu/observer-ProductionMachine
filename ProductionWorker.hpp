#pragma once

#include "ProductionDependent.hpp"

class ProductionWorker : public ProductionDependent {
public:
    
    ProductionWorker() = default;
    ~ProductionWorker() = default;
    
    void react() override {
	std::cout << "ProductionWorker : 30 min break\n";
    }
};

