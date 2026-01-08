#include "bankerUi.h"

void BankerUI :: displayMenu() 
{
    cout << "Welcome to Banker Page" << endl;
    cout << "1. Create Customer "<< endl;
    cout << "2. Display All customers "<< endl;
    cout << "3. Exit"<< endl;
}

void BankerUI :: handleOperations() 
{
    bool run = true;

    while(run){ 
        int choice;
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice ;

        switch(choice)
        {
            case 1:
            {
            string id,name,pwd;
            cout << "Enter the customer id: ";
            cin >> id;
            cout << "Enter the customer name: " ;
            cin >> name;
            cout << "Enter the Password: ";
            cin >> pwd;
            banker->createCustomer(customers, id, name, pwd);
            break;
            }

            case 2:
            cout << "All customer's Information" << endl;
            banker->displayAllCustomers(customers);
            break;

            case 3:
            cout << "Exiting Banker Menu ...\n";
            run = false;
            break;

            default:
            cout << "Invalid Choice" << endl;
        }
    }
}