#include "account.h"

Account ::Account(string accNum, double bal, string accType){
    accountNumber = accNum;
    balance = bal;
    accountType = accType;
}

void Account :: addTransaction(const string &type, double amount, const string &date)
{
    Transaction  T1 = {type , amount , date};
    transactions.push_back(T1);
}

void Account :: displayTransactionHistory() const
{
    if(transactions.empty() ){
        cout << "Transacaction History is empty" << endl;
        return;
    }
    for(int i=0;i<transactions.size();i++){
        transactions[i].displayTransaction();
    }
}