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
CXXFLAGS=  -std=c++11 -g -I/usr/include -I.

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
OBJECTS= practica1.o escena.o ejes.o modelo3D.o cubo.o tetraedro.o casa.o rombo.o ObjetoRevolucion.o file_ply_stl.o ply.o perro.o
# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : $(OBJECTS)
	$(CC) -o $@ $(CXXFLAGS) $(OBJECTS) $(LDFLAGS)



#read_ply.o: read_ply.cc file_ply_stl.cc
#	g++ -std=c++11 -g -DXWINDOWS -DSHM -I/usr/include -I. -c
#file_ply_stl.o: file_ply_stl.cc file_ply_stl.h vertex.h
#cubo.o : cubo.cc cubo.h
#	$(CC) -g cubo.cc cubo.h -o cubo.o


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
