#include <cstdio>
#include <iostream>

#include "cubo.h"

Cubo::Cubo(){
  reservar(8,12);
  //inicializacion de coordenadas

  vertices[0].x=0;
  vertices[0].y=MEDIDA;
  vertices[0].z=0;

  vertices[1].x=0;
  vertices[1].y=0;
  vertices[1].z=0;

  vertices[2].x=MEDIDA;
  vertices[2].y=0;
  vertices[2].z=0;

  vertices[3].x=MEDIDA;
  vertices[3].y=MEDIDA;
  vertices[3].z=0;

  vertices[4].x=MEDIDA;
  vertices[4].y=MEDIDA;
  vertices[4].z=MEDIDA;

  vertices[5].x=0;
  vertices[5].y=MEDIDA;
  vertices[5].z=MEDIDA;

  vertices[6].x=MEDIDA;
  vertices[6].y=0;
  vertices[6].z=MEDIDA;

  vertices[7].x=0;
  vertices[7].y=0;
  vertices[7].z=MEDIDA;



  //inicializacion de cara

  //Triangulo sup trasero
  cara[0].v_0=0;
  cara[0].v_1=3;
  cara[0].v_2=2;

  //triangulo inf trasero
  cara[1].v_0=2;
  cara[1].v_1=1;
  cara[1].v_2=0;

  //triangulo sup derecho
  cara[2].v_0=2;
  cara[2].v_1=3;
  cara[2].v_2=4;

  //triangulo inf der
  cara[3].v_0=4;
  cara[3].v_1=6;
  cara[3].v_2=2;

  //triangulo izq sup
  cara[4].v_0=1;
  cara[4].v_1=5;
  cara[4].v_2=0;

  //triangulo izq inf
  cara[5].v_0=7;
  cara[5].v_1=5;
  cara[5].v_2=1;

  //triangulo sup delantero
  cara[6].v_0=6;
  cara[6].v_1=4;
  cara[6].v_2=5;

  //triangulo inf delantero
  cara[7].v_0=5;
  cara[7].v_1=7;
  cara[7].v_2=6;

  //triangulo sup abajo
  cara[8].v_0=1;
  cara[8].v_1=2;
  cara[8].v_2=6;

  //triangulo inf abajo
  cara[9].v_0=6;
  cara[9].v_1=7;
  cara[9].v_2=1;

  //triangulo sup arriba
  cara[10].v_0=4;
  cara[10].v_1=3;
  cara[10].v_2=0;

  //triangulo inf arriba
  cara[11].v_0=0;
  cara[11].v_1=5;
  cara[11].v_2=4;
}
