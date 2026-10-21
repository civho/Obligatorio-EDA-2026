#include "palabra.h"
#include "linea.h"
#include "definiciones.h"
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

linea borrarLinea(linea l) {
    
    if(l->palabra != NULL){
       l->palabra = NULL; //Borrar palabra
    }
    if(l->ant != l){ 
        linea aux = l;
        l = aux->sig;
        aux->sig->ant = aux->ant;
        aux->ant->sig = aux->sig;
        delete aux;
    }else {
        delete l;
        return NULL;
    }

    return l;
        
}

linea sigLinea(linea l){
    return l->sig;
}

linea antLinea(linea l){
    return l->ant;
}

bool existeLinea(Posicion contL,Posicion posicionLinea) {
   return contL + 1 >= posicionLinea;
}

linea buscarLinea(linea l, Posicion x){ 
    for(Posicion i = 1; i < x; i++){
			l = sigLinea(l);
		}
        return l;
}

pal obtenerPal(linea l){
    return l->palabra;
}
linea insertarPalenLinea(linea l, pal p) { 
    l->palabra = p;
    return l;
}

