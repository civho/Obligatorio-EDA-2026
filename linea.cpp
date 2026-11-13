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
    if(l == NULL){ 
        linea aux = new nodo_linea;
        aux->palabra = NULL;
        aux->sig = aux;
        aux->ant = aux;
        l = aux;
        return l;
    }else {
        linea aux = new nodo_linea;
        aux->palabra = NULL;
        aux->sig = l;
        aux->ant = l->ant;
        l->ant->sig = aux;
        l->ant = aux;      
        l=aux;  
        return l;
    }
    return l;
}

linea borrarLinea(linea l) {
    
    if(l->palabra != NULL){
       l->palabra = DeleteAllPal(l->palabra); //Borrar palabra
    }
    if(l->ant != l){ 
        linea aux = l; // guarda l para borrarlo
        l = aux->sig; // mueve l un nodo
        aux->sig->ant = aux->ant; // le da al valor "ant" del nodo siguiente (que es  l) el valor "ant" del nodo actual
        aux->ant->sig = aux->sig; // le da al valor "sig" del nodo anterior el valor "sig" de aux
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
   return contL >= posicionLinea;
}

linea buscarLinea(linea l, Posicion x){
    if(l == NULL) {
        return NULL;
    }
    if(x > 1){
        for(Posicion i = 1; i < x; i++){
                l = sigLinea(l);
            }
            
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

void imprimirLinea(linea l, Posicion x){ 
    linea aux = l;
            printf("%d: ", x);
            ImprimirPal(aux->palabra);
            printf("\n");
            aux = aux->sig;
    
}

