typedef struct nodo_pal * pal;

pal CrearPalabra();
//Crea un nodo pal vacio.

pal consPalabra(pal p);
//Agrega una palabra al principio del nodo pal.

pal AddPalPos(pal p,int x);
//Agrega un nodo pal en x posicion

pal BorrarPalPos(pal p,int x);
//Borra el nodo pal en la posicion xalloc

pal BorrarPalPalabra(pal p,Cadena palabra);
//Borra el nodo pal si es igual a la palabra ingresada