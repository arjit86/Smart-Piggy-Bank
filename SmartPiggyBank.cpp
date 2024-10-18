/*=====================================================================
Program: Smart Piggy Bank 
Date: 2024/9/10
Description: A piggy bank that deposits , withdraws the money and also give the stats regarding 
the coin by clicking on menus like deposit, wtihdraw , viewcoins and exit.
Input: Valid number for the menu , depositing amount from the user
Output: Remaining balance in the piggy bank , Statistics regarding the coin and error messages
Compilation instructions:
Usage:
Modifications:
Date Comment:
---- ------------------------------------------------
======================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float displayMenu(double balance);
float depositMenu(double &currBalance);
float withdrawAmount(double &remBalance);
void viewCoins(double balance);

int main() {
    int choice;
    double balance = 0.00; 

    while (true) {
        displayMenu(balance);
        cin >> choice;

        if (choice == 1) {
            depositMenu(balance);
        } else if (choice == 2) {
            withdrawAmount(balance);
        } else if (choice == 3) {
            viewCoins(balance);  
        } else if (choice == 4) {
            cout << "Good Bye!!" << endl;
            break; //exiting the loop
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}

float displayMenu(double balance) { //function for display Menu
	cout << fixed << setprecision(2);
    cout << setfill('*') << setw(39) << "" << endl;
    cout << "*           Piggy Bank Menu           *" << endl;
    cout << "*                                     *" << endl;
    cout << "*      Current Balance $ "  << setfill(' ') << setw(7) <<balance << "      *" << endl;
    cout << setfill('*') << setw(39) << "" << endl;
    cout << "*                                     *" << endl;
    cout << "* 1)  Make Deposit                    *" << endl;
    cout << "* 2)  Make Withdrawal                 *" << endl;
    cout << "* 3)  View Coins                      *" << endl;
    cout << "* 4)  Exit Program                    *" << endl;
    cout << "*                                     *" << endl;
    cout << setw(39) << "" << endl <<endl;
    cout << "Enter choice: ";
}

float depositMenu(double &currBalance) { //function for deposit
    double maxBal = 900;
    double depositBalance = 0;

    cout << "Enter the amount to be deposited: $ ";
    cin >> depositBalance;

    if (depositBalance < 0) {
        cout << "Invalid amount -- Negative values are not allowed." << endl;
    } else if (depositBalance > (maxBal - currBalance)) {
        cout << "The piggy bank will not hold that much. You may deposit up to $" ;
        cout << fixed << setprecision(2) << (maxBal - currBalance) << endl;
    } else {
        currBalance += depositBalance;
    }
}

float withdrawAmount(double &remBalance) { //function for withdrawing
    double withdraw = 0;
    cout << "Enter the amount to be withdrawn: "; 
    cin >> withdraw;

    if (withdraw < 0) {
        cout << "Invalid amount -- Negative values are not allowed." << endl;
    } else if (withdraw > remBalance || remBalance <= 0) {
        cout << "The piggybank does not contain that much. You may withdraw up to $" << remBalance << endl;
    } else {
        remBalance -= withdraw;
    }
}

void viewCoins(double balance) {
    // function for calculating the number of quarters, dimes, nickels, and pennies
    int quarters = balance / 0.25;
    balance -= quarters * 0.25;

    int dimes = balance / 0.10;
    balance -= dimes * 0.10;

    int nickels = balance / 0.05;
    balance -= nickels * 0.05;

    int pennies = round(balance / 0.01);  

    cout << "***********************************\n";
    cout << "* Statistics *\n";
    cout << "***********************************\n";
    cout << "* Quarters " << quarters << " $ " << fixed << setprecision(2) << (quarters * 0.25) << " *\n";
    cout << "* Dimes    " << dimes << " $ " << fixed << setprecision(2) << (dimes * 0.10) << " *\n";
    cout << "* Nickels  " << nickels << " $ " << fixed << setprecision(2) << (nickels * 0.05) << " *\n";
    cout << "* Pennies  " << pennies << " $ " << fixed << setprecision(2) << (pennies * 0.01) << " *\n";
    cout << "***********************************\n";
}

