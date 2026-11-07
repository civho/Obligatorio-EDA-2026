#include "arbol.h"
#include <stdio.h>
struct nodo_arbol {
    int dato;
    arbol ph;
    arbol sh;
};

arbol arbol_crear() {
    return NULL;
}

int arbol_raiz(arbol a){
    return a->dato;
}
arbol arbol_ph(arbol a) {
    return a->ph;
}

arbol arbol_sh(arbol a) {
    return a->sh;
}

bool arbol_vacio(arbol a){
    return a == NULL;

}

int max(int x, int y){
    if(x > y){
        return x;
    }else {
        return y;
    }
}

int arbol_profundidad(arbol a){
    if(a == NULL){
        return 0;
    }else {
        return  max(1+ arbol_profundidad(a->ph), arbol_profundidad(a->sh));
    }
    
}
bool arbol_pertenece(arbol a, int x) {
    if(a == NULL){
        return false;
    }else if(a->dato == x){
        return true;
    }else {
        return arbol_pertenece(a->sh, x) || arbol_pertenece(a->ph, x);
    }

}

void imprimir_arbol(arbol a) {
    if(a == NULL){
        printf("arbol vacio");
    }else {
        int cantE = 0;
        arbol_imprimir_tree(a, cantE);   
    }
}
void arbol_imprimir_tree(arbol a, int cant_Tab){
    if(a != NULL){
        for (int i = 0 ; i < cant_Tab; i++){
            printf(" ");
        }
        printf("%d \n",a->dato);
        arbol_imprimir_tree(a->ph, cant_Tab++);
        arbol_imprimir_tree(a->sh, cant_Tab);
    }

}

void arbol_imprimir_nivel(arbol a, int nivel){
// imprime un nivel del arbol
    if (a != NULL){
        if (nivel == 0){
            printf("%d \n",a->dato);
            arbol_imprimir_nivel(a->sh, nivel);
        }else{
            arbol_imprimir_nivel(a->ph, nivel--);
            arbol_imprimir_nivel(a->sh, nivel);
        }
    }
}

void arbol_imprimir_niveles(arbol a);
// imprime el arbol a por niveles

void arbol_destruir(arbol &a);
// elimina todos los nodos del arbol y libera memoria

arbol ar_destruir(arbol a){
// elimina todos los nodos del arbol y libera memoria
    if (a == NULL)
    {
        return NULL;
    }else{
        a->ph = ar_destruir(a->ph);
        a->sh = ar_destruir(a->sh);
        delete(a);
        return NULL;
    }
}


void arbol_insertar(arbol &a, int p , int h) {
 if(a == NULL){
    
 }else {
    arbol nodo_padre = arbol_buscar(a,p);
    if(nodo_padre != NULL){
        arbol nodo_nuevo = new nodo_arbol;
        nodo_nuevo->sh = nodo_padre->sh;
        nodo_nuevo->ph = nodo_nuevo;
    }
    
 }

}
arbol arbol_buscar(arbol a, int x) {
    if (a == NULL){
        return NULL;    
    }else if(a->dato == x ){
        return a;
    }else {
        arbol aux = arbol_buscar(a->ph, x);
        if(aux != NULL){
            return aux;
        }else {
            return arbol_buscar(a->sh,x);
        }
    }

}