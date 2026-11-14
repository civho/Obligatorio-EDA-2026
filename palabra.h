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

pal correrPalOverflow(pal p,pal psigL);
//PRE:p con nodos max palabras+1 al menos, psigL existe y es el primero de los nodos pal de la siguiente linea.
//POS:Mueve el nodo excedente al inicio de psigL, y retorna esta misma cadena de nodos pal. 

pal BorrarOcurrenciasPalabra(pal p, Cadena palabra);
//POS:Devuelve una lista de nodos palabra eliminando y liberando de memoria las que tengan la palabra dada.

void EliminarPal(pal & p);
//POS:Elimina y libera memoria de p.

Cadena ObeTex(pal p);
//Retorna la palabra

pal SobrecargarPal(pal cabeza,pal cola);
//POS:Añade el pal cola al final de los nodos del pal cabeza, sin restricciones.

pal correrPalCompresion(pal p,pal psigL);
//PRE:Funcion usada exclusivamente para comprimir texto, misma logica que correrPalOverflow.
//POS:Separa los nodos excedentes y son los que devuelve