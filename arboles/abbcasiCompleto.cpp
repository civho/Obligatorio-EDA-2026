#include "abbcasiCompleto.h"
#include <stdio.h>
#include <cmath>

struct nodo_minheap {
    int * arr;
    int tope;
};

minheap minheap_crear() {
    minheap aux = new nodo_minheap;
    aux->arr = new (int[HEAP_SIZE]);
    aux->tope = 0;
    return aux;
}

minheap minheap_insertar(minheap m, int x){
    m->arr[m->tope] = x;
    int pos = m->tope;
    m->tope ++;
    int swap;
    while (pos > 0 && m->arr[pos] < m->arr[(pos - 1) / 2]) { // el valor que estamos es menor al valor del padre
        swap = m->arr[pos]; // guardamos el valor actual (que es menor)
        m->arr[pos] = m->arr[(pos - 1) / 2]; // guardamos es en valor actual el valor del padre(que es mayor)
        m->arr[(pos - 1) / 2] = swap; // en el valor del padre el valor que habiamos guardado del hijo (que es mas pequeño)
        pos = (pos - 1)/ 2; // ahora nuestro pos es el nuevo pos modificado que tiene el valor mas pequeño (para la siguiente recursion del while nos movimos hacia arriba)
        
    }
    return m;
}

int minheap_min(minheap m){
    return m->arr[0];
}

int minheap_cantdad(minheap m){
    return m->tope;
}

minheap minheap_eliminar_minimo(minheap m){
    m->tope --;
    m->arr[0] = m->arr[m->tope];
    int pos = 0;
    bool intercambiar = true;
    int swap, pos_swap;
    while (intercambiar && (2*pos + 1) < m->tope ){
        if((2 * pos + 2) < m->tope) {
            if( m->arr[2*pos +1] < m->arr[2*pos +2]){
                pos_swap = 2*pos+1;
            }else {
                pos_swap = 2*pos+2;
            }
            
        }
        pos_swap = 2*pos+1;
    }
    if(m->arr[pos] > m->arr[pos_swap]) {
        swap = m->arr[pos];
        m->arr[pos] = m->arr[pos_swap];
        pos = pos_swap;
    }else { 
        intercambiar = false;
    }
    return m;
}
minheap minheap_destruir(minheap m){
    delete[] m->arr;
    delete m;
    m = NULL;
    return m;
}

void minheap_imprimir_arreglo(minheap m){
    for(int i=0; i < m->tope; i ++){
        printf("posicion %d, valor %d \n", i, m->arr[i]);
    }
}

void minheap_imprimir_monticulo(minheap m) {
    for(int i = 0; pow(2,1) < m->tope; i++){
        for(int j=pow(2,i)-1; (j>2*pow(2,i)-1) && (j < m->tope); j++){
            printf("%d ", m->arr[j]);
        }
        printf("\n");
    }
}