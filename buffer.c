#include "buffer.h"
#include "definiciones.h"

struct nodo_buffer{
    buffer sig, ant;
    Cadena palabra;
};

buffer crearBuffer(){
// crea una nuevo buffer vacio
    buffer b = NULL;
    return b;
}

buffer AgBuffer(buffer b, Cadena pal){
// agrega la ultima plabara al buffer y elimina la primer que del buffer 
    if (b == NULL){    
        b = new(nodo_buffer);
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
            return b;
        }
        else{
            if(iter->sig != b && iter->ant == b ){
            buffer aux = new(nodo_buffer); 
            strcpy(aux->palabra, pal);
            aux->sig = b;
            aux->ant = iter;
            return b; 
            }
        }
        else{
            strcpy(b->palabra, pal);
            b = b->sig;
            return b; 
        }
    }
}
