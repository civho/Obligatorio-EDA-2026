#include "definiciones.h"
#include "editor.h"
typedef struct nodo_buffer * buffer; 

void imprimirBuffer(buffer b);
// imprima una palabra del buffer

buffer crearBuffer();
// Crea una nuevo buffer vacio

buffer SigB(buffer b);
//Avanza al siguiente

bool IsEmpty(buffer b);
//Retorna true si esta vacia encaso contrario retirna true

buffer AgBuffer(buffer b, Cadena pal);
// Agrega la ultima plabara al buffer y si el esta lleno remplaza la palabra por una del buffer