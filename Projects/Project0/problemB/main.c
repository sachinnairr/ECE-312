//
// Created by Sachin Nair on 6/11/22.
//
#include <stdio.h>
#include <assert.h>
#define SIZE 26
int are_anagrams(char[], char[]);
int main() {
    printf("running test 'iceman' and 'cinema'...\n");
    char iceman[] = "iceman";
    char cinema[] = "cinema";
    assert(are_anagrams(iceman, cinema));
    printf("passed!\n");
    printf("running test 'raganam' and 'anagram'...\n");
    char raganam[] = "raganam";
    char anagram[] = "anagram";
    assert(are_anagrams(raganam, anagram));
    printf("passed!\n");

    printf("running test 'listen' and 'silent'...\n");
    char listen[] = "listen";
    char silent[] = "silent";
    assert(are_anagrams(listen, silent));
    printf("passed!\n");
    printf("running test 'mole' and 'meal'...\n");
    char mole[] = "mole";
    char meal[] = "meal";
    assert(!are_anagrams(mole, meal));
    printf("passed!\n");
    printf("running test 'happy' and 'sad'...\n");
    char happy[] = "happy";
    char sad[] = "sad";
    assert(!are_anagrams(happy, sad));
    printf("passed!\n");
}
int are_anagrams(char first_word[], char second_word[]) {

    int bucket[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int counter = 0;
    while(first_word[counter] != '\0'){
        int pos = first_word[counter] - 96;
        bucket[pos]+=1;
        counter++;
    }
    counter = 0;
    while(second_word[counter] != '\0'){
        int pos = second_word[counter] - 96;
        bucket[pos]-=1;
        counter++;
    }
    for(int i = 0; i < 26; i++){
        if(bucket[i] != 0){
            return 0;
        }
    }
    return 1;
}
