#include "savingsaccount.h"
#include "insufficientFundsException.h"

SavingsAccount::SavingsAccount(string accNum, double bal, double rate)
    : Account(accNum, bal, "Savings"), interestRate(rate) {}

void SavingsAccount::deposit(double amount)
{
    balance += amount;
    addTransaction("Deposit", amount, "2025-02-10");
}

void SavingsAccount::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        addTransaction("Withdraw", amount, "2025-02-10");
    }
    else
    {
        throw InsufficientFundsException("Insufficient balance ");
    }
}

void SavingsAccount::displayAccount() const 
{
    cout << "Account Number: " << accountNumber
         << ", Balance: " << balance
         << ", Interest Rate: " << interestRate << "%\n";
}

void SavingsAccount::saveToFile(ofstream &out) const 
{
    out << accountNumber << "," << balance << "," << interestRate << "\n";
}