// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// editor.c
// Modulo de implementacion de editor.

#include "editor.h"
#include "linea.h"
#include "buffer.h"
#include "palabra.h"
// Incluir los modulos realizados.
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_editor{
	/* acá deben figurar los campos/estructuras que usted considere necesarios para implementar el editor.
	Ej: texto, diccionario, etc. Recordar que cada módulo
	debe implementarse independientemente e incluirse */
	linea lin = NULL; 
	buffer buf = NULL; // las 3 ultimas letras
	Posicion contL = 0;
};

editor CrearEditor(){
// Crea la estructura editor.
	editor e = new(nodo_editor);
	/* crear el resto de las estructuras que se incluyan en el editor
	usando las funciones correspondientes de cada modulo */
	return e;
}

TipoRetorno InsertarLinea(editor & e){
// Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.
// Ver más detalles en la letra del obligatorio.
	e->lin = consLinea(e->lin);
	e->contL ++;
	return OK;
}

TipoRetorno InsertarLineaEnPosicion(editor & e, Posicion posicionLinea){
// Inserta una nueva línea vacía en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	if(existeLinea(e->contL, posicionLinea - 1)) {
		linea aux = e->lin;
		
		aux = buscarLinea(aux, posicionLinea); // se mueve a la linea especificada, si no hay linea se queda donde esta
		
		if(posicionLinea == e->contL + 1) { //verifica que la linea deseada sea la primera o la ultima
			aux = snocLinea(aux);
			e->lin = sigLinea(aux); 

		}else {
			if(e->lin == aux) { // se fija si es la primera linea para así cambiar el puntero del editor a la nueva primera linea
				aux = consLinea(aux);
				e->lin = aux;
			}else {
				aux = consLinea(aux);
			}

		}
			return OK;

	}
 return ERROR;
}

TipoRetorno BorrarLinea(editor &e, Posicion posicionLinea){
// Borra la línea en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	linea aux=e->lin;
	if(existeLinea(e->contL ,posicionLinea)) {
		aux = buscarLinea(aux, posicionLinea);
		aux =	borrarLinea(aux);
		e->contL = e->contL-1;
		return OK;
	}else {
		return ERROR;
	}
	return ERROR;
}

TipoRetorno BorrarTodo(editor & e){
// Borra todas las líneas del texto.
// Ver más detalles en la letra del obligatorio.

	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor & e, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en el texto.
// Ver más detalles en la letra del obligatorio.

	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirTexto(editor & e){
// Imprime el texto por pantalla.
// Ver más detalles en la letra del obligatorio.
	if(e->contL == 0) {
		printf("Texto vacio\n");
	}else{
		for(Posicion i = 1; i <= e->contL; i++) {
			linea aux = buscarLinea(e->lin, i);
			imprimirLinea(aux);
		}
	}
	return OK;
}

TipoRetorno ComprimirTexto(editor & e){
// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.
	if(existeLinea(e->contL, posicionLinea)){
		
		linea auxLin = buscarLinea(e->lin, posicionLinea); //busca la linea especificada
		if(posicionPalabra == cantPal(obtenerPal(auxLin)) + 1 && MAX_CANT_PALABRAS_X_LINEA >= posicionPalabra){
				printf("aaa");
				 //se asegura que la posicion de insersion de palabra sea correcta

				pal auxPal = AddPalPos(obtenerPal(auxLin),posicionPalabra, palabraAIngresar); // intenta agregar la palabra a la posicion adecuada

					if(auxPal != NULL){
						auxLin = insertarPalenLinea(auxLin, auxPal); //si la palabra fue agregada inserta la lista de palabras en la linea
					}else {
						return ERROR; //devuelve un error si la palabra no se ingreso
					}
			}else {

			return ERROR; //devuelve un error si la posicion ingresada es erronea
			}
			return OK;
		}else {
			return ERROR;
		}
		return NO_IMPLEMENTADA;
}

TipoRetorno BorrarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra){
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor & e, Posicion posicionLinea, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en la línea indicada.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirLinea(editor & e, Posicion posicionLinea){
// Imprime la línea por pantalla.
// Ver más detalles en la letra del obligatorio.

	if(existeLinea(e->contL, posicionLinea - 1)) {
		linea aux = buscarLinea(e->lin, posicionLinea);
		imprimirLinea(aux);
		return OK;
	}


	return ERROR;
}

TipoRetorno IngresarPalabraDiccionario(editor & e, Cadena palabraAIngresar){
// Agrega una palabra al diccionario.
// Esta operación debe realizarse en a lo sumo O(log n) promedio.
// Ver más detalles en la letra del obligatorio.
	insertaraPalabraDic(e->dic, palabraAIngresar);
	return OK;
}

TipoRetorno BorrarPalabraDiccionario(editor & e, Cadena palabraABorrar){
// Borra una palabra del diccionario.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirDiccionario(editor & e){
// Muestra las palabras del diccionario alfabéticamente.
// Esta operación debe realizarse en O(n) peor caso.
// Ver más detalles en la letra del obligatorio.
	dic aux = e->dic;
	if(vacioDic(aux)){
		printf("Diccionario vacio\n");
	}else{
		imprimirDiccionario(izDic(aux));
		printf("%s\n", raizDic(aux));
		imprimirDiccionario(deDic(aux));
	}
	return OK;
}

TipoRetorno ImprimirTextoIncorrecto(editor & e){
// Muestra las palabras del texto que no se encuentran en el diccionario.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirUltimasPalabras(editor & e){
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.
	buffer aux = e->buf;
	if(aux == NULL){
		printf("No se ingresaron palabras\n");
	}else{
		while(aux != NULL){
			printf("%s", aux->palabra);
			printf(" ");
			aux = aux->sig;
		}
		printf("\n");
	}
	return OK;
}

TipoRetorno DestruirEditor(editor & e){
// Destruye la estructura editor y libera la memoria asociada.
	return NO_IMPLEMENTADA;
}
