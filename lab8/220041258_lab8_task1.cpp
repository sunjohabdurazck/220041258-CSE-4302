#include <iostream>

using namespace std;

class Account
{

protected:
    string accountNo;
    string accountName;
    float balance;
    static int nextAccountNo;

public:
    Account(const string& accName, float bal)
        : accountName(accName), balance(bal)
    {
        accountNo = "AccountPrefix" + to_string(nextAccountNo+100);
    }

    void setNo(string accNo)
    {
        accountNo=accNo;
    }
    string getNo()
    {
        return accountNo;
    }
    void setName(string accName)
    {
        accountName=accName;
    }
    string getName()
    {
        return accountName;
    }

    void setBalance(float bal)
    {
        balance=bal;
    }
    float getBalance()
    {
        return balance;
    }
    void display()
    {

        cout<<"Account Name : "<<getName()<<endl;
        cout<<"Account Number : "<<getNo()<<endl;
        cout<<"Account Balance : "<<getBalance()<<endl;
    }


};
int Account::nextAccountNo;
class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(const string& holderName, double bal, double interest)
        : Account(holderName, bal), interestRate(interest) {}

    static void nextAccountNo()
    {
        Account::nextAccountNo = 100;

    }
    void display()
    {
        Account::display();
        cout << "Account Type: Savings Account" << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};



class CurrentAccount : public Account
{
private:
    double interestRate;

public:
    CurrentAccount(const string& accName, float bal, double interest)
        : Account(accName, bal), interestRate(interest) {}
    static void nextAccountNo()
    {
        Account::nextAccountNo = 200;

    }
    void display()
    {
        Account::display();
        cout << "Account Type: Current Account" << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};
class LoanAccount : public Account
{
private:
    double interestRate;

public:
    LoanAccount(const string& accName, float bal, double interest)
        : Account(accName, bal), interestRate(interest) {}
    static void nextAccountNo()
    {
        Account::nextAccountNo = 500;

    }
    void display()
    {
        Account::display();
        cout << "Account Type: Current Account" << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};


class MonthlyDepositScheme : public Account
{
protected:
    double interestRate;

public:
    MonthlyDepositScheme(const string& accName, float bal, double interest)
        : Account(accName, bal), interestRate(interest) {}

    void display()
    {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};



class TwoYearMonthlyDepositScheme : public MonthlyDepositScheme
{
private:
    double monthlyDepositAmount;

public:
    TwoYearMonthlyDepositScheme(const string& holderName, double initialBalance, double depositAmount,double interest)
        : MonthlyDepositScheme(holderName, initialBalance,interest), monthlyDepositAmount(depositAmount) {}
    float maxInterest=monthlyDepositAmount*2/100;
    void display()
    {
        MonthlyDepositScheme::display();
        cout << "Account Type: Two-Year Monthly Deposit Scheme" << endl;
        cout << "Monthly Deposit Amount: $" << monthlyDepositAmount << endl;
        cout <<"Maximum Interest : $"<<maxInterest<<endl;

    }
};
class FiveYearMonthlyDepositScheme : public MonthlyDepositScheme
{
private:
    double monthlyDepositAmount;

public:
    FiveYearMonthlyDepositScheme(const string& holderName, double initialBalance, double depositAmount,double interest)
        : MonthlyDepositScheme(holderName, initialBalance,interest), monthlyDepositAmount(depositAmount) {}
    float maxInterest=monthlyDepositAmount*5/100;
    void display()
    {
        MonthlyDepositScheme::display();
        cout << "Account Type: Two-Year Monthly Deposit Scheme" << endl;
        cout << "Monthly Deposit Amount: $" << monthlyDepositAmount << endl;
        cout <<"Maximum Interest : $"<<maxInterest<<endl;

    }
};


int main() {
    SavingsAccount savings("Alice", 1000.0, 3.5);
    CurrentAccount current("Bob", 500.0, 1000.0);
    TwoYearMonthlyDepositScheme twomonthlyDeposit("Charlie", 200.0, 50.0,4.0);
    FiveYearMonthlyDepositScheme fivemonthlyDeposit("Marget", 340.0, 90.0,6.0);

    cout << "=== Savings Account ===" << endl;
    savings.display();
    cout << "\n=== Current Account ===" << endl;
    current.display();
    cout << "\n=== Two-Year Monthly Deposit Scheme ===" << endl;
    twomonthlyDeposit.display();

    cout << "\n=== Five-Year Monthly Deposit Scheme ===" << endl;
    fivemonthlyDeposit.display();

    return 0;
}

