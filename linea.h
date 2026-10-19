#include "definiciones.h"
#include "editor.h"
typedef struct nodo_linea * linea;

linea crearLinea();
// crea una nueva linea vacia

linea consLinea(linea l);
// agrega linea al principio

linea snocLinea(linea l);
// agrega linea al final

linea borrarLinea(linea l, int pos);
// elimina la linea especificada y liberar memoria

linea sigLinea(linea l), lienaAnt(linea l);
// devuelve la siguiete linea

void imprimirLinea(linea l);
// imprime todas las linas 
