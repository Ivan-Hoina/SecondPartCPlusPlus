#include <iostream>
#include <string>
#include "Task1.cpp"
#include "Task2.cpp"
#include "Task3.cpp"
#include "Task4.cpp"
#include "Task5.cpp"
#include "Task6.cpp"
#include "Task7.cpp"

using namespace std;

int Part5Section1Task1();
int Part5Section1Task2();
int Part5Section1Task3();
int Part5Section1Task4();

int Part5Section3Task1();
int Part5Section3Task2();
int Part5Section3Task3();


int main()
{
    // 5.1.9(1)
    //return Part5Section1Task1();

    // 5.1.9(2)
    //return Part5Section1Task2();
    
    // 5.1.9(3)
    //return Part5Section1Task3();
    
    // 5.1.9(4)
    //return Part5Section1Task4();
    
    // 5.3.10(1)
    //return Part5Section3Task1();

    // 5.3.10(2)
    //return Part5Section3Task2();
    
    // 5.3.10(3)
    return Part5Section3Task3();
}

//5.1.9

int Part5Section1Task1()
{
    Person person;
    person.setName("Harry");
    person.setLastName("Peterson");
    person.setAge(23);
    cout << "Meet " << person.getName() << ' ' << person.getLastName() << '\n';
    person.print();

    person.setName("Marry");
    person.setLastName("Anderson");
    person.setAge(25);
    cout << "Meet " << person.getName() << ' ' << person.getLastName() << '\n';
    person.print();

    return 0;
}

int Part5Section1Task2()
{
    Square s(4);
    s.print();
    s.setSide(2.0);
    s.print();
    s.setSide(-33.0);
    s.print();
    return 0;
}

int Part5Section1Task3()
{
    AdHocSquare ahs(2);
    cout << ahs.get_area() << '\n';
    ahs.set_side(5);
    cout << ahs.get_area() << '\n';

    LazySquare ls(2);
    cout << ls.get_area() << '\n';
    ls.set_side(5);
    cout << ls.get_area() << '\n';

    return 0;
}

int Part5Section1Task4()
{
    ShopItemOrder sio1("Desktop PC", 56000, -1);
    sio1.toString();
    cout << '\n';

    ShopItemOrder sio2("Notebook", -16500, 5);
    sio2.toString();
    cout << '\n';

    ShopItemOrder sio3("Mobile phone", 8000, 2);
    sio3.toString();

    return 0;
}

//5.3.10

int Part5Section3Task1() {
    int reserved = 0,
        capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;
    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();
    return 0;
}

int Part5Section3Task2() {
    int reserved = 0,
        capacity = 0;
    string mistake = "Something went wrong! Check your inputs or reread documentation.\n";
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;
    FlightBooking2 booking(1, capacity, reserved);
    string command = "";
    booking.printStatus();
    while (command != "quit")
    {
        cout << "What would you like to do?: ";
        getline(cin, command);

        if (command == "")
            continue;

        if (command == "Reserve")
        {
            int amount;
            cout << "Please enter amount of new reverved seats: ";
            cin >> amount;
            bool result = booking.reserveSeats(amount);
            if (result)
                cout << "Success!\n";
            else
                cout << mistake;
        }
        else if (command == "Cancel")
        {
            int amount;
            cout << "Please enter amount of canceled reverve seats: ";
            cin >> amount;
            bool result = booking.cancelReservations(amount);
            if (!result)
                cout << mistake;
        }

        booking.printStatus();
    }
    return 0;
}

int Part5Section3Task3() {
    FlightBookingManager manager;
    // Use this to have some starting value
    // booking[0] = FlightBooking(1, 400, 0);
    // booking[0].printStatus();
    string command = "";
    string mistake = "Something went wrong!\n";
    while (command != "quit")
    {
        cout << "What would you like to do?: ";
        getline(cin, command);

        if (command == "")
            continue;

        if (command == "Create") {
            int id;
            int capacity;
            cout << "Please enter new booking id:";
            cin >> id;
            cout << "\n Plane enter booking capacity: ";
            cin >> capacity;
            bool result = manager.create(id, capacity);
            if (result)
                cout << "Booking with " << id << " Id already created!\n";
            else
                cout << mistake;
        }
        else if (command == "Delete") {
            int id;
            cout << "Please enter new booking id: \n";
            cin >> id;
            bool result = manager.del(id);
            if (result)
                cout << "Booking with " << id << " Id already deleted!\n";
            else
                cout << mistake;
        }
        else if (command == "Reserve")
        {
            int id;
            cout << "Please enter new booking id:";
            cin >> id;
            int amount;
            cout << "\nPlease enter amount of new reverved seats: ";
            cin >> amount;
            bool result = manager.add(id, amount);
            if (result)
                cout << "On booking with " << id << " Id already added " << amount << " of reserved seats!\n";
            else
                cout << mistake;
        }
        else if (command == "Cancel")
        {
            int id;
            cout << "Please enter new booking id:";
            cin >> id;
            int amount;
            cout << "\nPlease enter amount of new reverved seats: ";
            cin >> amount;
            bool result = manager.cancel(id, amount);
            if (result)
                cout << "On booking with " << id << " Id already removed " << amount << " of reserved seats!\n";
            else
                cout << mistake;
        }
        else if (command == "Status") 
        {
            int id;
            cout << "Please enter new booking id:";
            cin >> id;
            cout << '\n';
            manager.status(id);
        }
    }
    return 0;
}