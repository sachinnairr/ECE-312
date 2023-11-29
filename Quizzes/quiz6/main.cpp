#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using  namespace std;
static unordered_map<string, int> variables;

int main(void) {
//this implementation assumes the functions to read the file have been implemented as in project 8

    while(next_token_type!= END){
        String token = next_token();
        if(strcmp(token, "var") == 0){
            varName = next_token();
            varValue = next_token();
            variables[varName] =  varValue;
        }
        elif(strcmp(token, "set")){
            var = next_token();
            varNewValue = next_token();
            variables[var] = varNewValue;
        }
        else
            cout << "variable not declared" << endl;
    }
}

