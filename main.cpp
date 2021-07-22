#include <iostream>

#include "ProductionMachine.hpp" 
#include "ProductionDependent.hpp"
#include "ProductionWorker.hpp"
#include "ProductionManager.hpp"
#include "WarehouseWorker.hpp"

int main() {

    ProductionMachine PM;
    
    ProductionDependent* p1 = new ProductionWorker();
    ProductionDependent* p2 = new ProductionManager();
    ProductionDependent* p3 = new WarehouseWorker();

    PM.attach(p1);
    PM.attach(p2);
    PM.attach(p3);

    PM.runMachine();

    delete p1;
    delete p2;
    delete p3;

    return 0;

}


