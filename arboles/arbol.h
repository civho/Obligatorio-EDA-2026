typedef struct  nodo_arbol * arbol;

arbol arbol_crear();
//crea un arbol

int arbol_raiz(arbol a );
// pre: a no vacío;
// retorna la raíz del arbol

arbol arbol_ph(arbol a);
// pre: a no vacío
// retorna el arbol primer hijo

arbol arbol_sh(arbol a);
// pre: a no vacío
//devuelve el arbol siguiente hermano

bool arbol_vacio(arbol a);
// retorna true si el arbol está vacío, false si no;

int max(int x, int y);

int arbol_profundidad(arbol a);
// retorna la profundidad del arbol

bool arbol_pertenece(arbol a, int x);
// retorna true si x esta em el arbol a, false en el caos contrario

void imprimir_arbol(arbol a);
// imprime el arbol tabulado

void arbol_imprimir_nivel(arbol a, int nivel);
// imprime un nivel del arbol

void arbol_imprimir_niveles(arbol a);
// imprime el arbol a por niveles

void arbol_destruir(arbol &a);
// elimina todos los nodos del arbol y libera memoria

arbol ar_destruir(arbol a);
// elimina todos los nodos del arbol y libera memoria

void arbol_insertar(arbol &a, int p , int h);
// se existe el nodo con valor p, inserta h como primer hijo de p

arbol arbol_buscar(arbol a, int x);
// si existe x entonces retorna nodo con el valor x, en cao contrario retorna NULL