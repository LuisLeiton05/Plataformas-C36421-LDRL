#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

// Los datos serán números.
// Estrcutura de cada nodo.
typedef struct Node {
    int data ;
    struct Node * previo ;
    struct Node * siguiente ;
} Node ;

typedef struct  DoubleList {
    struct Node * inicio ;
    struct Node * final ;

} DoubleList ;


// Funciones:
void inicializar_lista (struct DoubleList * lista) ;
void nodo_al_inicio (struct DoubleList * lista, int data) ; 
void nodo_al_final (struct DoubleList * lista, int data) ;
void nodo_en_cierta_posicion (struct DoubleList *lita, int indice,  int data) ;
void eliminar_nodo (struct DoubleList * lista, int data) ;
// Esta funcion necesitamos que devuelva un valor.
struct Node* buscar_nodo (struct DoubleList * lista, int data) ;
void imprimir_hacia_adelante (struct DoubleList * lista) ;
void imprimir_hacia_atras (struct DoubleList * lista) ;
void liberar (struct DoubleList * lista) ;

#endif 