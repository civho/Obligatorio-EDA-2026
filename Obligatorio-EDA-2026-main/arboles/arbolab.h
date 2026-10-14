typedef struct nodo_arbolb * arbolb;


arbolb crear();
// retorna un arbolb vaciio

arbolb insertar(int x, arbolb abiz, arbolb abde);
// inserta x como raíz de un arbol de un ab con abiz y abde arboles izquierdo y derecho

bool raíz(arbolb ab);
// pre: ab no vacio
// pos: retorna la raiz de un arbol ab

arbolb abiz(arbolb ab);
//retorna subarbol iz

arbolb abde(arbolb ab);
// retorna subarbol der

bool vacio(arbolb ab);
// retorna true si arbol vacio false si caso contrario

bool pertenece(arbolb ab, int x);
// retorna true si x pertenece a ab false en el caso contrario

int cantidad(arbolb ab);
// retorna la cantiad de nodos de x en ab

int profundidad(arbolb ab);
// retorna la profundidad del arbol de ab

arbolb destruir(arbolb ab), destruirPROD(arbolb ab);
// elimina todos los nodos del arbol ab y libera memoria