//Ejer 1
//a
typedef struct nodo_queue *queue;

queue queue_crea();
//crea una queve vacia 

queue queve_enqueve(queue q, unsigned int x);
//inserta x al final de q

queue queve_dequeve(queue q);
//Pre: q no vacio
//eliminar el primer elemento

bool queve_isEmpty(queue q);
//retorna true si q vasia, false en caso contrario 

void queue_imprimir(queue q);
//imprime los elemnto q

unsigned queue_first(queue q);
//retorna el primer de q

queue queve_destruir(queue q);
//elimina todas los elemento y libera memopria 

unsigned queue_last(queue q);
//retorna el ultimo de q

typedef struct nodo_cola *cola;

cola cola_crear();
//crea una cola vacia 

cola cola_encolar(cola c, unsigned x);
//agrega x al final de c

cola cola_decencolar(cola c);
//quita el prmer elemnto

//Ejer 2