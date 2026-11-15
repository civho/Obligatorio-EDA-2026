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


bool PerDicc(dic d,Cadena pal);
// retorna true si la palabra se encunetra en el diccioanrio, false en el caso contrario

bool borrarDic(dic & d, Cadena palabra);
// elimina una palabra del diccionario

dic destruirDic(dic d);
// elimina todos los nodos del editor y libera memoria