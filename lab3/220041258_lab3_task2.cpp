#include <iostream>
using namespace std;

class RationalNumber
{
private:
    int a; 
    int b;  

public:
    void assign(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            cout << "Invalid fraction (denominator cannot be 0)." << endl;
            return;
        }
        a = numerator;
        b = denominator;
    }

    float convert()
    {
        if (b == 0)
        {
            cout << "Invalid fraction (denominator cannot be 0)." << endl;
            return 0.0;
        }
        return float(a) / float(b);
    }

    void invert()
    {
        if (a == 0)
        {
            cout << "Cannot invert a fraction with a zero numerator." << endl;
            return;
        }
        int temp = a;
        a = b;
        b = temp;
    }

    void print()
    {
        if (b == 0)
        {
            cout << "Invalid fraction (denominator cannot be 0)." << endl;
            return;
        }
        cout << "The rational number is " << a << "/" << b << endl;
    }

    int returnNo()
    {
        return a;
    }
};

int main()
{
    RationalNumber bo;
    bo.assign(3, 4);
    bo.print();

    return 0;
}