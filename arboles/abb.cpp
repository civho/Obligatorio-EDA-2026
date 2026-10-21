#include "abb.h"
#include <stdio.h>

struct nodo_abb
{
    int dato;
    abb iz;
    abb de;
};  

abb crear() {
    return NULL;
}
abb insertar(abb a, int x) {
    if(vacio(a)){
        abb aux = new(nodo_abb);
        aux -> iz = NULL;
        aux -> de = NULL;
        aux -> dato = x;
        return aux;
    }else if(a -> dato > x) {
        a -> iz = insertar(a-> iz, x);
        return a;
    }else if (a -> dato < x){
        a -> de = insertar(a-> de, x);
        return a;
    }
    
}

bool vacio(abb a) {
    return a == NULL;
}

int raiz(abb a){
// pre: a no vacio
// pos; retorna la raíz del arbol a
    return a->dato;
}

abb subiz(abb a){      
// pre: a no vacio
// pos: retorna el subarbol de la izquierda
    return a->iz;
}

abb subde(abb a){    
// pre: a no vacio
// pos; retorna el subarbol de la derecha
    return a->de;
}

int contar(abb a){
// retorna la cantidad de nodos del arbol a
    if(vacio(a)){   
        return 0;
    }else {
        return contar(a->iz) + 1 + contar(a->de);
    }
    
    
}

bool pertenece(abb a, int x) {

    if(vacio(a)) {
        return false;
    }else if(a->dato == x) {
        return true;
    } else if(a->dato > x) {
        return pertenece(a->de, x);
    }else {
        return pertenece(a->iz, x);
    }

}

     int max(int x, int y){
        if(x > y){
            return x;
        } else {
            return y;
        }
    }

int profundidad(abb a){
    // retorna la profundidad del arbol
    if(vacio(a)){
        return 0;
    }else {
        return 1+max(profundidad(a->iz), profundidad(a->de));
    }
}
    

abb eliminar(abb a, int x){
    // elimina el nodo x del arbol y libera memoria
    if(vacio(a)) {
        return NULL;

    }else if(a->dato > x) {
        return a->iz = eliminar(a->iz, x);

    }else if(a->dato < x) {
        return a->de = eliminar(a->de, x);

    }else if(vacio(a->iz) && vacio(a->de)){ 
        delete a;
        return  NULL;   

    }else if(vacio(a->iz)) {
        abb aux = a-> de; 
        delete a;
        return aux;

    }else if(vacio(a->de)) {
        abb aux = a-> iz; 
        delete a;
        return aux;
    }else {
        abb aux = minimo(a->de);
        a->dato = aux->dato;
        a->de = eliminar(a->de, aux->dato);
        return a;
    }
}

abb destruir(abb a) {
    // elimina todos los nodos y libera memoria
    if(vacio(a)) {
        return NULL;
    }else {
        a->iz = destruir(a->iz);
        a->de = destruir(a->de);
        delete a;
        return NULL;
    }
}

abb minimo(abb a){
    // pre: a no vacio
    // pos: retorna la clave con menor valor
    if(vacio(a)) {

        return NULL;
    } else if(a->iz == NULL){
        return a;
    }else {
        
        return minimo(a->iz);
    }
    
}


abb maximo(abb a){
// pre: a no vacio
// pos: retorna la clave con mayor valor
    if(vacio(a)) {
    

        return NULL;
    } else if(a->de == NULL){
        return a;
    }else {
        
        return maximo(a->de);
    }

}

bool esabb(abb a);
// retorna true si es abb, en caso contrario retorna false