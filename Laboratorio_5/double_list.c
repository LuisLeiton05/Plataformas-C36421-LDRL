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