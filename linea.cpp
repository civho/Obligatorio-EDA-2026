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

    }else if(l->sig != l){
        linea recorre = l;
        while(recorre->sig != l){
            recorre = recorre->sig;
        }
        l->ant->sig = aux; 
        aux->ant = l->ant;
        aux->sig = l;
        l->ant = aux;

       
    }else {
        aux->sig = l;
        aux->ant = l; 
        l->sig = aux;
        l->ant = aux;
        
        
    }
    //sumar contador
    return l;
}

linea borrarLinea(linea l, int pos) {
    int contador = 3;
    if(l == NULL){
        return NULL; 
    }else if(l->sig != l){
        while(l->sig != l){ 
            if(contador >= pos) { 

            }
        }
    }
    
}

linea sigLinea(linea l);
// devuelve la siguiete linea


