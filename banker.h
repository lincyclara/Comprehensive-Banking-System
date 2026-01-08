#include <iostream>
#include <memory>
#include <map>
#include "customer.h"
#include "authenticationFailedException.h"

using namespace std;

class Banker {
    string bankerID;
    string name;
    string password;

public:
    Banker(string id, string nm, string pwd);
    bool authenticate(const string& pwd);
    void createCustomer(map<string, shared_ptr<Customer>>& customers, string id, string name, string pwd);
    void displayAllCustomers(const map<string, shared_ptr<Customer>> &customers);
};