#include <iostream>
#include <string>

using namespace std;

class FlightBooking2 {
public:
    FlightBooking2(int id, int capacity, int reserved)
    {
        this->id = id;
        this->capacity = capacity;
        if (capacity < 0)
            this->capacity = capacity;
        this->reserved = reserved;
        if (reserved < 0)
            this->reserved = 0;
        if (reserved > (int) (capacity * 1.05f))
            this->reserved = (int) (capacity * 1.05f);
    }

    void printStatus()
    {
        cout << "Flight [" << id << "] : [" << reserved << "]/[" << capacity << "] ([" << ((reserved * 1.0) / (capacity * 1.0)) * 100.0 << "]%) seats taken\n";
    }

    bool reserveSeats(int reservedSeats)
    {
        if (reservedSeats < 0)
            return false;
        if (reserved + reservedSeats > (int) (capacity * 1.05f))
            return false;

        reserved += reservedSeats;
        return true;
    }

    bool cancelReservations(int reservedSeats)
    {
        if (reservedSeats < 0)
            return false;
        if (reserved - reservedSeats < 0)
            return false;

        reserved -= reservedSeats;
        return true;
    }

private:
    int id;
    int capacity;
    int reserved;
};