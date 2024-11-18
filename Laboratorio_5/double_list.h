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
    struct Node * inicio ;
    struct Node * final ;

} ;


// Funciones:
void inicializar_lista (struct DoubleList * lista) ;
void nodo_al_inicio (struct DoubleList * lista) ; 
void nodo_al_final (struct DoubleList * lista, int data) ;
void nodo_en_cierta_posicion (struct DoubleList *lita, int indice,  int data) ;
void eliminar_nodo (struct DoubleList * lista, int data) ;
// Esta funcion necesitamos que devuelva un valor.
struct Node* buscar_nodo (struct DoubleList lista, int data) ;
void imprimir_hacia_adelante (struct DoubleList * lista, int data) ;
void imrpimir_hacia_atrás (struct DoubleList * lista, int data) ;

#endif 