//
// Created by Sachin Nair on 8/1/22.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Parse.h"
#include <map>
using namespace std;

int operation(string s, int x, int y);
void run();
void clear(vector<string> list);
void stop(map<string, int> map);
void text();
void initialize();
void set();
void parse();
int recursiveInterpreter(vector<string>& vector);
bool isValid(string str);


map<string, int> variables;
vector<string> list;

bool isOperation(string op){
    if(op == "&&" || op == "||"  || op == "!" || op == "~" || op == "+" || op == "-" || op == "*" || op == "/" || op == "%" ||  op == "<" ||  op == "<=" || op == ">" || op == ">=" || op == "==" || op == "!=")
        return true;
    else
        return false;
}
int operation(string operation, int input1, int input2){

    if (operation == "&&")
        return (input1 && input2);
    else if (operation == "||")
        return (input1 || input2);
    else if (operation == "+")
        return (input1 + input2);
    else if (operation == "-")
        return (input1 - input2);
    else if (operation == "*")
        return (input1 * input2);
    else if (operation == "/")
        return (input1 / input2);
    else if (operation == "%")
        return (input1 % input2);
    else if (operation == "==")
        return (input1 == input2);
    else if (operation == "<")
        return (input1 < input2);
    else if (operation == "<=")
        return (input1 <= input2);
    else if (operation == ">")
        return (input1 > input2);
    else if (operation == ">=")
        return (input1 >= input2);
    else if (operation == "!=")
        return (input1 != input2);
}

void text(){
    read_next_token();
    cout << next_token();
}

void initialize(){
    read_next_token();
    string variable = next_token();

    parse();
    //if variable does not exist, add it to map
    if (variables.find(variable) == variables.end())
        variables[variable] = recursiveInterpreter(list);
    //if variable does exist print error
    else
        cout << "variable " << variable << " incorrectly re-initialized" << endl;



    clear(list);
}

void set(){

    read_next_token();
    string variable = next_token();

    parse();
    //check that variable already exists
    if (variables.find(variable) != variables.end())
        variables[variable] = recursiveInterpreter(list);
    //if it doesnt exist already, return error
    else
        cout << "variable "<< variable << " not declared" << endl;

    clear(list);
}

bool isValid(string peek){
    if(peek != "text" && peek != "output" && peek != "var" && peek != "set")
        return true;
    return false;
}

void parse(){

    string peek = peek_next_token();
    //while not at the end of file and not inputing a command
    while(next_token_type != END && isValid(peek)){
        read_next_token();

        string token = next_token();
        //check if token is commenting out the line
        if (token == "//")
            skip_line();
        //add token to the vector
        list.push_back(token);
        //increment peek to next token
        peek = peek_next_token();
    }

}

int recursiveInterpreter(vector<string>& vector){
    string first = vector.front();

    if (variables.find(first) != variables.end()){
        vector.erase(vector.begin());
        return variables[first];
    }

    if (isOperation(first) == false){
        vector.erase(vector.begin());
        return stoi(first);
    }
    if (first == "~" ){
        vector.erase(vector.begin());
        int returnVal = recursiveInterpreter(vector);
        returnVal *= -1;
        return returnVal;

    }
    if(first == "!"){
        vector.erase(vector.begin());
        int returnVal = recursiveInterpreter(vector);
        if (returnVal != 0)
            return false;

        else if (returnVal == 0)
            return true;
    }
    if (first != "!"){
        vector.erase(vector.begin());
        return operation(first, recursiveInterpreter(vector), recursiveInterpreter(vector));
    }


}
void clear(vector<string> list){
    list.clear();
}
void stop(map<string, int> map){
    map.clear();
}

void run(){
    while(next_token_type != END){

        string token = next_token();

        if (token == "//")
            skip_line();

        else if(token == "var"){

            initialize();
            continue;
        }
        else if (token == "set"){

            set();
            continue;
        }
        else if (token == "text"){

            text();
            continue;
        }
        else if (token == "output"){

            parse();
            cout << recursiveInterpreter(list);
            clear(list);
        }
        read_next_token();
    }
    stop(variables);
}

