//
// Created by Sachin Nair on 6/13/22.
//
#include <stdio.h>
void printMultTableInt(int n);
void printMultTableFrac(int n);
int main(void){
    // You can change this to test your code
    int size = 10;
    printMultTableInt(size);
    printMultTableFrac(size);
    return 0;
}
// Prints multiplication table of integers from 1 to n
void printMultTableInt(int n){
    // WRITE CODE FOR PART A HERE
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            int val = i*j;
            if(j == n){
                printf("%d", val);

            }
            else{
                printf("%d ", val);
            }
        }
        printf("\n");
    }
    printf("\n");

}
// Prints multiplication table for fractions from 1, 1/2, 1/3 to 1/n
void printMultTableFrac(int n){
    // WRITE CODE FOR PART B HERE
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            double denom = i*j;
            double val = 1/denom;
            if(j == n){
                printf("%.2f", val);

            }
            else{
                printf("%.2f ", val);
            }        }
        printf("\n");
    }
    printf("\n");

}