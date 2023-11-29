// String ADT <Project3.cpp>
// EE 312 Project 3 submission by
// <Sachin Nair>
// <svn343>
// Slip days used: <1>
// Summer 2022
// Copy and paste this file at the top of all your submitted source code files.
// Do not turn this in by itself.

#include <assert.h>     //to provide assert()
#include <stdbool.h>    //to provide "bool" datatype (true or false)
#include <stdlib.h>     //dynamic allocation functions
#include <stdint.h>     //integer datatype with precise explicit width
#include <string.h>     //utility functions for string management
#include "UTString.h"

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(const UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}


/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    int len = strlen(src);
    int counter;
    UTString *newString = (UTString*) malloc(1 * sizeof(UTString));
    newString -> length = len;
    newString -> capacity = len;
    char *point =  (char*) malloc(5+len);

    for(counter = 0; counter < len; counter++) {
        point[counter] = src[counter];
    }

    point[counter+1] = 0;
    newString -> string = point;
    CHECK(newString) = SIGNATURE;
    return newString;
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    assert(isOurs(s));
    return s->length;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) {
    assert(isOurs(s));
    int cap = s->capacity;
    int len = s->length;
    int count = 0;
    while((suffix[count] != 0) && (len+count < cap)) {
        s->string[len+count] = suffix[count];
        count++;
    }
    s->length = len+count;
    s->string[len+count] = 0;
    CHECK(s) = SIGNATURE;
    return s;
}

/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    assert(isOurs(dst));
    int cap = dst->capacity;
    int x = 0;
    while(src[x] != 0 && dst->string[x] != 0) {
        dst->string[x] = src[x];
        x++;
    }
    if(src[x] == 0) {
        while(dst->string[x+1] != 0) {
            dst->string[x+1] = 0;
            x++; //if no work come back to this loop
        }
        dst->length = strlen(src);
    }
    else {
        while(x < cap) {
            if (src[x] != 0) {
                dst->string[x] = src[x];
            }
            x++;
        }
        dst->length = x;
    }
    UTString* s = dst;
    CHECK(s) = SIGNATURE;
    return s;
}

/*
 * Free all memory associated with the given UTString.
 */
void utstrfree(UTString* self) {
    assert(isOurs(self));
    free(self->string);
    free(self);
}

/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    assert(isOurs(s));
    int cap = s->capacity;

    if (cap < new_capacity) {
        char* string2 = (char*) malloc(5+new_capacity);
        strcpy(string2, s->string);
        string2[strlen(s->string)] = 0;

        s->string = string2;
        s->capacity = new_capacity;
        CHECK(s) = SIGNATURE;
        return s;
    }
    CHECK(s) = SIGNATURE;
    return s;
}
