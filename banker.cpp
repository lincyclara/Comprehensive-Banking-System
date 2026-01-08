#include "banker.h"

bool Banker ::  authenticate(const string& pwd)
{
    if(pwd == this->password){
        return true;
    }
    else
    {
        throw AuthenticationFailedException();
    }
}

void Banker ::  createCustomer(map<string, shared_ptr<Customer>>& customers, string id, string name, string pwd)
{
    if(customers.find(id) != customers.end()){
        cout << "Customer ID : " << id << " already exists" << endl;
        return;
    }
    shared_ptr<Customer> newCustomer = make_shared<Customer> (id,name,pwd);
    customers[id] = newCustomer ;

}

void Banker :: displayAllCustomers(const map<string, shared_ptr<Customer>> &customers)
{
    if(customers.empty()){
        cout << "No Accounts" << endl;
        return;
    }
    for(const auto& pair : customers){
        cout << "CustomerID:" << pair.first << endl;
        pair.second->displayCustomerInfo();
    }
}
