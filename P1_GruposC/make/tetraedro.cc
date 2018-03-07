#include <cstdio>
#include <iostream>
#include "tetraedro.h"


Tetraedro::Tetraedro(){
  reservar(4,4);

  //inicializacion de coordenadas

  vertices[0].x=0;
  vertices[0].y=3*MEDIDA;
  vertices[0].z=0;

  vertices[1].x=0;
  vertices[1].y=0;
  vertices[1].z=-MEDIDA;

  vertices[2].x=MEDIDA;
  vertices[2].y=0;
  vertices[2].z=0;

  vertices[3].x=0;
  vertices[3].y=0;
  vertices[3].z=MEDIDA;


  //inicializacion de caras
  cara[0].v_0=0;
  cara[0].v_1=3;
  cara[0].v_2=2;

  cara[1].v_0=0;
  cara[1].v_1=2;
  cara[1].v_2=1;

  cara[2].v_0=0;
  cara[2].v_1=1;
  cara[2].v_2=3;

  cara[3].v_0=3;
  cara[3].v_1=1;
  cara[3].v_2=2;
}
