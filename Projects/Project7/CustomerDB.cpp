// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Sachin Nair
// SVN343
// Slip days used: <1>
// Summer 2022
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here
    int len = this->length;
    int cap = this->capacity;
    //if customer is in the data base, parse through and return
    if(isMember(name)) {
        for(int i = 0; i < len; i++) {
            if(this->data[i].name.operator==(name)) {
                return this->data[i];
            }
        }
    }
    else {
        if(len == cap) { //if data base is full, doubble the capacity.
            Customer* addData = new Customer[2 * cap];
            this->capacity = 2 * cap;
            for(int i = 0; i < len; i++) {
                addData[i] = this->data[i];
            }
            delete[] this->data;
            this->data = addData;
        }
        //if not in database and there is capacity, create a customer and add it
        Customer addCust(name);
        this->data[len] = addCust;
        this->length = len + 1;
        return this->data[len];
    }
}

bool CustomerDB::isMember(UTString name) { // not done, your effort goes here
    int len = this->length;
    //check if customer is in the data base and return boolean
    for(int i = 0; i < len; i++) {
        if(this->data[i].name == name)
            return true;
    }
    return false;
}
