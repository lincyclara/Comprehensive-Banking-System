// Banking System Skeleton Code (Advanced Version with File Handling, UI Classes, and Transaction History)

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <fstream>


using namespace std;

// --------------------- MAIN FUNCTION --------------------- //

int main() {
    map<string, shared_ptr<Customer>> customers;
    map<string, shared_ptr<Banker>> bankers;

    bankers["B001"] = make_shared<Banker>("B001", "Admin", "admin123");

    try {
        cout << "Welcome to Global Bank\n";
        cout << "Login as (banker/customer): ";
        string role;
        cin >> role;

        if (role == "banker") {
            string id, pwd;
            cout << "Enter Banker ID: "; cin >> id;
            cout << "Enter Password: "; cin >> pwd;

            if(bankers.find(id) == bankers.end()){
                throw AuthenticationFailedException("Banker ID not found!");
            }
            auto banker = bankers[id];
            banker->authenticate(pwd);

            BankerUI bankerUI(banker, customers);
            bankerUI.handleOperations();
        } else if (role == "customer") {
            string id, pwd;
            cout << "Enter Customer ID: "; cin >> id;
            cout << "Enter Password: "; cin >> pwd;

            if(customers.find(id) == customers.end()){
                throw AuthenticationFailedException("Customer ID not found!");
            }
            auto customer = customers[id];
            customer->authenticate(pwd);

            CustomerUI customerUI(customer);
            customerUI.handleOperations();
        } else {
            throw BankingException("Invalid role selected.");
        }
    } catch (const BankingException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
