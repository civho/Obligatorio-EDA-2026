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

pal BorrarPalPalabra(pal p,Cadena palabra);
//POS:Borra el nodo pal si es igual a la palabra ingresada.

pal DeleteAllPal(pal p);
//POS:Dado un nodo palabra, borra todos los nodos y libera memoria.

pal consPal(pal p, Cadena palabra);
//POS:Añade una palabra en el nodo pal dado.

Posicion cantPal(pal p);
//POS:Retorna la cantidad de palabras en un nodo pal.

void ImprimirPal(pal p);
// imprime la palabra 