// SuperStrings <Project1.cpp>
// EE 312 Project 1 submission by
// <Sachin Nair>
// <svn343>
// Slip days used: <1>
// Summer 2022
// Copy-paste contents of this file at the top of every .c or .h file that youwrite or modify.
#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <cstdlib>
#define MAX_WORDS 5000;
#define MAX_WORD_LENGTH 19;

/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/

int findLen(char *array){

    if(array == NULL){
        return 0;
    }
    int counter = 0;
    while(*array++ != '\0'){
        counter++;
    }
    return counter;

}
int findLenPointer(char** array){
    int counter = 0;
    while(array[counter] != nullptr){
        counter++;
    }
    return counter;

}


char convertLower(char x){
    if(x >= 'A' && x <= 'Z'){
        x = (x + 32);
    }
    return x;

}
bool isWhiteSpace(char x){
    if(x == ' ' || x == '\t' || x == '\n'){
        return true;
    }
    return false;
}
char** generateArray(char string[], int len) {

    char **words = (char **) calloc(5000,sizeof(char*));
    if(words == NULL){
        printf("%s ", "unable to malloc, try running again");
        exit(1);
    }
    int i = 0;
    int j = 0;


    while (i <len) {

        char *curString = (char *) calloc(20,sizeof(char) );
        if(curString == NULL){
            printf("%s ", "unable to malloc, try running again");
            exit(1);
        }
        int k = 0;

       while (!(isWhiteSpace(string[i]))) {
           curString[k] = string[i];
           i++;
           k++;
           curString[19] = '\0';
       }
       words[j] = curString;

       j++;
       while (isWhiteSpace(string[i])) {
           i++;
       }



   }

    return words;
}
bool isSuperString(char* target, char* candidate){
    int pointer1=0;
    int pointer2=0;
    int len = findLen(target);
    int len2 = findLen(candidate);
    while(pointer1 < len && pointer2 < len2) {
        if (target[pointer1] == candidate[pointer2]) {
            pointer1++;
            pointer2++;
        } else {
            pointer2++;
        }


    }
    //printf("%d\n", pointer1);
    //printf("%d\n", len);

    if(pointer1 == len){
        return true;
    }
    return false;
}





void printSuperStrings(char targets [], char candidates []) {
    int len = findLen(targets);
    int len2 = findLen(candidates);

    for(int i = 0; i <len; i++){
        targets[i] = convertLower(targets[i]);
    }
    for(int i = 0; i < len2; i++){
        candidates[i] = convertLower(candidates[i]);
    }


    char** dict = generateArray(targets, len);
    char** words = generateArray(candidates,len2);

    int len3 = findLenPointer(dict);
    int len4 = findLenPointer(words);


    for(int i = 0; i < len3; i++){
        for(int j = 0; j < len4; j++){
            //printf("%s, ", dict[i]);
            //printf("%s\n",words[j]);

            if(isSuperString(dict[i], words[j])){
                printf("%s\n",words[j]);
                printf("\n");
            }
        }


    }







}


