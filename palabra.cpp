#include "definiciones.h"
#include "linea.h"
#include "palabra.h"
#include <string.h>
#include <stdio.h>

int MAX_PAL=20;

struct nodo_pal {
    pal sig;
    Cadena palabra;
};

pal CrearPalabra(){
	return NULL;
}

bool IsEmptyPal(pal p){
	if (p==NULL){
		return true;
	}else {
		return false;
	}
}
		

pal PalSig(pal p){
	if (p==NULL){
		return NULL;
	}else{
		return p->sig;
	}
}
	
pal AddPalPos(pal p,Posicion x,Cadena palabra){
	if (x==1){
		p=consPal(p,palabra);
		return p;
	}else {
		p->sig=AddPalPos(PalSig(p),x-1,palabra);
		return p;
	}
}
//Falta chequear que el X es valido,y como manejar el error

pal BorrarPalPos(pal p,Posicion x){
	if (x==1){
		pal aux=PalSig(p);
		delete p;
		return aux;
	}else {
		p->sig=BorrarPalPos(PalSig(p),x-1);
	}
	
		return p;
}	

pal BorrarPalPalabra(pal p,Cadena palabra);
//Borra el nodo pal si es igual a la palabra ingresada

pal DeleteAllPal(pal p){
	if (p==NULL){
		return NULL;
}else {
	p->sig=DeleteAllPal(PalSig(p));
	delete p->palabra;
	delete p;
	p=NULL;
	return p;
}
}

pal consPal(pal p, Cadena palabra){
	Cadena auxpal = new char[MAX_PAL];
	pal aux = new(nodo_pal);
		aux->sig = PalSig(p);
	aux->palabra=auxpal;
	strcpy(aux->palabra,palabra);
	return aux;
}
//Falta ver si esta bien implementear el "ERROR" aca.Tambien chequear que x es menor que MAX PALABRA(por lineas). 
//MAX PAL habria que declararla? Maximo de letras que entrarian por palabra.
//No se si el strcpy funciona...

void ImprimirPal(pal p){
	if (p!=NULL){
		int i = 0;
		while (p->palabra[i]!='\0'){
			printf("%c", p->palabra[i]);
			i++;
		}
		printf(" ");
		ImprimirPal(PalSig(p));
	}
}

Posicion cantPal(pal p){
	Posicion cont=0;
	while (p!=NULL){
		cont++;
		p = p->sig;
	}
return cont;
}

bool PosicionValidaPal(Posicion x,pal p){
	if (x>MAX_CANT_PALABRAS_X_LINEA){
		return false;
	}else if(x<=cantPal(p)+1){
		return true;
	}else {
		return false;
	}
}
//Si da error leer el #define MAX_CANT_PALABRAS_X_LINEA 3.

// linea correrPalOverflow(linea l,pal p){
// 		if (PalSig(p)==NULL){
// 			if (sigLinea(l)!=NULL){
// 				l=sigLinea(l);
// 			} else {
// 				snocLinea(l);
// 				l=sigLinea(l);
// 			}
// 			pal aux=l->palabra;
// 			l->palabra=p;
// 			p->sig=aux;
// 			return NULL;
// 		} else {
// 			l=correrPalOverflow(l,PalSig(l->palabra));
// 		}
// }