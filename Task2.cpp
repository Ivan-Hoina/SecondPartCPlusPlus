#include <iostream>
#include <string>
using namespace std;
class Square
{
public:
    Square(double newSide)
    {
        setSide(newSide);
    }

    void setSide(double newSide)
    {
        if (newSide >= 0)
            side = newSide;
        else
        {
            side = 0;
            cout << "Side should be bigger then 0 or equals" << '\n';
        }
        area = side * side;
    }

    double getSide(void)
    {
        return side;
    }

    double getArea(void)
    {
        return area;
    }

    void print()
    {
        cout << "Square: side =" << getSide() << " area =" << getArea() << '\n';
    }

private:
    double side;
    double area;
};