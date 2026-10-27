#include "definiciones.h"

typedef struct arbol_diccionario * dic;

dic crearDic();
//retorna NULL

dic deDic(dic d);
// retorna el hijo derecho de d

dic izDic(dic d);
// retorna el hijo izquierdo de d

bool vacioDic(dic d);
// retorna true si d esta, vacio false si no

bool insertarPalDic(dic  & d, Cadena palabra);
// inserta la palabra ordenadamente en el diccionario

void imprimirDic(dic d);
// pre imprime los datos de el diccionario, si esta vacio devuelve "diccionario vacio"

Cadena aMayuscula(Cadena palabra);
//pre: palabra no vacia
//pos: convierte una cadena de caracteres a mayuscula