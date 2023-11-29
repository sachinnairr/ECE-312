// CRM <Project4.cpp>
// EE 312 Project 4 submission by
// Sachin nair
// svn343
// Slip days used: <0>
// Summer 2022
// Copy-Paste the above lines at the top of your submitted files.


#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"
#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;


Customer store;


/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */


Customer* createCustomer(String name){
    if (num_customers < MAX_CUSTOMERS) {
        Customer* create = customers+num_customers;
        String s = StringDup(&name);
        (*create).bottles = 0;
        (*create).diapers = 0;
        (*create).rattles = 0;
        (*create).name = s;
        num_customers++;
        return create;
    }
    return 0;
}

Customer* findCustomer(String name) {
    Customer* location;
    for(int i = 0; i < num_customers; i++){
        if (StringIsEqualTo(&customers[i].name, &name)==true) {
            location = customers+i;
            return location;
        }
    }
    return createCustomer(name);
}


void reset(void) {
    for(int i = 0; i < num_customers; i++){
        customers[i].bottles = 0;
        customers[i].diapers = 0;
        customers[i].rattles = 0;
        StringDestroy(&customers[i].name);
    }

    store.diapers = 0;
    store.bottles = 0;
    store.rattles = 0;
    num_customers = 0;
}

void processSummarize() {
    printf("There are %d Bottles, %d Diapers and %d Rattles in inventory\n",store.bottles, store.diapers, store.rattles);
    printf("we have had a total of %d different customers\n", num_customers);

    int maxBottles = 0;
    int maxDiapers = 0;
    int maxRattles = 0;

    int maxBottlesIndex = -1;
    int maxDiapersIndex = -1;
    int maxRattlesIndex = -1;

    for (int i = 0; i < num_customers; i++) {
        if (customers[i].bottles > maxBottles) {
            maxBottlesIndex = i;
            maxBottles = customers[i].bottles;
        }
        if (customers[i].diapers > maxDiapers) {
            maxDiapersIndex = i;
            maxDiapers = customers[i].diapers;
        }
        if (customers[i].rattles > maxRattles) {
            maxRattlesIndex = i;
            maxRattles = customers[i].rattles;
        }
    }
    if(maxBottlesIndex == -1) {
        printf("no one has purchased any Bottles\n");
    }
    else {
        StringPrint(&customers[maxBottlesIndex].name);
        printf(" has purchased the most Bottles (%d)\n", customers[maxBottlesIndex].bottles);
    }
    if(maxDiapersIndex == -1) {
        printf("no one has purchased any Diapers\n");
    }
    else {
        StringPrint(&customers[maxDiapersIndex].name);
        printf(" has purchased the most Diapers (%d)\n", customers[maxDiapersIndex].diapers);
    }
    if(maxRattlesIndex == -1) {
        printf("no one has purchased any Rattles\n");
    }
    else {
        StringPrint(&customers[maxRattlesIndex].name);
        printf(" has purchased the most Rattles (%d)\n", customers[maxRattlesIndex].rattles);
    }
}

void processPurchase() {
    String customerName;
    String items;
    int order;
    String bottles = StringCreate("Bottles");
    String rattles = StringCreate("Rattles");
    String diapers = StringCreate("Diapers");

    readString(&customerName);
    readString(&items);
    readNum(&order);


    if(order < 0) {
        StringDestroy(&customerName);
        return;
    }

    if(StringIsEqualTo(&items,&bottles) && store.bottles < order) {
        printf("Sorry ");
        StringPrint(&customerName);
        printf(", we only have %d Bottles\n", store.bottles);
        StringDestroy(&customerName);
        return;
    }
    else if(StringIsEqualTo(&items,&diapers) && store.diapers < order) {
        printf("Sorry ");
        StringPrint(&customerName);
        printf(", we only have %d Diapers\n", store.diapers);
        StringDestroy(&customerName);
        return;
    }
    else if(StringIsEqualTo(&items,&rattles) && store.rattles < order) {
        printf("Sorry ");
        StringPrint(&customerName);
        printf(", we only have %d Rattles\n", store.rattles);
        StringDestroy(&customerName);
        return;
    }
    else
        StringDestroy(&customerName);

    Customer* consumer = findCustomer(customerName);

    if(StringIsEqualTo(&items,&bottles)) {
        consumer->bottles += order;
        store.bottles -= order;
    }
    else if(StringIsEqualTo(&items,&diapers)) {
        consumer->diapers += order;
        store.diapers -= order;
    }
    else if(StringIsEqualTo(&items,&rattles)) {
        consumer->rattles += order;
        store.rattles -= order;
    }


    StringDestroy(&items);
    StringDestroy(&bottles);
    StringDestroy(&diapers);
    StringDestroy(&rattles);

}


void processInventory() {
    String items;
    int num;
    String bottles = StringCreate("Bottles");
    String rattles = StringCreate("Rattles");
    String diapers = StringCreate("Diapers");

    readString(&items);
    readNum(&num);

    if(num < 0) {
        StringDestroy(&items);
        return;
    }

    if(StringIsEqualTo(&items,&bottles)) {
        store.bottles += num;
    }
    else if(StringIsEqualTo(&items,&diapers)) {
        store.diapers += num;
    }
    else if(StringIsEqualTo(&items,&rattles)){
        store.rattles += num;
    }
    else
        printf("Select a valid item");

    StringDestroy(&bottles);
    StringDestroy(&diapers);
    StringDestroy(&rattles);
    StringDestroy(&items);
}