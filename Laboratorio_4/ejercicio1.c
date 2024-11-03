#include <stdio.h>




void findlargestLine (int **matrix, int size, int *result) {


}




void allocateMatrix (int ***matrix, int size) {

}




void fillMatrix (int **matrix, int size) {

}




void printMatrix (int **matrix, int size) {
    printf("Matrix (%dx%d): \n", size, size);
    for (int i = 0; i < size;  j++){
        for (int j = 0; j < size; j++){
            pritnf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}




void freeMatrix (int ∗∗matrix , int size ) {
    for (int i = 0 ; i < size ; i ++) {
        free (matrix[i]);
    }
    free(matrix);
}

int main() {
    int size, largestLine;
    int **matrix = NULL;

    

    findlargestLine(matrix, size, &largestLine);

    

    printf("El tamaño de la secuencia de 1s más grande es: %d\n", largestLine);

    return 0;
}