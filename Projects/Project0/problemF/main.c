//
// Created by Sachin Nair on 6/13/22.
//
#include <stdio.h>
#include <stdlib.h>
int gcd(int x,int y);
int main(void) {
    gcd(48,18);
    gcd(144,60);
    gcd(65,12);
    gcd(179,7);
    return 0;
}

int gcd(int x, int y){
    int gcd;

    for(int i=1; i <= y; i++){
        if(x%i==0 && y%i==0)
            gcd = i;
    }

    printf("%s%d%s%d%s%d \n", "GCD of ", x, " and ", y, " is ", gcd);

}