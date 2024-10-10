#ifndef Student_h
#define Student_h

#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

class Student{
private:
    string StudentName;
    string Department;
    string Program;
    string Section;
    int AdmissionYear;
    string Address;
    double GPA;
public:
    Student(string StuName,string Dept,string Pro,string Sec,int AdmiYear,string Addr,int PA)
    :StudentName(StuName),Department(Dept),Program(Pro),Section(Sec),AdmissionYear(AdmiYear),Address(Addr),GPA(PA){}


    string getStudentName() const{return StudentName;}
    void setStudentName(const string& StuName) { StudentName = StuName; }

    string getDepartment() const { return Department; }
    void setDepartment(const string& Dept) { Department = Dept; }

    string getProgram() const { return Program; }
    void setProgram(const string& Pro) { Program = Pro; }

    string getSection() const { return Section; }
    void setSection(const string& Sec) { Section = Sec; }

   int getAdmissionYear()  { return AdmissionYear; }
    int setAdmissionYear(int AdmiYear) { AdmissionYear = AdmiYear; }


    string getAddress() const { return Address; }
    void setAddress(const string& Addr) { Address = Addr; }

    double getGPA()  { return GPA; }
    double setGPA(double PA) { GPA = PA; }


    void calculateGPA(int mid,int final,int quiz,int attendance,double marks){
        int mids,finals,attend,quizes;
        mids=mid/3;
        finals=final/3;
        quizes=quiz/3;
        attend=attendance;
        marks=mids+finals+quizes+attend;

        if(marks>0&&marks<40)
            GPA=0;
            else if(marks>=40&& marks<45)
                GPA=2.0;
                        else if(marks>=45&& marks<50)
                GPA=2.25;
                            else if(marks>=50&& marks<55)
                GPA=2.5;
                           else if(marks>=55&& marks<60)
                GPA=2.75;
                            else if(marks>=60&& marks<65)
                GPA=3.0;
                            else if(marks>=65&& marks<70)
                GPA=3.25;
                            else if(marks>=70&& marks<75)
                GPA=3.5;
                            else if(marks>=75&& marks<80)
                GPA=3.75;
                            else if( marks<=80)
                GPA=4.0;



    }


};
#endif // Student_h






