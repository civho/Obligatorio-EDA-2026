typedef struct nodo_pal * pal;

pal CrearPalabra();
//POS:Crea un nodo pal vacio.

bool IsEmptyPal(pal p);
//POS:Checkea si p es vacio, true si es, false sino.

pal PalSig(pal p);
//POS:Devuelve el nodo pal siguiente, si hay. De lo contrario devuelve NULL hasta si p es vacio.
pal AddPalPos(pal p,int x);
//POS:Agrega una palabra en un nodo pal en x posicion, devuelve error si la posicion no es valida

pal BorrarPalPos(pal p,int x);
//POS:Borra el nodo pal en la posicion x.

pal BorrarPalPalabra(pal p,Cadena palabra);
//POS:Borra el nodo pal si es igual a la palabra ingresada.

pal DeleteAllPal(pal p);
//POS:Dado un nodo palabra, borra todos los nodos y libera memoria.

pal consPal(pal p, Cadena palabra);
//POS:Añade una palabra en el nodo pal dado.