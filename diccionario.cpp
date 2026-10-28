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


Cadena aMayuscula(Cadena palabra) {
    Cadena auxPal = new char; 
        strcpy(auxPal, palabra);
        int cantPal = strlen(auxPal) + 1; 
        for (int i = 0; i < cantPal; i++){
            auxPal[i] = toupper(auxPal[i]);
        }
        return auxPal;
}


bool insertarPalDic(dic & d, Cadena palabra) {
    
    
    if (d == NULL) {
        dic aux = new arbol_diccionario;
        aux->iz = NULL;
        aux->de = NULL;
        aux->pal = new char; //copia el string a pal
        strcpy(aux->pal, palabra);
        d=aux;
        return true;
    } else {
        
        int comparar = strcmp(aMayuscula(d->pal),aMayuscula(palabra));
        if (comparar > 0){
            return  insertarPalDic(d->iz, palabra);;

        } else if (comparar < 0) {
            return insertarPalDic(d->de, palabra);;
            
        } else if (comparar == 0) { // si la palabara ya existe
            return false;
        }
    }
    return NULL;
}

void imprimirDic(dic d) { 
    	if (!vacioDic(d)){
		imprimirDic (izDic(d));
		printf("%s \n", d->pal);
		imprimirDic (deDic(d));
	}

}