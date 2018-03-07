#ifndef _MODELO3D_H
#define _MODELO3D_H
#include <cstdio>
#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include "modos.h"
using namespace std;

struct Puntos {

	float x,y,z;

Puntos& operator=(Puntos aux){
	x=aux.x;
	y=aux.y;
	z=aux.z;
	return *this;
}

};

struct Triangulo {
	unsigned int v_0,v_1,v_2; //indica los vertices
};
struct Color{
	float r,g,b;
};


class modelo3D{
protected:
	vector<Color> color_vert;//vector de colores

	vector<Color> color_chess_izq;
	vector<Color> color_chess_der;

	vector<Puntos> vertices;
	vector<Triangulo> cara;
	#define MEDIDA 50.0

public:

	modelo3D();
	// modelo3D(int num_vertices, int num_cara);
	void reservar(int num_vertices, int num_cara);
	vector<Puntos> getVertices();
	vector<Triangulo> getCara();
	vector<Color> getColor_vertice();
	void Colores(bool chess);
	//void drawPoints();
	//void drawLine();
	//void drawFILL();
	void drawChess();
	void Tipo(MODOS modo);
	void draw(GLenum mode);
	//examen
	void drawTodo();
	void ColoresRGB(int red, int green, int blue);

	void Escalar(float n);
};
#endif
