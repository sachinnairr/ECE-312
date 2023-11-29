// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Sachin Nair
// SVN343
// Slip days used: <1>
// Summer 2022

#include <stdio.h>
#include <iostream>
#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"

using namespace std;

void readString(UTString&);
void readNum(int&);

CustomerDB database;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;

/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Bottles") {
        return &num_bottles;
    } else if (word == "Diapers") {
        return &num_diapers;
    } else if (word == "Rattles") {
        return &num_rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Bottles") {
        return &cust.bottles;
    } else if (word == "Diapers") {
        return &cust.diapers;
    } else if (word == "Rattles") {
        return &cust.rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}
void processPurchase() {
    UTString customer;
    readString(customer);

    UTString product;
    readString(product);

    int count;
    readNum(count);

    Customer c = database[customer];
    int itemQuant = *selectInventItem(product);
    int *items = (selectInventItem(product, c));

    if (count <= 0) {
        cout << "Sorry " << customer.c_str() << ", we only have " << itemQuant << " " << product.c_str() << endl;
    }
    else if(count <= itemQuant) {
        *items += count;
        database[customer] = c;
        *selectInventItem(product) -= count;
    }
}
void helperBottles(Customer* maxCustomer){
    if(maxCustomer!=0){
        cout << maxCustomer->name.c_str() << " has purchased the most Bottles (" << maxCustomer->bottles << ")" << endl;
    }

    else if(maxCustomer == 0){
        cout << "no one has purchased any Bottles" << endl;
    }
}
void helperDiapers(Customer* maxCustomer){
    if(maxCustomer!=0){
        cout << maxCustomer->name.c_str() << " has purchased the most Diapers (" << maxCustomer->diapers << ")" << endl;
    }

    else if(maxCustomer == 0){
        cout << "no one has purchased any Diapers" << endl;
    }
}
void helperRattles(Customer* maxCustomer){
    if(maxCustomer!=0){
        cout << maxCustomer->name.c_str() << " has purchased the most Rattles (" << maxCustomer->rattles << ")" << endl;
    }

    else if(maxCustomer == 0){
        cout << "no one has purchased any Rattles" << endl;
    }
}


void processSummarize() {
    std::cout << "There are " << num_bottles << " Bottles, " << num_diapers << " Diapers and " << num_rattles << " Rattles in inventory" << endl;
    std::cout << "we have had a total of " << database.size() << " different customers" << endl;

    UTString Bottles = UTString("Bottles");
    UTString Diapers = UTString("Diapers");
    UTString Rattles = UTString("Rattles");

    Customer* bottleMax = findMax(Bottles);
    Customer* diaperMax = findMax(Diapers);
    Customer* rattleMax = findMax(Rattles);

    helperBottles(bottleMax);
    helperDiapers(diaperMax);
    helperRattles(rattleMax);



}

void processInventory() {
    UTString product;
    readString(product);
    int count;
    readNum(count);

    int *point = selectInventItem(product);

    *point += count;



}
