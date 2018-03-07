#ifndef _ESCENA_H
#define _ESCENA_H
#include <stdio.h>
#include "ejes.h"
#include "modelo3D.h"
#include "tetraedro.h"
#include "cubo.h"
#include "casa.h"
#include "rombo.h"
#include "ObjetoRevolucion.h"
#include <string>
#include "ply.h"
#include "modos.h"

class Escena {
private:
// tama�o de los ejes
#define AXIS_SIZE 5000
Ejes ejes;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformaci�n de c�mara
	void change_projection();
	void change_observer();

public:
	//para ply

     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
private:
	//para tener un modelo 3D y controlar el modo
	string name;
	MODOS modo;
	modelo3D* model;
	Cubo cub;
	Tetraedro tetra;
	Casa ca;
	Color colores;
	Rombo rb;
	ObjetoRevolucion re;
	int n_rotaciones;
	bool tapas;
	Ply p;
	GLenum mode;
	void redimensionar(int newWidth,int newHeight,float n);
public:
	void Colores(); //para cambiar el array de colores
	void CambiaArchivo(string nm);
};
#endif
