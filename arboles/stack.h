typedef struct nodo_stack *stack;

stack crear();
//Crea un stack vacio

stack push(stack s,int x);
//Agrega el elemento x al stack; coloca el elemento x en el top del stack

stack pop(stack s);
//Quita del stack el elemento que este en el tope

int top(stack s);
//PRE:s no vacio
//POS:retorna el elemento que este ubicado en el tope del stack

bool vacio(stack s);
//Retorna true si el stack esta vacio, false en caso contrario

stack destruir(stack s);
//Elimina los elementos del stack y libera memoria

