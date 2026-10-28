#include "definiciones.h"
#include "editor.h"

typedef struct nodo_pal * pal;

pal CrearPalabra();
//POS:Crea un nodo pal vacio.

bool IsEmptyPal(pal p);
//POS:Checkea si p es vacio, true si es, false sino.

pal PalSig(pal p);
//POS:Devuelve el nodo pal siguiente, si hay. De lo contrario devuelve NULL hasta si p es vacio.

pal AddPalPos(pal p,Posicion x, Cadena palabra);
//PRE:Posicion valida.
//POS:Agrega una palabra en un nodo pal en x posicion.

pal BorrarPalPos(pal p,Posicion x);
//PRE:Posicion valida.
//POS:Borra el nodo pal en la posicion x.

pal DeleteAllPal(pal p);
//POS:Dado un nodo palabra, borra todos los nodos y libera memoria.

pal consPal(pal p, Cadena palabra);
//POS:Añade una palabra en el nodo pal dado.

Posicion cantPal(pal p);
//POS:Retorna la cantidad de palabras en un nodo pal.

void ImprimirPal(pal p);
// imprime la palabra 

bool PosicionValidaPal(Posicion x,pal p);
//Chequea si la Posicion x ingresada es valida.

linea correrPalOverflow(pal p,psig);
//PRE:p con nodos max palabras+1, psig existe.
//POS:Hace las asignaciones correspondientes.

pal BorrarOcurrenciasPalabra(pal p, Cadena palabra);
//POS:Devuelve una lista de nodos palabra eliminando y liberando de memoria las que tengan la palabra dada.

void EliminarPal(pal & p);
//POS:Elimina y libera memoria de p.

