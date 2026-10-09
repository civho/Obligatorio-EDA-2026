#include "arbolab.h"

struct  nodo_arbolb{
    int dato;
    arbolb izq;
    arbolb der;
};

arbolb crear(){
    return NULL;
}

arbolb insertar(int x, arbolb abiz, arbolb abde){
    arbolb aux= new(nodo_arbolb);   
    aux->dato=x;
    aux->izq = abiz;
    aux->der = abde;
 
    return aux;
}
bool raíz(arbolb ab){
    return ab->dato;
}
// pre: ab no vacio
// pos: retorna la raiz de un arbol ab

arbolb abiz(arbolb ab){
    return ab->izq;
}
//retorna subarbol iz

arbolb abde(arbolb ab){
    return ab->der;
}
// retorna subarbol der

bool vacio(arbolb ab){
    return (ab == NULL);
}
// retorna true si arbol vacio false si caso contrario

bool pertenece(arbolb ab, int x){
    if(ab==NULL){
        return false;
    }else if(ab->dato == x){
        return true;
    }else {
        return pertenece(ab->izq,x) || pertenece(ab->der,x);

    }
}
// retorna true si x pertenece a ab false en el caso contrario

int cantidad(arbolb ab){
    if(ab == NULL){
        return 0;
    }else {
        return 1+cantidad(ab->izq)+cantidad(ab->der);
    }
}
// retorna la cantiad de nodos de x en ab
int max(int x, int y) {
    
}

int profundidad(arbolb ab){
    if(ab==NULL){
        return 0;
    }else {
        return 1+max(profundidad(ab->izq),profundidad(ab->der));
    }
}
// retorna la profundidad del arbol de ab

arbolb destruir(arbolb ab) {
    if(ab == NULL) {
        return NULL;
    }else {
        ab->izq = destruir(ab->izq);
        ab->der = destruir(ab->der);
        delete ab;
        return NULL;
    }
}


arbolb destruirPROD(arbolb &ab) {
    if(ab == NULL) {
        return NULL;
    }else {
        destruir(ab->izq);
        destruir(ab->der);
        delete ab;
        return NULL;
    }
}
// elimina todos los nodos del arbol ab y libera memoria