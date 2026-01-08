#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "transaction.h"

using namespace std;

class Account
{
protected:
    string accountNumber;
    double balance;
    string accountType;
    vector<Transaction> transactions;

    
public:
    Account(string accNum, double bal, string accType);
    string getAccountNumber() const {
        return accountNumber;
    }

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayAccount() const = 0;
    virtual void saveToFile(ofstream &out) const = 0;
    void addTransaction(const string &type, double amount, const string &date);
    void displayTransactionHistory() const;
    virtual ~Account() {}
};