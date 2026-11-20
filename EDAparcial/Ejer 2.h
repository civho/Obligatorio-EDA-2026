typedef struct nodo_arbol *arbol;

int arbol_profundidad(arbol a);
//returna la altura del arbol

int max(int x, int y);
//

void arbol_imprimir_Rama(arbol a);
//

void imprimirRamasMasLargas(arbol a, int prof);
//

void ramasMasLargas(arbol a);
//imprime las ramas mas largas del árbol
//(Entendiendo por rama el camino desde la raíz a una hoja)