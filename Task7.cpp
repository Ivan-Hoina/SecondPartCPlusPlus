#include <iostream>
#include <array>
#include <string>

using namespace std;

class FlightBooking3
{
public:
    FlightBooking3()
    {
        id = -1;
        capacity = 0;
        reserved = 0;
    }
    FlightBooking3(int id, int capacity, int reserved)
    {
        this->id = id;
        this->capacity = capacity;
        if (capacity < 0)
            this->capacity = capacity;
        this->reserved = reserved;
        if (reserved < 0)
            this->reserved = 0;
        if (reserved > (int) (capacity * 1.05f))
            this->reserved = (int)(capacity * 1.05f);
    }
    ~FlightBooking3()
    {
        delete& id;
        delete& capacity;
        delete& reserved;
    }
    void printStatus()
    {
        cout << "Flight [" << id << "] : [" << reserved << "]/[" << capacity << "] ([" << ((reserved * 1.0) / (capacity * 1.0)) * 100.0 << "]%) seats taken\n";
    }
    bool reserve(int reservedSeats)
    {
        if (reservedSeats < 0)
            return false;
        if (reserved + reservedSeats > (int) (capacity * 1.05f))
            return false;

        reserved += reservedSeats;
        return true;
    }
    bool cancel(int reservedSeats)
    {
        if (reservedSeats < 0)
            return false;
        if (reserved - reservedSeats < 0)
            return false;

        reserved -= reservedSeats;
        return true;
    }
    int getId() { return id; };
    int getCapacity() { return capacity; };
    int getReserved() { return reserved; };

    bool operator !=(FlightBooking3* booking) {
        return this != booking;
    }

private:
    int id;
    int capacity;
    int reserved;
};

class FlightBookingManager
{
public:
    bool create(int id, int capacity)
    {
        if (id < 0)
            return false;

        bookings[id] = new FlightBooking3(id, capacity, 0);

        return true;
    }

    bool del(int id)
    {
        if (id < 0)
            return false;

        delete bookings[id];
        return true;
    }

    bool add(int id, int amount)
    {
        if (id < 0)
            return false;

        if (bookings[id] == NULL)
            return false;

        return bookings[id]->reserve(amount);        
    }

    bool cancel(int id, int amount)
    {
        if (id < 0)
            return false;

        if (bookings[id] == NULL)
            return false;

        return bookings[id]->cancel(amount);
    }    

    void status(int id)
    {
        if (id < 0)
            return;

        if (bookings[id] == NULL)
            return;

        bookings[id]->printStatus();
    }

private:
    int bookingsAmount = 50;
    array<FlightBooking3*, 50> bookings;
};