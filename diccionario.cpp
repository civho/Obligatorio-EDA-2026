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
        aux->pal = new char[strlen(palabra) + 1]; //copia el string a pal
        strcpy(aux->pal, palabra);
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
    if (!vacioDic(d)){
		imprimirDic (izDic(d));
		printf("%s \n", d->pal);
		imprimirDic (deDic(d));
	}
}
