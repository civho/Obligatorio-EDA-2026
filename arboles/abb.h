typedef struct nodo_abb * abb;


abb crear();
// crea un arbol vacio

abb insertar(abb a, int x);
// agrega x en forma ordenada en el arbol a

bool vacio(abb a);
// retorna true si esta vacio, false si tiene valores

int raiz(abb a);
// pre: a no vacio
// pos; etorna la raíz del arbol a

abb subiz(abb a);
// pre: a no vacio
// pos: retorna el subarbol de la izquierda

abb subde(abb a);
// pre: a no vacio
// pos; retorna el subarbol de la derecha

int contar(abb a);
// retorna la cantidad de nodos del arbol a

bool pertenece(abb a, int x);
// retorna true si x esta en el arbol, en caso contrario retorna false
    int max(int x, int y);
int profundidad(abb a);
// retorna la profundidad del arbol

abb eliminar(abb a, int x);
// elimina el nodo x del arbol y libera memoria

abb destruir(abb a);
// elimina todos los nodos y libera memoria

abb minimo(abb a);
// pre: a no vacio
// pos: retorna la clave con menor valor

abb maximo(abb a);
// pre: a no vacio
// pos: retorna la clave con mayor valor

bool esabb(abb a);
// retorna true si es abb, en caso contrario retorna false