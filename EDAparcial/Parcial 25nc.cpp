#include <stdio.h>
#include <strings.h>
#include "Parcial 25nc.h"
//Ejer 1
//b
struct nodo_queue{
    cola primero, ultimo;
    unsigned suma, cantidad;
};

struct nodo_cola{
    unsigned dato;
    cola sig; 
};

cola cola_crear(){
    return NULL;
} 

cola cola_encolar(cola c, unsigned x){
}

cola cola_decencolar(cola c){

}

queue queue_crea(){
    queue aux = new nodo_queue;
    aux->primero = cola_crear();
    aux->ultimo = cola_crear();
    aux->cantidad = 0;
    aux->suma = 0;
    return aux; 
}

queue queve_enqueve(queue q, unsigned int x){
    cola aux = new nodo_cola;
    aux->dato = x;
    aux->sig = NULL;
    if (q->primero == NULL && q->ultimo == NULL){
        q->primero = aux;
        q->ultimo = aux;
        q->suma ++;
    }else{
        q->ultimo->sig = aux;
        q->ultimo = aux;
        q->suma += aux->dato;
        q->cantidad++;
    }
    return q;
}

queue queve_dequeve(queue q){
    if(q->primero == q->ultimo){
        delete (q->primero);
        q->primero = NULL;
        q->ultimo = NULL;
        q->suma = 0;
        q->cantidad = 0;
    }else{
        cola borrar = q->primero;
        q->primero = q->primero->sig;
        q->suma -= q->primero->dato;
        q->cantidad --;
        delete borrar;
    }
    return q;
}

bool queve_isEmpty(queue q){
    return q == NULL;
}


