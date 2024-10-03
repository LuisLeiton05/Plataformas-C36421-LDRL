#include<stdio.h>

#define SIZE 5

int findLargestLine(int matrix[][SIZE]) {
   



}

int main (){
    int matrix[SIZE][SIZE] = {
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1}
    };

    int largestLine = findLargestLine(matrix);
    printf("EL tamano de la secuencia de 1s mas grande es: %d \n", largestLine) ;

    return 0;
}

