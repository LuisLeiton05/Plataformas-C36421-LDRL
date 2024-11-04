#include <stdio.h>
#include <stdlib.h>

// Cuenta las filas de 1s.
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

// Reserva, en memoria dinámica, el espacio para nuestra matriz.
void allocateMatrix (int ***matrix, int size) {
    // (int **) es para reservar memoria a un arreglo de punteros, varios de ellos.
    *matrix = (int **)malloc(size * sizeof(int *)) ;
    // Caso en el que no encontró espacio.
    if (*matrix == NULL) {
        printf("Error: No se pudo asignar la memoria para la matriz. \n") ;
        return ;
    }

    // Reservamos la memoria para cada una de las fila.
    for (int i = 0; i < size; i++) {
        (*matrix)[i] = (int *)malloc(size * sizeof(int));
        // Caso en el que no encuentra espacio.
        if ( (*matrix)[i] == NULL) {
        printf("Error: No se pudo asignar la memoria para alguna fila de la matriz. \n") ;
        return ;
        }
    }
}       

// Rellena nuestra matriz con 1s y 0s.
void fillMatrix (int **matrix, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(matrix + i ) + j ) = (rand() %2) ; // %2 le da numero enteros entre 0 y 1, es decir hace una matriz binaria.
        }
    }
}



// Imprimir nuestra matriz binaria.
void printMatrix (int **matrix, int size) {
    printf("Matrix (%dx%d): \n", size, size);
    for (int i = 0; i < size;  i++){
        for (int j = 0; j < size; j++){
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}



// Liberar memoria asignada previamente.
void freeMatrix (int **matrix , int size ) {
    for (int i = 0 ; i < size ; i ++) {
        free (matrix[i]);
    }
    free(matrix);
}

// Función de la matriz transpuesta.
void transpuestaMatrix (int **matrix, int size, int *** transpuesta) {
    // Reservamos el espacio de esta nueva matriz.
    allocateMatrix(transpuesta, size) ;
    if (*transpuesta == NULL) {
        printf("Error al asignar memoria para la transpuesta.\n");
        return;
    }
    // Recorrerla y transponer a la anterior.
    for (int i = 0; i < size;  i++){
        for (int j = 0; j < size; j++){
        *(*(*transpuesta + j) + i) = *(*(matrix + i) + j) ;
        }
    }
}

int main() {
    int size, largestLine1, largestline2 ;
    int **matrix = NULL;

    printf("Ingrese un número para definir el tamaño de la matriz: \n") ;
    scanf("%d", &size) ;

    
    allocateMatrix(&matrix, size) ;
    fillMatrix(matrix,size) ;
    printf("La matriz original es: \n");
    printMatrix(matrix, size) ;
    findlargestLine(matrix, size, &largestLine1);
    printf("El tamaño de la secuencia de 1s más grande es: %d\n", largestLine1);

    // Lógica para la matriz transpuesta.
    int **transpuesta = NULL ;
    transpuestaMatrix(matrix, size, &transpuesta) ;
    printf("La matriz transpuesta es: \n");
    printMatrix(transpuesta, size);
    findlargestLine(transpuesta, size, &largestline2);
    printf("El tamaño de la secuencia de 1s más grande en la transpuesta es: %d\n", largestline2);


    // Liberamos la memoria.
    freeMatrix(transpuesta, size) ;
    freeMatrix(matrix, size) ;

    return 0;
}