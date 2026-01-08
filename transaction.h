#include <iostream>
using namespace std;

class Transaction {
    string type;
    double amount;
    string date;

public:
    Transaction(const string& t, double amt, const string& dt) : type(t), amount(amt), date(dt) {}

    void displayTransaction() const;
};