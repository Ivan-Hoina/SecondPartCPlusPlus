#include <iostream>
#include <string>

using namespace std;

class AdHocSquare
{
public:
    AdHocSquare(double side)
    {
        this->side = side;
    }
    void set_side(double side)
    {
        this->side = side;
    }
    double get_area()
    {
        return side * side;
    }
private:
    double side;
};

class LazySquare
{
public:
    LazySquare(double side)
    {
        this->side = side;
        area = side * side;
    }
    void set_side(double side)
    {
        this->side = side;
        side_changed = true;
    }
    double get_area()
    {
        if (side_changed)
        {
            area = side * side;
            side_changed = false;
        }

        return area;
    }
private:
    double side;
    double area;
    bool side_changed;
};