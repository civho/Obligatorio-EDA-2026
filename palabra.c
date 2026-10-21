#include "palabra.h"
#include "definiciones.h"
#include <string.h>
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
	if (x==0){
		p=consPal(p,palabra);
		return p;
	}else {
		p->sig=AddPalPos(PalSig(p),x-1,palabra);
		return p;
	}
}
//Falta chequear que el X es valido,y como manejar el error

pal BorrarPalPos(pal p,Posicion x){
	if (IsEmptyPal(p)){
		return ERROR;
	}else{
	if (x==0){
		pal aux=PalSig(p);
		delete p;
		return aux;
	}else {
		PalSig(p)=BorrarPalPos(PalSig(p),x-1);
	}
	}
		return p;
}	
//Falta chequear que el X es valido, y como manejar el error

pal BorrarPalPalabra(pal p,Cadena palabra);
//Borra el nodo pal si es igual a la palabra ingresada

pal DeleteAllPal(pal p){
	if (p==NULL){
		return NULL;
}else {
	PalSig(p)=DeleteAllPal(PalSig(p));
	delete p->palabra;
	delete p;
	p=NULL;
	return p;
}
}

pal consPal(pal p, Cadena palabra){
	Cadena auxpal = new(char[MAX_PAL]);
	pal aux = new(nodo_pal);
	PalSig(aux)=PalSig(p);
	aux->palabra=auxpal;
	strcpy(aux->palabra,palabra);
}
//Falta ver si esta bien implementear el "ERROR" aca.Tambien chequear que x es menor que MAX PALABRA(por lineas). 
//MAX PAL habria que declararla? Maximo de letras que entrarian por palabra.
//No se si el strcpy funciona...

void ImprimirPal(pal p){
	if (p!=NULL){
		i=0;
		while (p->palabra[i]!='\0'){
			printf(p->palabra[i];
		}
		printf(" ");
	}
	ImprimirPal(PalSig(p);
}

Posicion cantPal(pal p){
	Posicion cont=0;
	while (p!=NULL){
		cant++;
	}
return cant;
}
