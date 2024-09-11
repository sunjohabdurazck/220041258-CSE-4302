#include <iostream>

using namespace std;

int main()
{
    char x;

    enum etype{laborer, secretary, manager,accountant, executive, researcher};
    etype job;

    cout<<"Enter first letter: ";
   cin>>x;
   switch(x){
   case 'l':
       job=laborer;
       break;
   case 's':
       job=secretary;
    break;
   case 'm':
       job=manager;
    break;
   case 'a':
       job=accountant;
    break;
    case 'e':
        job=executive;
    break;
    case 'r':
        job=researcher;
    break;
    default:
    cout<<"Invalid";
   }
    string etype_text;
    switch(job){
   case laborer:
       etype_text="laborer";
       break;
   case secretary:
       etype_text="secretary";
    break;
   case manager:
       etype_text="manager";
    break;
   case accountant:
       etype_text="accountant";
    break;
    case executive:
        etype_text="executive";
    break;
    case researcher:
        etype_text="researcher";
    break;
    default:
    cout<<"Invalid";

    }
    cout<<"Employee type is: "<<etype_text<<endl;
    return 0;
}
