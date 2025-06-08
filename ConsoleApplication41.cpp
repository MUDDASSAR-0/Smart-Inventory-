// ConsoleApplication41.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    char condition;
    //add time
    //time_t is data type used to store time.time(0) get current system time. now store time
    time_t now = time(0);
    //struct is user define data type.tm structure define in c time library & itm hold broken time (year, date , day)
    struct tm ltm;
    //localtime_s convert time into human readable form
    localtime_s(&ltm, &now);
    //in date section arrry alway start with sunday otherwise answer will be change
    const string day[7] = { "sunday","monday","tuesday","wednesday","thursday","friday","saturday" };
    const int SIZE = 20;

    string names[SIZE] = { "Sugar", "Wheat", "Rice", "Juice", "Biscuit",
                           "Milk", "Eggs", "Tea", "Coffee", "Oil",
                           "Salt", "Soap", "Shampoo", "Toothpa", "Butter",
                           "Cheese", "Detergt", "Bread", "Tomato", "Potato" };

    int quantity[SIZE] = { 50, 40, 30, 20, 100,
                           60, 70, 35, 45, 55,
                           90, 85, 40, 25, 65,
                           75, 80, 100, 60, 50 };

    int price[SIZE] = { 50, 40, 60, 80, 10,
                        30, 12, 100, 120, 90,
                        20, 15, 85, 25, 55,
                        70, 65, 25, 18, 22 };

    int totalCost = 0;
    char moreItems = 'y';

    string purchasedItems[SIZE];
    int purchasedQuantities[SIZE];
    int purchasedPrices[SIZE];
    int purchaseCount = 0;

    cout << "------------------------------------------------" << endl;
    cout << "         WELCOME               " << endl;
    cout << "IF YOU WANT TO SELL ITEM THEN PRESS S & IF YOU WANT TO PURCHASE ITEM THEN PRESS P (S / P): ";
    cin >> condition;
    //sell things
    if (condition == 's' || condition == 'S') {
        cout << "\n----- BUY PRODUCT -----\n";
        //show inventory
        cout << "ID\tName\t\tStock\tPrice\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i + 1 << "\t" << names[i] << "\t\t" << quantity[i] << "\tRs." << price[i] << endl;
        }
        //user press y to add more things
        while (moreItems == 'y' || moreItems == 'Y') {
            int id, qty;
            cout << "Enter product ID to buy: ";
            cin >> id;

            if (id < 1 || id > SIZE) {
                cout << "Invalid Product ID! Please try again.\n";
                continue;
            }

            cout << "Enter quantity to buy: ";
            cin >> qty;
            while (qty > quantity[id - 1]) {
                cout << "LIMITED STOCK " << names[id - 1] << " of " << quantity[id - 1] << " Available";
                cout << "\nAGAIN ENTER QUANTITY TO BUY : ";
                cin >> qty;
            }

            quantity[id - 1] -= qty;
            totalCost += qty * price[id - 1];

            purchasedItems[purchaseCount] = names[id - 1];
            purchasedQuantities[purchaseCount] = qty;
            purchasedPrices[purchaseCount] = price[id - 1];
            purchaseCount++;

            cout << "Added " << qty << " " << names[id - 1] << "(s) to your cart.\n";

            cout << "Do you want to buy more items? (y/n): ";
            cin >> moreItems;
        }
        //generate bill of sell 
        system("cls");
        cout << "-------------------------------------------------\n";
        cout << "\t------- BILL -------\n";
        cout << "    ------ THANKS FOR COMING ------ \n";
        cout << "    DATE : " << 1900 + ltm.tm_year << ":" << 1 + ltm.tm_mon << ":" << ltm.tm_mday << "\tDAY: " << day[ltm.tm_wday] << endl;
        cout << "--------------------------------------------------\n";
        cout << "Item\t\tQuantity\tPrice\tTotal\n";
        for (int i = 0; i < purchaseCount; i++) {
            int itemTotal = purchasedQuantities[i] * purchasedPrices[i];
            cout << purchasedItems[i] << "\t\t" << purchasedQuantities[i] << "\t\tRs." << purchasedPrices[i]
                << "\tRs." << itemTotal << endl;
        }
        cout << "\nTotal amount to pay: Rs." << totalCost << endl;
    }
    //purchase section
    if (condition == 'p' || condition == 'P') {
        cout << "\n----- PURCHASE PRODUCT -----\n";
        //show inventory
        cout << "ID\tName\t\tStock\tPrice\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i + 1 << "\t" << names[i] << "\t\t" << quantity[i] << "\tRs." << price[i] << endl;
        }

        while (moreItems == 'y' || moreItems == 'Y') {
            int id, qty;
            cout << "Enter product ID to purchase: ";
            cin >> id;

            if (id < 1 || id > SIZE) {
                cout << "Invalid Product ID! Please try again.\n";
                continue;
            }

            cout << "Enter quantity to purchase: ";
            cin >> qty;

            quantity[id - 1] += qty;

            cout << "Updated stock for " << names[id - 1] << ": " << quantity[id - 1] << "\n";

            cout << "Do you want to add more stock? (y/n): ";
            cin >> moreItems;
        }
        //show updated inventory
        system("cls");
        cout << "--------------inventory updated--------------\n";
        cout << "ID\tName\t\tStock\tPrice\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i + 1 << "\t" << names[i] << "\t\t" << quantity[i] << "\tRs." << price[i] << endl;}

    }
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
