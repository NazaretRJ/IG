#include "casa.h"

Casa::Casa(){
  reservar(10,16);

  vertices[0].x=0;
  vertices[0].y=0;
  vertices[0].z=MEDIDA;

  vertices[1].x=0;
  vertices[1].y=MEDIDA;
  vertices[1].z=MEDIDA;

  vertices[2].x=MEDIDA/2;
  vertices[2].y=MEDIDA*2;
  vertices[2].z=MEDIDA;

  vertices[3].x=MEDIDA;
  vertices[3].y=MEDIDA;
  vertices[3].z=MEDIDA;

  vertices[4].x=MEDIDA;
  vertices[4].y=0;
  vertices[4].z=MEDIDA;

  vertices[5].x=MEDIDA;
  vertices[5].y=MEDIDA;
  vertices[5].z=0;

  vertices[6].x=MEDIDA;
  vertices[6].y=0;
  vertices[6].z=0;

  vertices[7].x=0;
  vertices[7].y=0;
  vertices[7].z=0;

  vertices[8].x=0;
  vertices[8].y=MEDIDA;
  vertices[8].z=0;

  vertices[9].x=MEDIDA/2;
  vertices[9].y=MEDIDA*2;
  vertices[9].z=0;


//cara delantera tejado
  cara[0].v_0=3;
  cara[0].v_1=2;
  cara[0].v_2=1;

//cara delantera triangulo inferior
  cara[1].v_0=1;
  cara[1].v_1=0;
  cara[1].v_2=4;

//cara delantera triangulo superior
  cara[2].v_0=4;
  cara[2].v_1=3;
  cara[2].v_2=1;

//cara lateral derecha sup
  cara[3].v_0=6;
  cara[3].v_1=5;
  cara[3].v_2=3;

//cara lateral derecha inf
  cara[4].v_0=3;
  cara[4].v_1=4;
  cara[4].v_2=6;

//cara lateral der tejado sup
  cara[5].v_0=5;
  cara[5].v_1=9;
  cara[5].v_2=2;

//cara lateral der tejado inf
  cara[6].v_0=2;
  cara[6].v_1=3;
  cara[6].v_2=5;

//cara trasera sup
  cara[7].v_0=7;
  cara[7].v_1=8;
  cara[7].v_2=5;

//cara trasera inferior
  cara[8].v_0=5;
  cara[8].v_1=6;
  cara[8].v_2=7;

//cara trasera tejado
  cara[9].v_0=8;
  cara[9].v_1=9;
  cara[9].v_2=5;

//cara lateral izq superior
  cara[10].v_0=0;
  cara[10].v_1=1;
  cara[10].v_2=8;

//cara lateral izq inferior
  cara[11].v_0=8;
  cara[11].v_1=7;
  cara[11].v_2=0;

//cara lateral izq tejado sup
  cara[12].v_0=1;
  cara[12].v_1=2;
  cara[12].v_2=9;

//cara lateral izq tejado inf
  cara[13].v_0=9;
  cara[13].v_1=8;
  cara[13].v_2=1;

//cara inferior sup
  cara[14].v_0=0;
  cara[14].v_1=7;
  cara[14].v_2=6;

//cara inferior inf
  cara[15].v_0=6;
  cara[15].v_1=4;
  cara[15].v_2=0;

}
