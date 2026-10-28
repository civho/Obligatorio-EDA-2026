#include "buffer.h"
#include "definiciones.h"
#include <stdio.h>
#include <string.h> 

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
        aux->palabra = new char;
        strcpy(aux->palabra, pal);
        aux->sig = NULL;
        aux->ant = NULL;
        return aux;
    }else{
        buffer iter = b;
        int cantT = 1;
        while(iter->sig != NULL){
            iter = iter->sig;
            cantT++;
        }
        if (cantT < MAX_CANT_ULTIMAS_PALABRAS){
            buffer aux = new(nodo_buffer); 
            aux->palabra = new char;
            strcpy(aux -> palabra, pal);
            aux -> sig = b;
            aux -> ant = NULL;
            b -> ant = aux;    
            return aux;
        }else{
            buffer aux = new(nodo_buffer); 
            aux->palabra = new char;
            strcpy(aux -> palabra, pal);
            aux -> sig = b;
            aux -> ant = NULL;
            if (iter->ant != NULL) {
                iter->ant->sig = NULL;
                b -> ant = aux;
                delete(iter);
            }else{
                aux->sig = NULL; 
                delete(iter);
            }    
            return aux; 
        }
    }
}

void imprimeirBuffer(buffer b){
    printf("%s\n", b->palabra);
}
