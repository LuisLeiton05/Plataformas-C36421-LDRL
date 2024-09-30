#include <stdio.h>

int factorial (int n) {
    int i =1 ;
    while ( n > 1) {
        i = i * n;
        n = n - 1; /*
                    *Hay que quitarle el int, ya que sino se interpreta 
                    *como una nueva variable por lo que no modificaria a 
                    *la original. 
                    */
    }

    return i;
}

int main (int argc, char *argv[]) {
    int fac4 = factorial(4);
    int fac5 = factorial(5);
    printf("4! = %d , 5! = %d \n", fac4, fac5);

    // Se pide un numero a calcularle el factorial.
    int numero ;
    printf("Ingrese el numero al que le desee calcualar el factorial: \n") ;
    scanf("%d", &numero) ;
    printf("\n") ;
    printf("El factorial del %d es: %d \n", numero, factorial(numero)) ;

    return 0;
}