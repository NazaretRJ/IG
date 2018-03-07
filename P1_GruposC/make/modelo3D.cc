#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "modelo3D.h"

modelo3D::modelo3D(){}

void modelo3D::reservar(int num_vertices, int num_cara){
	 //reservar espacio
	vertices.resize(num_vertices);
	cara.resize(num_cara);
	color_vert.resize(num_vertices);
  //para chess
  color_chess_der.resize(color_vert.size());
  color_chess_izq.resize(color_vert.size());
  //inicializamos los colores
	Colores(false);
  Colores(true);
}

void modelo3D::Colores(bool chess){

	if(!chess){
		for(int i = 0 ; i< color_vert.size(); i++){
			//por defecto,pintamos en azul
			color_vert[i].r=0;
			color_vert[i].g=0;
			color_vert[i].b=1;
		}
  }
	else{ //modo ajedrez

		for(int i = 0 ; i< color_vert.size(); i++){

				color_chess_izq[i].r=1;
				color_chess_izq[i].g=0;
				color_chess_izq[i].b=0;
				color_chess_der[i].r=0;
				color_chess_der[i].g=1;
				color_chess_der[i].b=0;
		}

	}

}

vector<Puntos> modelo3D::getVertices(){
	return vertices;
}

vector<Triangulo> modelo3D::getCara(){
	return cara;
}
vector<Color> modelo3D::getColor_vertice(){
	return color_vert;
}

void modelo3D::drawPoints(){
  glEnableClientState(GL_COLOR_ARRAY);
  //pasar el vertice de los colores para pintar
  //glColorPointer (size (si son 3 o 4 colores -> rgb o rgba),type,offset,pointer)
  glColorPointer(3,GL_FLOAT,0,&color_vert[0]);
  //habilitar array
	glEnableClientState(GL_VERTEX_ARRAY);
  //pasar el array de datos
  //3 por coordenadas [Puntos] (x y z)
	glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  //decirle de que manera queremos que pinte
  glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
	//mandar los datos a pintar
  glDrawElements(GL_TRIANGLES,3*cara.size(),GL_UNSIGNED_INT,&cara[0]);
}

void modelo3D::drawLine(){
  glEnableClientState(GL_COLOR_ARRAY);
  glColorPointer(3,GL_FLOAT,0,&color_vert[0]);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glDrawElements(GL_TRIANGLES,3*cara.size(),GL_UNSIGNED_INT,&cara[0]);
}

void modelo3D::drawFILL(){
  glEnableClientState(GL_COLOR_ARRAY);
  glColorPointer(3,GL_FLOAT,0,&color_vert[0]);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glDrawElements(GL_TRIANGLES,3*cara.size(),GL_UNSIGNED_INT,&cara[0]);

}

void modelo3D::drawChess(){
  //si están aquí no pasa nada porque los datos se mandan antes de que se destruyan
    vector<Triangulo> car_pares,car_imp;

  for(int i = 0; i<cara.size();i++){
    if(i%2==0)
      car_pares.push_back(cara[i]);
    else
      car_imp.push_back(cara[i]);
  }

  glEnableClientState(GL_COLOR_ARRAY);
  //especificamos el vector de colores
  glColorPointer(3,GL_FLOAT,0,&color_chess_izq[0]);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  //pintamos caras impares
    glDrawElements(GL_TRIANGLES, 3*car_imp.size(),GL_UNSIGNED_INT,&car_imp[0]);

  //glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  //ponemos el nuevo color
  glColorPointer(3,GL_FLOAT,0,&color_chess_der[0]);
  //pintamos caras pares
  glDrawElements(GL_TRIANGLES, 3*car_pares.size(),GL_UNSIGNED_INT,&car_pares[0]);

}

//Examen
void modelo3D::drawTodo(){
  ColoresRGB(1,0,0);//puntos rojos
  drawPoints();
  ColoresRGB(0,1,0);//lineas verdes
  drawLine();
  ColoresRGB(0,0,1);//contenido azul
  drawFILL();
}

void modelo3D::ColoresRGB(int red, int green, int blue){

  for(int i = 0 ; i < color_vert.size(); i++){
    color_vert[i].r=red;
    color_vert[i].g=green;
    color_vert[i].b=blue;
  }
  glEnableClientState(GL_COLOR_ARRAY);
  glColorPointer(3,GL_UNSIGNED_INT,0,&color_vert[0]);
}

//Examen 2

void modelo3D::drawLP(){
	glDisable(GL_CULL_FACE);//ahora se ven las caras de detrás
	//para distinguir ponemos dos colores
	ColoresRGB(1,0,0);//puntos rojos
	drawPoints();
	ColoresRGB(0,1,0);//lineas verdes
	drawLine();
}
