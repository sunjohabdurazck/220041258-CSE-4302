#include <iostream>

using namespace std;
class Employee{
private:
    string EmpName;
    int ID;
    int Age;
    float Salary;
    void getStatus(){
    if(Age<=25&& Salary<=20000){
        cout<<"Status: Low";
    }
    else if(Age<=25&& Salary>20000)
        cout<<"Status: Moderate";
    else if(Age>25&& Salary<=21000)
        cout<<"Status: Low";
    else if(Age>25&& Salary>21000&& Salary<=60000)
        cout<<"Status: Moderate";
    else if(Age>25&& Salary>60000)
        cout<<"Status: High";
        else
            cout<<"Invalid";
    }
public:

   void FeedInfo(){

       cout<<"Enter employee name: "<<endl;
       cin>>EmpName;

       cout<<"Enter employee ID: "<<endl;
       cin>>ID;

       cout<<"Enter employee age: "<<endl;
       cin>>Age;
       cout<<"Enter salary: "<<endl;
       cin>>Salary;

    }
    void ShowInfo(){
        cout << "Employee Name: " << EmpName << endl;
        cout << "Employee ID: " << ID << endl;
        cout  << "Employee Age: "<<Age<< endl;
        cout << "Employee Salary: " << Salary << endl;
         getStatus();


    }

};
int main()
{

Employee employ;

employ.FeedInfo();
employ.ShowInfo();
    return 0;
}
