#include <vector>
#include <stdexcept>
#include <iostream>
#include <stdint.h>

std::vector<u_int64_t> fibVector{0, 1};

//Increases capacity of vector by a pre-configured step size
void steppedIncreaseOfCapacityOfVector(std::vector<u_int64_t> *ptr) {
    const int CAPACITYINCREASESTEPSIZE = 100;
    int newVectorCapacity= ptr->capacity() + CAPACITYINCREASESTEPSIZE;
    ptr->reserve(newVectorCapacity);
} 

u_int64_t getNthFibNumber(u_int64_t n) {
    if(n < 0) {
        throw std::invalid_argument("n must be 0 or greater.");
    }
    else {
        //If already in the list, just return that
        if(fibVector.size() > n) {
            return fibVector.at(n);
        }
        else {
            //n-2 needs to be called first, since otherwise the vector will
            //be out of order after the val is push_back onto vector
            u_int64_t thisFibNumber = getNthFibNumber(n - 2) + getNthFibNumber(n - 1);
            
            //Increase the capacity by one step if needed
            if(n + 1 > fibVector.capacity()) {
                steppedIncreaseOfCapacityOfVector(&fibVector);    
            }

            fibVector.push_back(thisFibNumber);

            return thisFibNumber;
        }
    }
}

int main() {
    fibVector.reserve(100);
}