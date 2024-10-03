#include<stdio.h>
// Agregamos stdlib para poder usar rand.
#include<stdlib.h>

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
    printf("EL tamano de la secuencia de 1s mas grande es: %d (ejemplo) \n", largestLine) ;
    printf("\n");

    // Utilizando rand creamos, y rellenamos una matriz binaria y cuadrada.
    int numero = (rand() %7) +5; // Cambiando ese valor sumando, cambia la matriz.
    int filas = numero ;
    int columnas = numero ;

    // Declaramos la matriz (max 5x5, pero puede cambiarse), rellenamos e imrpimimos.
    int matriz [filas][columnas];

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = (rand() %2) ; // %2 le da numero enteros entre 0 y 1, es decir hace una matriz binaria.
        }

    }

    printf("La matriz a usar es: \n") ;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]) ;
        }
        printf("\n");  

    }

    printf("\n");

    // Hacemos el conteo para esta nueva matriz.
     int largestLine2 = findLargestLine(matriz);
    printf("EL tamano de la secuencia de 1s mas grande en esta nueva matriz es: %d \n ", largestLine2) ;
    return 0;
}

