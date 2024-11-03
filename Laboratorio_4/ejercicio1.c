#include <stdio.h>
#include <stdlib.h>

void findlargestLine (int **matrix, int size, int *result) {
    int contador = 0 ;
    int contador_max = 0 ;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(*(matrix + i ) + j ) == 1){
                contador++ ; // Si es 1 lo incrementa en 1. 
            } else {
                if (contador > contador_max){
                    contador_max = contador ;// Vamor actualizando cada vez que sea 0.
                }

                // Necesitamos reiniciar el contador para la siguiente iteracion.
                contador = 0 ;
                }

            }

        }
        // Necesitamos verficar si la ultima iteracion es la mayor.
        if (contador > contador_max){
            contador_max = contador ;
        }

    *result = contador_max ; 
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