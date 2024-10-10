#include <iostream>
#include <string>
#include "Student.cpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;



void EditInformationByKeyboard(Student *info,int i) {
    string StName,department,program,section, address;
     int mid,final,attendance,quiz;

    cout << "Enter Student Name: ";
    getline(cin, StName);
    info[i].setStudentName(StName);

     cout << "Enter Department : ";
    getline(cin, department);
    info[i].setDepartment(department);

     cout << "Enter Program : ";
    getline(cin, program);
   info[i].setProgram(program);

     cout << "Enter Section : ";
    getline(cin, section);
    info[i].setSection(section);

    cout << "Enter Address : ";
    getline(cin, address);
    info[i].setAddress(address);



    cin.ignore();
}

std::string generateRandomString(int length) {
    std::string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1;

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        randomString += alphabet[rand() % alphabetSize];
    }

    return randomString;
}

int randomInRange(int min, int max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;
}

// Function to generate a random double within a given range [min, max]
double randomInRange(double min, double max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    // Generate a random double between 0 and 1
    double randomFraction = static_cast<double>(rand()) / RAND_MAX;

    // Scale and shift the random value to the desired range
    return min + randomFraction * (max - min);
}


void ShowAllAlphabetically(Student *info, int n) {
    Student temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (info[i].getStudentName() > info[j].getStudentName()) {
                temp = info[i];
                info[i] =info[j];
                info[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Student Name: " << info[i].getStudentName()
             << "  GPA: " << info[i].getGPA()<< endl;
    }
}



int main()
{
    int n=2;
    Student info[100];
    for(int i=0;i<n;i++){
        EditInformationByKeyboard(info,i);
    }
    ShowGPA(info,n);
    ShowAllAlphabetically(info,n);
    return 0;
}





