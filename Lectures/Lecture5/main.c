#include <stdio.h>
#include <stdlib.h>
int main() {
    int rows = 3;
    int cols = 10;
    int** matrix = (int**)malloc(rows*sizeof(int*) );
    for(int i = 0; i<rows;i++){
        matrix[i] = (int*)malloc(cols*sizeof(int));
    }

    for(int i = 0; i < rows; i++){
        for (int j = 0; j<rows; j++){
            matrix[i][j] = i*rows+j;
        }
    }
    return 0;
}
