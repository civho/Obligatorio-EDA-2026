#define HEAP_SIZE 25
typedef struct nodo_minheap * minheap;


minheap minheap_crear();
//crea un minheap acio

minheap minheap_insertar(minheap m, int x);
// pre: m no lleno
// inserta x en m

int minheap_min(minheap m);
// pre: m no vacio
// pos: retorna el valor minimo de m

int minheap_cantdad(minheap m);
// cantidad de elementos de m

minheap minheap_eliminar_minimo(minheap m);
// pre: m no vacío
// pos: elimina el valor minimo (nodo con amyor prioridad)

minheap minheap_destruir(minheap m);
// elimina todos los elementos y libera memoria

void minheap_imprimir_arreglo(minheap m);
// imprime la lista de valores de m con minimo como primer valor

void minheap_imprimir_monticulo(minheap m);
// imprime el arbol monticulo de minumos