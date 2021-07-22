#include <thread>
#include <chrono>
#include "ProductionDependent.hpp"
#include "ProductionMachine.hpp"

void ProductionMachine::attach(ProductionDependent* subscriber) {
    vec_.push_back(subscriber);
}

bool ProductionMachine::detach(ProductionDependent* subscriber) {
    auto result = std::find(vec_.cbegin(), vec_.cend(), subscriber);
    if (result != vec_.cend()) {
        vec_.erase(result);
        return true;
    }
    return false;
}

void ProductionMachine::runMachine() {
    std::cout << "Getting started. The worker turns on the machine.\n"; 
    while (productCounter_ < dailyProductionLimit) {
	++productCounter_;
	std::this_thread::sleep_for (std::chrono::milliseconds(200));
	std::cout << "|\n";    
	if (productCounter_ % subLimit == 0) {
	    std::cout << '\n';
	    this->notify();
	    std::this_thread::sleep_for (std::chrono::milliseconds(2000));;
	}
    }
    std::cout << "End of work\n";
}
         
void ProductionMachine::notify() {
    for (auto* prodDepObj : vec_) {
        if (prodDepObj) {
            prodDepObj->react();
        }
    }
}
  
