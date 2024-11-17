#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Primer se inicializa la lista.
void inicializar_lista (struct DoubleList * lista) {
    lista -> inicio = NULL ;
    lista -> final = NULL ;
}

// Función para insertar nodo al inicio.
void nodo_al_inicio (struct DoubleList * lista, int data) {
    struct Node * nuevo_nodo = (struct Node *)malloc(sizeof(struct Node));
    nuevo_nodo -> data = data ;
    nuevo_nodo -> previo = NULL ;
    nuevo_nodo -> siguiente = lista->inicio;

    // Revisamos si estamos insertando al inicio.
    if (lista->inicio != NULL) {
        lista->inicio->previo = nuevo_nodo;
    }
    else {
        lista->final = nuevo_nodo ; // Por si está vacia, este sería también el final.
    }

    lista->inicio = nuevo_nodo ; 
}

// Función para insertar nodo al final.
void nodo_al_final (struct DoubleList * lista, int data) {
    struct Node * nuevo_nodo = (struct Node *)malloc(sizeof(struct Node));
    nuevo_nodo -> data = data ;
    nuevo_nodo -> previo = lista->final ;
    nuevo_nodo -> siguiente = NULL;

    // Revisamos si estamos insertando al final.
    if (lista->final != NULL) {
        lista->final->siguiente = nuevo_nodo;
    }
    else {
        lista->inicio = nuevo_nodo ; // Por si está vacia, este sería también el inicial.
    }

    lista->final = nuevo_nodo ; 
}

// Función para insertar nodo en posición específica.
void nodo_en_cierta_posicion (struct DoubleList * lista, int indice, int data) {
    if (indice == 0){
        nodo_al_inicio(lista, data) ;
    }

    struct Node * actual = lista->inicio ;
    int i = 0 ;
 
    // Iteramos para encontrar la posicion.
    while ( actual != NULL && i < indice - 1 ){
        actual = actual->siguiente ;
    }

    // Revisemos que está en el rango.
    if ( actual == NULL ) {
        printf("La lista no contiene tantos elementos (fuera de rango). \n") ;
    }

    // Creamos el nodo nuevo.
    struct Node * nuevo_nodo = (struct Node *)malloc(sizeof(struct Node));
    nuevo_nodo -> data = data ;
    nuevo_nodo -> previo = actual ;
    nuevo_nodo -> siguiente = actual->siguiente;

    // Revisamos si estamos insertando al final.
    if (actual->siguiente != NULL) {
        actual->siguiente->previo = nuevo_nodo;
    }
    else {
        lista->final = nuevo_nodo ;
    }

    actual->siguiente = nuevo_nodo ; 

}