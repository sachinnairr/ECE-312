#include <iostream>
#include <math.h>

using namespace std;

struct Player{
    double statistic;
    string name;
    Player(){};
    Player(string name, double stat);
    void print(){
        cout << name << "(" << statistic << ")" << endl;
    }
};

struct Team{
    string name;
    size_t size;
    Player players [10000];
    Team(){
        name = "";
        size=0;
    }
    void operator+=(Player* player);
};

int main(){

}