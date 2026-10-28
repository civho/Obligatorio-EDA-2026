//Arboles PH SH
void arbol_eliminar(arbol & a ,int x){
    if (a != NULL){
        if (a -> dato == x){
            arbol aborrar = a;
            a = a -> sh;
            arbol_destruir(aborrar-> ph);
            delate aborrar;
            arbol_eliminar(a);
        }else{
            arbol_eliminar(a-> ph);
            arbol_eliminar(a-> sh);
        }
    }
}

arbol rbol_eliminar(arbol a,int x);

int sumaMayoresQueK (arbol a,int k);

int suma_nivel(arbol a,int nivel){
//PRE:a no vacio
//retorna la suma de los elementos del nivel indicado
    if (a == NULL){
        return 0;
    }else{
        if (nivel == 0)
            return a->dato + suma_nivel(a->sh, nivel);
        else
            return suma_nivel(a->ph, nivel--) + suma_nivel(a->sh, nivel);
    }
}

int mayores_Cant_Hijos(arbol a){
//PRE: a no vacio
//terona la mayor cantidad de hijos
if (a==NULL){
    return 0;
}else 
return max(1+mayores_Cant_Hijos(a->ph),mayores_Cant_Hijos(a->sh));

}



arbol nodo_mayor_cant_hijos (arbol a){
//Retorna el nodo con mayor cantidad de Hijos



}

int arbol_maximo (arbol a);
//PRE:a no vacio
//retorna el valor mayor


void arbol_primos(arbol a,arbol actual);
//Imprime los primos del arbol actual