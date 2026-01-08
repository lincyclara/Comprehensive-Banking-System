#include "customer.h"

bool Customer :: authenticate(const string& pwd) 
{
    if(pwd == this->password){
        return true;
    }
    else
    {
        throw AuthenticationFailedException();
    }
}

void Customer :: addAccount(shared_ptr<Account> acc)
{
    accounts.push_back(acc);
}

void Customer :: displayCustomerInfo() const
{
    cout << "Customer ID: " << customerID << "\nName: " << name << endl;
    cout << "Number of Accounts: " << accounts.size() << endl;
    for(int i=0;i<accounts.size();i++){
        accounts[i]->displayAccount();
    }
}

void Customer :: displayTransactionHistory() const
{
    if(accounts.empty()){
        cout << "No accounts found" << endl;
    }
    for(int i=0;i<accounts.size();i++){
        accounts[i]->displayTransactionHistory();
    }
}

void Customer :: saveToFile(ofstream& out) const
{
    out << customerID <<"," <<  name << ","<< password << endl;

    for(int i=0;i<accounts.size();i++){
        accounts[i]->saveToFile(out);
    }
}

void Customer :: depositToAccount(const string& accNum, double amount)
{
    for (auto& acc : accounts) {
        if (acc->getAccountNumber() == accNum) {
            acc->deposit(amount);
            return;
        }
    }
    throw BankingException("Account not found!");
}

void Customer ::  withdrawFromAccount(const string& accNum, double amount)
{
    for (auto& acc : accounts) {
        if (acc->getAccountNumber() == accNum) {
            acc->withdraw(amount);   // InsufficientFundsException handled inside
            return;
        }
    }
    throw BankingException("Account not found!");
}
