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
    imprimir_hacia_adelante (&lista) ;

    printf("\n");

    // Insertamos un nodo al final.
    printf("Insertar nodo en la última posicion. \n ") ;
    printf("La lista actual es: \n") ;
    imprimir_hacia_adelante(&lista) ;
    printf("La lista con el nuevo nodo al final es: \n") ;
    nodo_al_final (&lista, x) ;
    imprimir_hacia_adelante(&lista) ;

    printf("\n");

    // Insertamos un nodo en una posición específica.
    printf("Insertar un nodo en una posición específica: \n") ;
    printf ("Será el 190 en la segunda posición. \n") ;
    printf("La lista actual es: \n") ;
    imprimir_hacia_adelante(&lista) ;
    printf("La lista anadiendo un 190 en la segunda posición: \n");
    nodo_en_cierta_posicion(&lista, 1, x) ;
    imprimir_hacia_adelante(&lista) ;

    printf("\n");

    // Eliminar un nodo basado en la data.
    printf("Eliminar un nodo basado en la data: \n") ;
    printf("La lista actual es: \n") ;
    imprimir_hacia_adelante(&lista) ;
    printf("La lista después de eliminar 25: \n") ;
    eliminar_nodo (&lista, y) ;
    imprimir_hacia_adelante (&lista) ;

    printf("\n");

    // Buscar un elemento a partir de su data.
    printf("Buscar un elemento a partir de su data: \n") ;
    printf ("Buscamos primero el 15 y luego el 190. \n") ;
    printf("La lista actual es: \n") ;
    imprimir_hacia_adelante(&lista) ;

    struct Node *num1 = buscar_nodo(&lista, 15) ;
    struct Node *num2 = buscar_nodo(&lista, x) ;

    if (num1 != NULL) {
        printf("Elemento encontrado: %d\n", num1->data) ;
    } else {
        printf("Elemento no encontrado: 15.\n") ;
    
    }
    if (num2 != NULL) {
        printf("Elemento encontrado: %d\n", num2->data) ;
    } else {
        printf("Elemento no encontrado: 190 \n");
    }

    printf("\n");

    // Recorrer hacia adelante  la lista e imprimirla.
    printf("Recorrer hacia adelante la lista e imprimirla: \n") ;
    imprimir_hacia_adelante (&lista) ;

    printf("\n");

    // Recorrerla hacia atrás la lista e imprimirla.
    printf("Recorrerla hacia atrás la lista e imprimirla: \n") ;
    imprimir_hacia_atras(&lista) ;


    // Liberamos la memoria recorriendo la lista.
    liberar (&lista) ;

    return 0 ;
}