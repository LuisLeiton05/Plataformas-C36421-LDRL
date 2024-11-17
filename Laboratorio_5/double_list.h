#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

// Los datos serán números.
// Estrcutura de cada nodo.
typedef struct Node {
    int data ;
    struct Node * previo ;
    struct Node * siguiente ;
} ;

typedef struct  DoubleList {
    Node * inicio ;
    Node * final ;

} ;


// Funciones:
void inicializar_lista (DoubleList * lista) ;
void nodo_al_inicio (DoubleList * lista, int data) ; 
void nodo_al_final (DoubleList * lista, int data) ;
void nodo_en_cierta_posicion (DoubleList *lita, int indice, int data) ;
void eliminar_nodo (DoubleList * lista, int data) ;
// Esta funcion necesitamos que devuelva un valor, por eso no es void.
Node* buscar_nodo (DoubleList lista, int data) ;
void imprimir_hacia_adelante (DoubleList * lista, int data) ;
void imrpimir_hacia_atrás (DoubleList * lista, int data) ;



#endif 