#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    string accountType;
    double currentBalance;
    double minimumBalance;


public:
    BankAccount(int accNum, const string& holderName,const string& accType, double balance, double minBalance)
        : accountNumber(accNum), accountHolderName(holderName), accountType(accType), currentBalance(balance), minimumBalance(minBalance) {}

    void showInfo(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: BDT " << currentBalance << endl;
        cout << "Minimum Balance: BDT " << minimumBalance << endl;
    }
    void showBalance() {
        cout << "Current Balance: BDT " << currentBalance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            currentBalance += amount;
            cout << "Deposit Successful. New Balance: BDT " << currentBalance << endl;
        } else {
            cout << "Invalid." << endl;
        }
    } void withdrawal(double amount) {
        if (amount > 0 && currentBalance - amount >= minimumBalance) {
            currentBalance -= amount;
            cout << "Withdrawal Successful. New Balance: BDT " << currentBalance <<endl;
        } else {
            cout << "Invalid amount for withdrawal or balance too low." << endl;
        }
    }

    void giveInterest(double interestRate = 0.03) {
        double interest = currentBalance * interestRate;
        double tax = interest * 0.1;
        currentBalance += interest - tax;
        cout << "Interest added. New Balance: BDT " << currentBalance << endl;
    }
    BankAccount() {
        cout << "Account of Mr. " << accountHolderName << " with account no " << accountNumber << " is destroyed with a balance BDT " << currentBalance <<endl;
    }
};
int main()
{
    BankAccount account(258,"Sunjoh","savings",5000,1000);

    account.showInfo();
    account.showBalance();
    account.deposit(1000);
    account.withdrawal(700);
    account.giveInterest();

}

