#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include "escena.h"

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    name = "";
    n_rotaciones = 3;
    tapas=true;
    modo = PUNTOS;
    model=&cub;
    mode=GL_POINT;
}

void Escena::CambiaArchivo(string nm){
  name=nm;
  Ply py(nm);
  p=py;
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}

//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
  cout<<"draw objects\n";


  glEnable(GL_CULL_FACE);

  switch (modo) {
    case PUNTOS:
      mode=GL_POINT;
      model->draw(mode);
    break;

    case LINEAS:
      mode=GL_LINE;
      model->draw(mode);
    break;

    case CHESS:
      model->drawChess();
    break;

    case RELLENO:
      mode=GL_FILL;
      model->draw(mode);
    break;
    //Examen
    case TODO:
    model->drawTodo();
    break;
  }

}



void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla" << Tecla1<< std::endl;
    switch(toupper(Tecla1)){
    case 'Q':
      return 1;
    break;
    case 'P': //Visualizar en modo puntos
      modo = PUNTOS;
      model->Tipo(modo);
    break;

    case 'L': //Visualizar en modo lineas
      modo = LINEAS;
      model->Tipo(modo);
    break;

    case 'F': //Visualizar en modo relleno
      modo = RELLENO;
      model->Tipo(modo);
    break;

    case 'C':
    //Visualizar en modo ajedrez
      modo = CHESS;
      model->Tipo(modo);
    break;


    case '1': //Activar tetraedro
      model=&tetra;
    break;

    case '2': //Activar Cubo
      model=&cub;
    break;

    case '3': //Activar PLY
      p.InicializarPLY(name);
      model=&p;

    break;

    case '4': //Activar Rev
      p.InicializarPLY(name);//extraemos datos del ply
      re.VerticesRevolucion(p.getVertices(),n_rotaciones,tapas);
      model=&re;
    break;

    case 'T':
      tapas=!tapas;
      if(tapas){
        re.PonerTapa(re.primer_vert,re.ult_vertice,p.getVertices());
      }
      else{
        re.QuitarTapa();
      }
      model=&re;
      model->Tipo(modo);
    break;

    case '+':
      n_rotaciones++;
      p.InicializarPLY(name);
      re.VerticesRevolucion(p.getVertices(),n_rotaciones,tapas);
      model=&re;
      //repintar
      model->Escalar(20);
      model->Tipo(modo);
    break;

    case '-':
      n_rotaciones--;
      p.InicializarPLY(name);
      re.VerticesRevolucion(p.getVertices(),n_rotaciones,tapas);
      model=&re;
      //repintar
      model->Escalar(20);
      model->Tipo(modo);
    break;

    case 'H': //Activar Casa
      model=&ca;
    break;

    case 'R': //Activar Rombo
      model=&rb;
    break;

    //para ver más grande
    case 'M' :
      model->Escalar(20);
      model->Tipo(modo);
    break;

    case 'V':
      re.PedirVertices();
      model=&re;
      model->Tipo(modo);
    break;

    //Examen práctica
    case 'A': //activar fill,lines y points
      modo = TODO;
      model->Tipo(modo);
    break;

    //Examen práctica 2
    case 'E': //elije eje de rotación
      char eje;
      cout<<"Eje sobre el que quiere que gire:";
      cin>>eje;
      eje=toupper(eje);
      if(eje=='Y'){
        re.Y=true;
        re.Z=false;
        re.X=false;
      }
      else{
        if(eje='X'){
          re.Y=false;
          re.Z=false;
          re.X=true;
        }

        else{
          re.Y=false;
          re.Z=false;
          re.X=true;
        }
      }
      p.InicializarPLY(name);
      re.VerticesRevolucion(p.getVertices(),n_rotaciones,tapas);
      model=&re;
      //repintar
      model->Escalar(20);
      model->Tipo(modo);
    break;

  }
  //obligamos a volver a pintar
  glutPostRedisplay();
  return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}
//para redimensionar a nuestra manera

void Escena::redimensionar(int newWidth,int newHeight,float n){
change_projection();
Width=newWidth/n;//coorednadas de pantallas
Height=newWidth/n;
glViewport(0,0,Width,Height);
}

//**************************************************************************
// Funcion para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}
