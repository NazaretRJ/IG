#include <cstdio>
#include <iostream>
#include "rombo.h"


Rombo::Rombo(){
  reservar(5,10);

  //inicilaizacion de vertices
  vertices[0].x=MEDIDA;
  vertices[0].y=2*MEDIDA;
  vertices[0].z=MEDIDA;

  vertices[1].x=0;
  vertices[1].y=MEDIDA;
  vertices[1].z=0;

  vertices[2].x=MEDIDA;
  vertices[2].y=MEDIDA;
  vertices[2].z=MEDIDA;

  vertices[3].x=2*MEDIDA;
  vertices[3].y=MEDIDA;
  vertices[3].z=0;

  vertices[4].x=MEDIDA;
  vertices[4].y=MEDIDA;
  vertices[4].z=-MEDIDA;

  vertices[5].x=MEDIDA;
  vertices[5].y=0;
  vertices[5].z=0;

  //inicilizacion caras

  //cara delantera superior
  cara[0].v_0=0;
  cara[0].v_1=1;
  cara[0].v_2=2;

//cara delantera inf
  cara[1].v_0=1;
  cara[1].v_1=5;
  cara[1].v_2=2;

//cara lateral derecha sup
  cara[2].v_0=3;
  cara[2].v_1=0;
  cara[2].v_2=2;

//cara lateral derecha inf
  cara[3].v_0=3;
  cara[3].v_1=2;
  cara[3].v_2=5;

//cara trasera superior
  cara[4].v_0=4;
  cara[4].v_1=0;
  cara[4].v_2=3;

//cara trasera inferior
  cara[5].v_0=4;
  cara[5].v_1=3;
  cara[5].v_2=5;

//cara lateral izquiera sup
  cara[6].v_0=0;
  cara[6].v_1=4;
  cara[6].v_2=1;

//cara lateral izquierda inf
  cara[7].v_0=5;
  cara[7].v_1=1;
  cara[7].v_2=4;

//cuadrado interior tri sup
  cara[8].v_0=2;
  cara[8].v_1=3;
  cara[8].v_2=4;

//cuadrado interior tri inf
  cara[9].v_0=4;
  cara[9].v_1=1;
  cara[9].v_2=2;
}
