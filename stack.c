#include "stack.h"
#include <stdio.h>
#include <string.h>

struct nodo_stack {
    int dato;
    stack sig;
};

stack crear(){
//Crea un stack vacio
    return NULL;
}

stack push(stack s,int x){
//Agrega el elemento x al stack; coloca el elemento x en el top del stack
    stack aux = new(nodo_stack);
    aux->dato=x;
    if(vacio(s))
        aux->sig = NULL;
    else
        aux->sig = s->sig;
    return aux;
}

stack pop(stack s){
//Quita del stack el elemento que este en el tope
    if (vacio(s)){
        return NULL;
    }else{
        stack aux = s;
        s = s->sig;
        delete (aux);
        return s;    
    }
}

int top(stack s){
//PRE:s no vacio
//POS:retorna el elemento que este ubicado en el tope del stack
    return s->dato;
}

bool vacio(stack s){
//Retorna true si el stack esta vacio, false en caso contrario
    return s == NULL;
}

stack destruir(stack s){
//Elimina los elementos del stack y libera memoria
if (vacio(s))
    return NULL;
    else {
        s->sig=destruir(s->sig);
        delete (s);
        s=NULL;
        return s;
    }
}