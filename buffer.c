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

buffer AgBuffer(buffer b, Cadena pal){
// Agrega la ultima plabara al buffer y si el esta lleno remplaza la palabra por una del buffer 
    if (b == NULL){    
        b = new(nodo_buffer);
        b->sig = b;
        b->ant = b;
        strcpy(b->palabra, pal);
        return b;
    }
    else{
        buffer iter = b;
        if (iter->sig == b && iter->ant == b ){
            buffer aux = new(nodo_buffer); 
            strcpy(aux->palabra, pal);
            aux->sig = b;
            aux->ant = b;
            b->sig = aux;
            b -> ant = aux;
            return b;
        }
        else{
            iter = iter -> sig;
            if(iter->sig != b && iter->ant == b ){
                buffer aux = new(nodo_buffer); 
                strcpy(aux -> palabra, pal);
                aux->sig = b;
                aux->ant = iter;
                iter->sig = aux;
                b -> ant = aux;
                return b; 
            }
            else{
                strcpy(b -> palabra, pal);
                b = b->sig;
                return b; 
            }
        }
    }
}
