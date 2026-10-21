#include "definiciones.h"
#include "editor.h"
typedef struct nodo_linea * linea;

linea crearLinea();
// crea una nueva linea vacia

linea consLinea(linea l);
// agrega linea al final

linea borrarLinea(linea l, int pos);
// elimina la linea especificada y liberar memoria

linea sigLinea(linea l);
// devuelve la siguiete linea

