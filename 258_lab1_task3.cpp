#include <iostream>

using namespace std;

struct fract{
int numerator;
int denumerator;
};
int main()
{
    int res1,res2;
    fract f1;
    fract f2;
    char dummychar;

       cout << "Enter first fraction numbers: ";
        cin>>f1.numerator>>dummychar>>f1.denumerator;
           cout<<"Enter second fraction: ";
    cin>>f2.numerator>>dummychar>>f2.denumerator;
    res1=f1.numerator*f2.denumerator+f1.denumerator*f2.numerator;
    res2=f1.denumerator*f2.denumerator;
    cout<<"Sum= "<<res1<<"/"<<res2;
    return 0;
}
