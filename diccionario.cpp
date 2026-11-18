#include "definiciones.h"
#include "diccionario.h"
#include <stdio.h>
#include <string.h>
#include <cctype>
struct arbol_diccionario{
    dic iz, de;
    Cadena pal;
};

dic crearDic(){
    return NULL;
}

dic deDic(dic d){
    return d->de;
}

dic izDic(dic d){
    return d->iz;
}

bool vacioDic(dic d) {
    return d == NULL;
}


bool insertarPalDic(dic & d, Cadena palabra) {
    if (d == NULL) {
        dic aux = new arbol_diccionario;
        aux->iz = NULL;
        aux->de = NULL;
        aux->pal = new char[strlen(palabra) + 1]; 
        strcpy(aux->pal, palabra); //copia el string a pal
        d=aux;
        return true;
    } else {
        
        int comparar = strcasecmp(d->pal,palabra);
        if (comparar > 0){
            return  insertarPalDic(d->iz, palabra);;

        } else if (comparar < 0) {
            return insertarPalDic(d->de, palabra);;

			
        } else if (comparar == 0) { // si la palabara ya existe
            return false;
        }
    }
    return false;
}

bool PerDicc(dic d,Cadena pal){
    if(d == NULL)
        return false;
    else{
        if (d->iz != NULL && strcasecmp(d->pal, pal) > 0)
            return PerDicc(d->iz, pal);
        else{
			if (d->de != NULL && strcasecmp(d->pal, pal) < 0)
            	return PerDicc(d->de, pal);
        	else{ 
				if (strcasecmp(d->pal, pal) == 0)
					return true;
				else
					return false;
        	}
		}
	}
}

void imprimirDic(dic d) { 
    if (!vacioDic(d)){ //imprime inorder
		imprimirDic (izDic(d));
		printf("%s \n", d->pal);
		imprimirDic (deDic(d));
	}
}

int max(int a, int b){
// Retorna el maximo de a y b.
	if(a > b)
		return a;
	else
		return b;
}

int profundidad(dic d){
// Retorna la profundidad del arbol.
	if (d == NULL)
		return 0;
	else
		return 1 + max(profundidad(d->iz), profundidad(d->de));
}

dic max_iz(dic d){ 
    // retorna el ultimo hiijo de la izquierda
	if (d->de == NULL){
        return d;
	}else
    return max_iz(d->de);
}

dic min_de(dic d){
    // retorna el ultimo hiijo de la derecha
	if (d->iz == NULL){
		return d;
		
	}else
		return min_de(d->iz);
}




bool borrarDic(dic & d, Cadena palabra) {
    int comparar;
    if(d != NULL){ 
         comparar = strcasecmp(d->pal, palabra);
    }

    if(!PerDicc(d, palabra)){
        return false;
    }else if(comparar > 0){
        return borrarDic(d->iz, palabra);
    }else if(comparar < 0){
        return borrarDic(d->de, palabra);
    }else if(comparar == 0){
        if(d->de == NULL && d->iz == NULL){ // se es el ultimo nodo de una rama
            delete d;
            d = NULL;
            return true;
        }else if(d->de == NULL) { // si le quedan hijos a la izq
            dic aux = d->iz;
            delete d;
            d = aux;
            return true;
        }else if(d->iz == NULL){ // s le quedan hijos a la der
            dic aux = d->de;
            delete d;
            d = aux;
            return true;
        }else {                 // si tiene dos hijos 
            if(profundidad(d->iz) > profundidad(d->de)){ // diferenciamos por profundidad para mantener balance 

                dic nodoborrar = max_iz(d->iz);
                delete[] d->pal;
                d->pal = new char[strlen(nodoborrar->pal) + 1];
                strcpy(d->pal, nodoborrar->pal);
                return borrarDic(d->iz, nodoborrar->pal);
                
                
            }else {
                dic nodoborrar = min_de(d->de);
                delete[] d->pal;
                d->pal = new char[strlen(nodoborrar->pal) + 1];
                strcpy(d->pal, nodoborrar->pal);
                return borrarDic(d->de, nodoborrar->pal);
            
            }

        }
    }
    return false;

}

dic destruirDic(dic d){
	if (d != NULL){
		d->iz = destruirDic(d->iz);
		d->de = destruirDic(d->de);
		delete d;
	}
	return d;
}
