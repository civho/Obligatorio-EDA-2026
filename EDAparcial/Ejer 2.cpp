#include <stdio.h>
#include "Ejer 2.h"

struct nodo_arbol{
    int dato;
    arbol padre, ph, sh;
};

int max(int x, int y){
    if (x>y)
        return x;
    else
        return y;
}

int arbol_profundidad(arbol a){
    if(a == NULL)
        return 0;
    else
        return max(1 + arbol_profundidad(a->ph), arbol_profundidad(a->sh));
}

void arbol_imprimir_Rama(arbol a){
    if (a != NULL){
        arbol_imprimir_Rama(a->padre);
        printf("%d ", a->dato);
    }
}

void imprimirRamasMasLargas(arbol a, int prof){
    if (a != NULL){
        if(prof == 0){
            imprimirRamasMasLargas(a->sh, prof);
            arbol_imprimir_Rama(a);
        }else{
            imprimirRamasMasLargas(a->ph, prof--);
            imprimirRamasMasLargas(a->sh, prof);
        }
    }
}

void ramasMasLargas(arbol a){
    int prof = arbol_profundidad(a);
    imprimirRamasMasLargas(a, prof);
}