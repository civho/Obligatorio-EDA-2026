#include "definiciones.h"

typedef struct nodo_diccionario * dic;

dic crearDic();
//retorna NULL

dic deDic(dic d);
// retorna el hijo derecho de d

dic izDic(dic d);
// retorna el hijo izquierdo de d

bool vacioDic(dic d);
// retorna true si d esta, vacio false si no

dic insertaraPalabraDic(dic d, Cadena palabra);
