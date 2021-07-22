#pragma once

class ProductionDependent {
public:
    ProductionDependent() = default;
    virtual ~ProductionDependent() =default;
    virtual void react() = 0;
};

