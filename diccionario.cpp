#include "definiciones.h"
#include "diccionario.h"
#include <stdio.h>
#include <string.h>

struct nodo_diccionario{
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

dic insertaraPalabraDic(dic d, Cadena palabra) {
    if (d == NULL) {
        dic aux = new nodo_diccionario;
        aux->iz = NULL;
        aux->de = NULL;
        aux->pal = new char[strlen(palabra) + 1];
            strcpy(aux->pal, palabra);
        return aux;
    } else {
        int comparar = strcmp(d->pal, palabra);
        if (comparar < 0){
            d->iz = insertaraPalabraDic(d->iz, palabra);
            return d;
        } else if (comparar > 0) {
            d->de = insertaraPalabraDic(d->de, palabra);
            return d;
        } else if (comparar == 0) {
            return d;
        }
    }
    return NULL;
}
