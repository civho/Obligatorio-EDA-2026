#include "palabra.h"
#include "definiciones.h"
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
	

pal PalSig(pal p){
	if (p==NULL){
		return NULL;
	}else{
		return p->sig;
	}
	
pal AddPalPos(pal p,int x,Cadena palabra){
	if (x==0){
		pal aux = new(nodo_pal);
		PalSig(aux)=PalSig(p);
		return aux;
	}else if (IsEmptyPal(p)){
		return ERROR;
	}else 
		PalSig(p)=AddPalPos(PalSig(p),x-1,palabra);
		return p
//Falta agregar la palabra propiamente dicha, y si esta bien implementear el "ERROR" aca.Tambien chequear que x es menor que MAX PALABRA.

pal BorrarPalPos(pal p,int x){
	if (x==0){
		pal aux=PalSig(p);
		delete p;
		return aux;
	}else {
		PalSig(p)=BorrarPalPos(PalSig(p),x-1);
	}
		return p;
	
//Falta chequear que el X es valido

pal BorrarPalPalabra(pal p,Cadena palabra);
//Borra el nodo pal si es igual a la palabra ingresada