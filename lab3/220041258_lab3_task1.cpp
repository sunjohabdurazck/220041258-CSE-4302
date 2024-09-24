#include <iostream>

using namespace std;

class Counter
{
private:
    int counts = 1;
    int incrementNo;
    int sum;

public:
    Counter(int increment = 1) : incrementNo(increment), sum(counts) {}

    void setIncrementStep(int x)
    {
        incrementNo = x;
    }

    int getCount()
    {
        return counts;
    }

    void increment()
    {
        counts += incrementNo; 
    }

    void resetCount()
    {
        counts = 0;  
    }
};

int main()
{
    Counter counter;         
    counter.setIncrementStep(4);  
    counter.increment();     
    cout << "Current Count: " << counter.getCount() << endl;  

    return 0;
}