#include "definiciones.h"
#include "editor.h"
typedef struct nodo_buffer * buffer; 

buffer crearBuffer();
// Crea una nuevo buffer vacio

buffer consBuffer(buffer b, Cadena pal);
// Agrega la ultima plabara al buffer y si el esta lleno remplaza la palabra por una del buffer
