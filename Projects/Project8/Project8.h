//
// Created by Sachin Nair on 8/8/22.
//

#ifndef PROJECT8_PROJECT8_H
#define PROJECT8_PROJECT8_H
#include "Parse.h"
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;
bool isOperation(string string);
int operation(string operation, int input1, int input2);
void text();
void initialize();
void set();
bool isValid(string peek);
void parse();
int recursiveInterpreter(vector<string>& vector);
void clear(vector<string> list);
void stop(map<string,int> map);
void run();

#endif
