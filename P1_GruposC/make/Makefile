# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica1

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -I/usr/include -I.
CXXFLAGS=  -g -I/usr/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
#
CC = g++

# definicion de objetos
#
OBJECTS= practica1.o escena.o ejes.o modelo3D.o cubo.o tetraedro.o casa.o rombo.o
# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : $(OBJECTS)
	$(CC) -o $@ $(CXXFLAGS) $(OBJECTS) $(LDFLAGS)

#cubo.o : cubo.cc cubo.h
#	$(CC) -g cubo.cc cubo.h -o cubo.o

#tetraedro.o : tetraedro.h tetraedro.cc
#	$(CC) -g tetraedro.cc tetraedro.h -o tetraedro.o

#modelo3D.o : modelo3D.h modelo3D.cc tetraedro.h cubo.h
#	$(CC) -g modelo3D.cc modelo3D.h tetraedro.h cubo.h -o modelo3D.o

#escena.o : escena.cc escena.h modelo3D.o
#	$(CC) -g escena.cc escana.h modelo3D.o -o escena.o

#
#
clean:
	rm -f *.o
	rm -f $(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *
