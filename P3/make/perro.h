#ifndef _PERRO_H
#define _PERRO_H
#include"cubo.h"
#include"tetraedro.h"
#include"ply.h"
#include <GL/gl.h>
#include <GL/glut.h>

enum MODO_DIBUJO{
  AJED,NORMAL,ALL
};


class Perro{
private:
  //angulos
  float gamma,gamma1,gamma2,gamma3;//pie
  float beta,beta1,beta2,beta3;//pata abajo
  float w,w1,w2,w3; //pata
  float delta;//cara
  float omega;//cabeza,cuello
  float alfa;//cola
  const float ANG_MAX_PATAS=90;
  const float ANG_MIN_PATAS=-25;
  const float ANG_MAX = 90;
  const float ANG_MIN = -90;
  const float ANG_MIN_CARA = -10;
  const float ANG_MAX_CARA = 5;
  const float MAX_LENG = 15;
  const float MIN_LENG = 0;
  //altura
  float h;//cola
  const float LENG = 2.5;
  float lengua;
  bool sentido_cara,sentido_cabeza,sentido_cola,sentido_pata,sentido_pata_abajo,sentido_pie,sentido_lengua;
  //objetos
  Cubo cub;
  Tetraedro triangulo;
  Ply esfera;
  GLenum mode;

public:
  Perro();
  void draw(GLenum mod);
  void drawChess();
  void drawTodo();
  void triangulo_unidad(MODO_DIBUJO tipo);
  void cubo_unidad(MODO_DIBUJO tipo);
  void pata_abajo(MODO_DIBUJO tipo,float abajo,float pie);
  void pata(MODO_DIBUJO tipo,float p,float abajo,float pie);
  void cara(MODO_DIBUJO tipo);
  void cabeza(MODO_DIBUJO tipo);
  void cola(MODO_DIBUJO tipo);
  void pecho(MODO_DIBUJO tipo);
  void dibujar_perro(MODO_DIBUJO tipo);//METER CABEZA
  void animar();
  void hocico(MODO_DIBUJO tipo);
  void animar_cola(int velocidad);
  void animar_pata(int velocidad);
  void modificarCola(float alt);
  void animar_patas_abajo();
  void animar_pie();
  void animar_cara();
  void animar_cabeza();
  void animar_lengua();
};

#endif
