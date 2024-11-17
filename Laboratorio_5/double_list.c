#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Primer se inicializa la lista.
void inicializar_lista (DoubleList * lista) {
    lista -> inicio = NULL ;
    lista -> final = NULL ;
}

// Función para insertar nodo al inicio.
void nodo_inicio (struct DoubleList * lista, int data) {
    Node * nuevo_nodo = (Node *)malloc(sizeof(Node));
    
}