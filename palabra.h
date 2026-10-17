typedef struct nodo_pal * pal;

pal CrearPalabra();
//Crea un nodo pal vacio.

bool IsEmptyPal(pal p);
//Checkea si p es vacio.

pal PalSig(pal p);
//Devuelve el nodo pal siguiente, si hay. De lo contrario devuelve NULL

pal AddPalPos(pal p,int x);
//Agrega una palabra en un nodo pal en x posicion, devuelve error si la posicion no es valida

pal BorrarPalPos(pal p,int x);
//Borra el nodo pal en la posicion x.

pal BorrarPalPalabra(pal p,Cadena palabra);
//Borra el nodo pal si es igual a la palabra ingresada.