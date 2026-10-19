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

linea snocLinea(linea l){
    linea aux = new nodo_linea;
    aux->palabra = NULL;
    if(l == NULL){ 
        aux->sig = aux;
        aux->ant = aux;
        l = aux;
    }else {
        aux->sig = l;
        aux->ant = l->ant;
        l->ant->sig = aux;
        l->ant = aux;        
    }
    return l;
}
linea consLinea(linea l) {
     linea aux = new nodo_linea;
    aux->palabra = NULL;
    if(l == NULL){ 
        aux->sig = aux;
        aux->ant = aux;
        l = aux;
    }else {
        aux->sig = l;
        aux->ant = l->ant;
        l->ant->sig = aux;
        l->ant = aux;      
        l=aux;  
    }
    return l;
}

linea borrarLinea(linea l, int x) {
    linea aux = l;
    
    if(l->palabra != NULL){
       l->palabra = NULL;
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

linea antLinea(linea l){
    return l->ant;
}

// devuelve la siguiete linea

