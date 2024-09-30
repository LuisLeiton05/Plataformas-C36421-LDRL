// Codigo para la suma de las diagonales de una matriz.
#include <stdio.h>
// Se agrega para poder usar rand y que sea aleatoria la matriz (es recomendado en el tecer ejercicio).
#include <stdlib.h>

int main () {
    // Definimos una matriz con tamano cuadrado.
    int numero = (rand() %5) +1; // Cambiando ese valor sumando, cambia la matriz.
    int filas = numero ;
    int columnas = numero ;

    // Declaramos la matriz (max 5x5, pero puede cambiarse), rellenamos e imrpimimos.
    int matriz [filas][columnas];

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = (rand() %10) + 1 ;
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


    // Hago una funcion para la suma.
    int suma_diagonales (int matriz[filas][columnas], int numero) {
            // Variables que van a guardar la suma de cada diagnoal.
            int d1 = 0 ;
            int d2 = 0 ;

            for (int k = 0; k < numero; k++) {
                d1 += matriz[k][k] ;
                d2 += matriz [k][numero -k -1] ;
    
             }

            return d1 + d2 ;

    }

    
    printf("La suma de las diagonales es: %d \n", suma_diagonales(matriz, numero) ) ;
    return 0 ;
    }