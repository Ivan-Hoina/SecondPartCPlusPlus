#include <iostream>

using namespace std;

class FlightBooking {
public:

    FlightBooking(int id, int capacity, int reserved)
    {
        this->id = id;
        this->capacity = capacity;
        if (capacity < 0)
            this->capacity = capacity;
        this->reserved = reserved;
        if (reserved < 0)
            this->reserved = 0;
        if (reserved > capacity)
            this->reserved = capacity;
    }
    
    void printStatus()
    {
        cout << "Flight [" << id << "] : [" << reserved << "]/[" << capacity << "] ([" << ((reserved * 1.0) / (capacity * 1.0)) * 100.0 << "]%) seats taken";
    }

private:
    int id;
    int capacity;
    int reserved;
};