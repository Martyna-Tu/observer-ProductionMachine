#pragma once

#include "ProductionDependent.hpp"


class WarehouseWorker : public ProductionDependent {
public: 
    WarehouseWorker() = default;
    ~WarehouseWorker() = default;
    
    void react() override {
        std::cout << "WarehouseWorker collects the finished product and delivers the parts necessary for production\n";
    }
};


