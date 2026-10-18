#include "linea.h"
#include "definiciones.h"
#include "palabra.h"
#include <stdio.h>

struct nodo_linea {
    linea ant, sig;
    pal palabra;   
};

linea crearLinea(){
    return NULL;
}

linea consLinea(linea l, unsigned int *contl){
    linea aux = new nodo_linea;
    aux->palabra = crearPalabra();
    if(l == NULL){ 
        aux->sig = aux;
        aux->ant = aux;
        l = aux;

    }else if(l->sig == l){
        l->sig = aux;
        l->ant = aux;
        aux->sig = l;
        aux->ant = l;
       
    }else {
            aux->sig = l;
            aux->ant = l->ant->ant;
            l->ant->ant->sig = aux;
            l->ant = aux;        
    }
    //sumar contador
    return l;
}

linea borrarLinea(linea l, int x) {
    linea aux = l;
    
    if(l->palabra != NULL){
        DeleteAllPall(l->palabra);
    }else {
        if(l->ant != l){ 
            linea aux = l;
            aux->ant->sig = aux->sig;
            l->ant = aux->ant;

        }
        
    }
}

linea sigLinea(linea l){
    return l->sig;
}
// devuelve la siguiete linea


