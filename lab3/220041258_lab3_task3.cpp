#include <iostream>
#include <cstring> 

using namespace std;

class Medicine {
private:
    double pr;  
    double dis; 
    double sp;  
    char name[30];
    char genericName[30];

public:
    void assignName(const char name[30], const char genericName[30]) {
        strcpy(this->name, name);
        strcpy(this->genericName, genericName);
    }

    void assignPrice(double price) {
        if (price < 0)
            price = 0;
        pr = price;
    }

    void setDiscountPercent(double percent) {
        if (percent < 0 || percent > 30)
            percent = 5;  
        dis = (percent / 100) * pr;
    }

    double getSellingPrice() {
        sp = pr - dis;  
        return sp;
    }

    void display() {
        cout << name << " (" << genericName << ") is BDT " << pr
             << ". Current discount: BDT " << dis
             << ". Selling price: BDT " << sp << endl;
    }
};

int main() {
    Medicine com;
    
    com.assignName("Napa", "Paracetamol");

    com.assignPrice(100);
    com.setDiscountPercent(10);

    com.getSellingPrice();
    com.display();

    return 0;
}