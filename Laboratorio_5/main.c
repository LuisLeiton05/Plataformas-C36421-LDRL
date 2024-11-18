#include <stdio.h>
#include "double_list.h"

// Definimos algunos valores a usar.
    #define x 190 
    #define y 25 
    #define z 223 

int main() {
    // Inicializamos nuestra lista.
    struct DoubleList lista ;
    inicializar_lista(&lista) ;

    // Insertamos un nodo en la primera posición. 
    printf("Insertar nodo en la primera posicion: \n") ;
    nodo_al_inicio(&lista, x) ;
    nodo_al_inicio(&lista, y) ;
    printf("La lista actual es: \n") ;
    imprimir_hacia_adelante(&lista);
    printf("La lista con el nuevo nodo es: \n") ;
    nodo_al_inicio(&lista, z) ;

    printf("\n");

    // Insertamos un nodo al final.
    printf("Insertar nodo en la última posicion. \n ") ;
    printf("La lista actual es: \n") ;
    imprimir_hacia_adelante(&lista) ;
    printf("La lista con el nuevo nodo al final es: \n") ;
    nodo_al_final (&lista, x) ;

    printf("\n");

    // Insertamos un nodo en una posición específica.
    printf("Insertar un nodo en una posición específica. \n") ;
    printf ("Será el 190 en la segunda posición: \n") ;
    printf("La lista actual es: \n") ;
    imprimir_hacia_adelante(&lista) ;
    printf("La lista anadiendo un 190 en la segunda posición. \n");
    nodo_en_cierta_posicion(&lista, 1, x) ;

    printf("\n");

    // Eliminar un nodo basado en la data.
    printf("Eliminar un nodo basado en la data: \n") ;
    printf("La lista actual es: \n") ;
    imprimir_hacia_adelante(&lista) ;
    printf("La lista después de eliminar 25: \n") ;
    eliminar_nodo (&lista, y) ;



    // Buscar un elemento a partir de su data.
    printf("Buscar un elemento a partir de su data. \n") ;
    printf ("Buscamos primero el 15 y luego el 190. \n") ;
    printf("La lista actual es: \n") ;
    imprimir_hacia_adelante(&lista) ;

    struct Node *primero = buscar_nodo(&lista, 15) ;
    struct Node *segundo = buscar_nodo(&lista, x) ;

    if (primero != NULL) {
        printf("Elemento encontrado: %d\n", primero->data) ;
    } else {
        printf("Elemento no encontrado.\n") ;
    }

    if (segundo != NULL) {
        printf("Elemento encontrado: %d\n", segundo->data) ;
    } else {
        printf("Elemento no encontrado.\n");
    }

    printf("\n");

    // Recorrer hacia adelante  la lista e imprimirla.
    printf("Recorrer hacia adelante la lista e imprimirla. \n") ;
    imprimir_hacia_adelante (&lista) ;

    printf("\n");

    // Recorrerla hacia atrás la lista e imprimirla.
    printf("Recorrerla hacia atrás la lista e imprimirla. \n") ;
    imrpimir_hacia_atrás(&lista) ;


    return 0 ;
}