#include "buffer.h"
#include "definiciones.h"
#include <string.h> 
#include <stdio.h>

struct nodo_buffer{
    buffer sig, ant;
    Cadena palabra;
};

buffer crearBuffer(){
    // Crea una nuevo buffer vacio
    buffer b = NULL;
    return b;
}

buffer SigB(buffer b){
    return b->sig;
}

bool IsEmpty(buffer b){
    return b == NULL;
}

buffer AgBuffer(buffer b, Cadena pal){
    // Agrega la ultima plabara al buffer y si tiene la cantidad maxima palabras remplaza una palabra del buffer 
    if (b == NULL){    
        buffer aux = new(nodo_buffer);
        aux->palabra = new char[strlen(pal) + 1];
        strcpy(aux->palabra, pal);
        aux->sig = NULL;
        aux->ant = NULL;
        return aux;
    }else{
        buffer iter = b;
        int cantT = 1;
        while(iter->sig != NULL){ //llegar al ultimo
            iter = iter->sig;
            cantT++; //cuenta la cantidad de palabras
        }
        if (cantT < MAX_CANT_ULTIMAS_PALABRAS){ // no está lleno
            buffer aux = new(nodo_buffer); 
            aux->palabra = new char[strlen(pal) + 1];
            strcpy(aux -> palabra, pal);
            aux -> sig = b; // agrega la palabara al al buffer en primer lugar
            aux -> ant = NULL;
            b -> ant = aux;    
            return aux;
        }else{
            buffer aux = new(nodo_buffer); 
            aux->palabra = new char[strlen(pal) + 1];
            strcpy(aux -> palabra, pal);
            aux -> sig = b;
            aux -> ant = NULL;
            if (iter->ant != NULL) { 
                iter->ant->sig = NULL;
                b -> ant = aux;
                delete[] iter->palabra;
                delete(iter);
            }else{ // una sola palabra
                aux->sig = NULL; 
                delete[] iter->palabra;
                delete(iter);
            }    
            return aux; 
        }
    }
}

void imprimirBuffer(buffer b){
    printf("%s\n", b->palabra);
}

buffer destruirBuffer(buffer b) {
    if(b == NULL){
        return NULL;
    }else {
        destruirBuffer(b->sig);
        delete[] b->palabra;
        delete b;
        return NULL;
    }
}