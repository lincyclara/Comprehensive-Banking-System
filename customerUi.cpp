#include "customerUi.h"

void CustomerUI :: displayMenu() 
{
    cout << "Welcome to customer Page" << endl;
    cout << "1. Add account" << endl;
    cout << "2. View Profile" << endl;
    cout << "3. Deposit Amount " << endl;
    cout << "4. Withdraw Amount " << endl;
    cout << "5. Transaction History " << endl;
    cout << "6. Exit " << endl;
}
void CustomerUI :: handleOperations()
{
    bool run = true;
    while(run){
        int option;
        displayMenu();
        cout << "Enter your choice: ";
        cin >> option;

        switch(option){
            case 1:
            {
                string accNum;
                double rate, bal;
                cout << "Enter the Account number: ";
                cin >> accNum;
                cout << "Enter the balance amount: ";
                cin >> bal;
                cout << "Enter the Interest rate: ";
                cin >> rate;
                shared_ptr<Account> acc = make_shared<SavingsAccount>( accNum, bal, rate);
                customer->addAccount(acc);
                cout << "Savingsaccount created successfully\n";
                break;
            }

            case 2:
            customer->displayCustomerInfo();
            break;

            case 3:
            {
            double amount;
            string accNum;
            cout << "Enter the Account number: ";
            cin >> accNum;
            cout << "Enter the Amount: ";
            cin >> amount;
            customer->depositToAccount(accNum,amount);
            break;
            }

            case 4:
            {
                double amount;
                string accNum;
                cout << "Enter the Account number: ";
                cin >> accNum;
                cout << "Enter the Amount: ";
                cin >> amount;
                customer->withdrawFromAccount(accNum,amount);
                cout << "Withdrawal successful\n";
                break;
            }

            case 5:
            customer->displayTransactionHistory();
            break;

            case 6:
            cout << "Exiting customer Menu..." << endl;
            run = false;
            break;

            default:
            cout << "Invalid Choice" << endl;
        }
    }
}