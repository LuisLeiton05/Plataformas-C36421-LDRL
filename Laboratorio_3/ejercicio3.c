#include<stdio.h>

#define SIZE 5

int findLargestLine(int matrix[SIZE][SIZE]) {
    // Recorrer la matriz y sumar 1 por cada 1 que encuentre.
    int contador_max = 0 ;
    int contador = 0 ;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 1){
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

    return contador_max ;

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

