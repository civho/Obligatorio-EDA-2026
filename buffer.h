#include "definiciones.h"
#include "editor.h"
typedef struct nodo_buffer * buffer; 

buffer crearBuffer();
// crea una nuevo buffer vacio

buffer consBuffer(buffer b, Cadena pal);
// agrega linea al final

buffer borrarUltimo(buffer b);
// elimina la ultima palabra y mueve 
