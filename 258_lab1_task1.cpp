#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    char dummychar;


    cout << "Enter first fraction numbers: ";
        cin>>a>>dummychar>>b;
    cout<<"Enter second fraction: ";
    cin>>c>>dummychar>>d;
    e=((a*d)+(b*c));
    f=(b*d);
    cout<<"Their sum is "<<e<<"/"<<f;
    return 0;
}
