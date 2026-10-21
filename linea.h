#include "definiciones.h"
#include "editor.h"
#include "palabra.h"
typedef struct nodo_linea * linea;

linea crearLinea();
// crea una nueva linea vacia

linea consLinea(linea l);
// agrega linea al principio

linea snocLinea(linea l);
// agrega linea al final

linea borrarLinea(linea l);
// elimina la linea especificada y liberar memoria

linea sigLinea(linea l), lienaAnt(linea l);
// devuelve la siguiete linea

void imprimirLinea(linea l);
// imprime todas las linas 

bool existeLinea(Posicion contL,Posicion posicionLinea);
//retorna true si existe la linea deseada, false si no

linea buscarLinea(linea l, Posicion x);
// pre: linea no vacia
// se mueve a una linea existente

linea insertarPalenLinea(linea l, pal p);
// inserta una cadena de palabras a una linea
pal obtenerPal(linea l);
//Retorna la primera palabra de la linea

