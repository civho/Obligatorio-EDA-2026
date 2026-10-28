#include "definiciones.h"
#include "linea.h"
#include "palabra.h"
#include <string.h>
#include <stdio.h>

int MAX_PAL=20;

struct nodo_pal {
    pal sig;
    Cadena palabra=NULL;
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
		aux->sig = p;
	aux->palabra=auxpal;
	strcpy(aux->palabra,palabra);
	return aux;
}
//MAX PAL habria que declararla? Maximo de letras que entrarian por palabra.

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

pal correrPalOverflow(pal p,psigL){
for (int i=1;i<MAX_CANT_PALABRAS_X_LINEA;i++){
p=PalSig(p);
}
pal aux=PalSig(p);
p->sig=NULL;
aux->sig=psig;
return aux;

pal BorrarOcurrenciasPalabra(pal p, Cadena palabra){
	if (p==NULL){
		return NULL;
	} else {
		if (strcmp(p->palabra,palabra)==0){
			pal aux;
			aux=p;
			p=PalSig(p);
			p=BorrarOcurrenciasPalabra(p,palabra);
			EliminarPal(aux);
			return p;
		} else {
			p->sig=BorrarOcurrenciasPalabra(PalSig(p),palabra);
			return p;
		}
	}
}

void EliminarPal(pal & p){
	if (p!=NULL){
	delete[] p->palabra;
	delete p;
	p=NULL;
	}
}