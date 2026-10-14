#include "definiciones.h"
#include "editor.h"
typedef struct nodo_linea * linea;

bool CheckPosLinea(editor & e, Posicion linea, Posicion palabra);
// se fija si la posicion es posible y retorna true si lo  es, o false en caso contrario