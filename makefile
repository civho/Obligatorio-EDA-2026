todo: main.o editor.o linea.o
	g++ -Wall -o main main.o editor.o linea.o
main.o: main.c
	g++ -Wall -c main.c
editor.o: editor.h editor.cpp
	g++ -Wall -c editor.cpp
linea.o: linea.h linea.cpp
	g++ -Wall -c linea.cpp
	
# se deben agregar aca las reglas de compilacion para los modulos que agreguen
# agregar tambien las dependencias en la regla todo:
clean:
	rm -f main
	rm -f *.o

