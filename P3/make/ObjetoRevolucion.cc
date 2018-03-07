#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include<cmath>
#include "ObjetoRevolucion.h"
#include<assert.h>

ObjetoRevolucion::ObjetoRevolucion(){
  empieza_tapa=0;
  tapa_visible=false;
}

ObjetoRevolucion::ObjetoRevolucion(vector<Puntos> v , int n,bool poner_tapa){
  empieza_tapa=0;
  tapa_visible=true;

  VerticesRevolucion(v,n,poner_tapa);
}


Puntos ObjetoRevolucion::RotarY(Puntos &v,float ang){
  Puntos aux;
  ang=(ang*PI)/180;
  aux.x=v.x*cos(ang) + v.z*sin(ang);
  aux.y=v.y;
  aux.z=v.x*(-sin(ang)) + v.z * cos(ang);
  return aux;
}

void ObjetoRevolucion::PedirVertices(){
  int n;
  cout<<"Numero de vertices que va a meter"<<endl;
  cin>>n;
  if(n>0){
    Puntos aux;
    vector<Puntos> v;
    for(int i=0;i<n;i++){
      cout<<"coordena x"<<endl;
      cin>>aux.x;

      cout<<"coordena y"<<endl;
      cin>>aux.y;

      cout<<"coordena z"<<endl;
      cin>>aux.z;

      v.push_back(aux);
    }
    VerticesRevolucion(v,3,true);
  }
  else{
    cout<<"argumento no valido"<<endl;
  }
}

void ObjetoRevolucion::VerticesRevolucion(vector<Puntos> v , int n_rotaciones,bool poner_tapa){
  assert(v.size()>0);
  bool hay_tapa_sup=false;
  bool hay_tapa_inf=false;
  cout<<"antes clear vertices"<<vertices.size();
  vertices.clear();
  cara.clear();
  cout<<"despues clear"<<vertices.size();

  //vertices=v; si lo quitamos,no se repite los vertices iniciales.


if(v[0].x==0 && v[0].z==0){//esta sobre eje y
  hay_tapa_sup=true;
  primer_vert=v[0];
  v.erase(v.begin());  //quitamos el primer vertice
}
else{
  //para tapa
  primer_vert.y=v[0].y;
  primer_vert.x=0;
  primer_vert.z=0;
}

if(v.back().x==0 && v.back().z==0){//esta sobre eje y
  hay_tapa_inf=true;
  ult_vertice=v.back();
  v.erase(v.begin());  //quitamos el primer vertice
}
else{
  //para tapa
  ult_vertice.y=v.back().y;
  ult_vertice.x=0;
  ult_vertice.z=0;
}

  Puntos aux;
  float ang=360.0/n_rotaciones;
  float ang_actual=ang;
  int mod=n_rotaciones*v.size();
  int i;
  vertices=v;
  Triangulo tri;
  for(int k=1;k<n_rotaciones;k++){
    vertices.push_back(RotarY(v[0],ang_actual));

    for(int j=1;j<v.size();j++){
      i=(k*v.size()+j);
      vertices.push_back(RotarY(v[j],ang_actual));
      //abajo
      tri.v_0=i;
      tri.v_2=(i-v.size()-1);
      tri.v_1=(i-v.size());
      cara.push_back(tri);
      //arriba
      //tri.v_0=i;
      tri.v_2=(i-1);
      tri.v_1=(i-v.size()-1);
      cara.push_back(tri);

    }
  ang_actual+=ang;
  }

  for(int j=1;j<v.size();j++){
    i=(n_rotaciones*v.size()+j);
    //abajo
    tri.v_0=i%mod;
    tri.v_2=(i-v.size()-1)%mod;
    tri.v_1=(i-v.size())%mod;
    cara.push_back(tri);
    //arriba
    //tri.v_0=i;
    tri.v_2=(i-1)%mod;
    tri.v_1=(i-v.size()-1)%mod;
    cara.push_back(tri);

  }

  if(poner_tapa){
    PonerTapa(primer_vert,ult_vertice,v);
  }




color_vert.clear();
color_chess_izq.clear();
color_chess_der.clear();

Colores(true);
Colores(false);

}

void ObjetoRevolucion::PonerTapa(Puntos vert_sup,Puntos vert_inf,vector<Puntos> v){
  cout<<"tapa "<<endl;
  if(empieza_tapa != 0){//ya creada
    cout<<"creada"<<endl;
    tapa_visible=true;
  }
  else{//no credaas las tapas
    int tam=vertices.size();
    int aux;
    tapa_visible=true;
    empieza_tapa=cara.size(); //marca donde empieza la cara sup
    //metemos el vertice de la tapa
    int pos_vert=vertices.size();
    vertices.push_back(vert_sup);
    Triangulo tri;
    //tapa de arriba
    for(int i = 0;i<tam;i+=v.size()){
      tri.v_0=pos_vert;
      tri.v_1=i;
      tri.v_2=(i+v.size())%tam;

      cara.push_back(tri);
    }
    pos_vert=vertices.size();
    vertices.push_back(vert_inf);
    for(int i= v.size()-1 ;i<tam; i+=v.size()){
      tri.v_0=i;
      tri.v_1=pos_vert;
      tri.v_2=(i+v.size())%tam;

      cara.push_back(tri);
    }

  }
cout<<"fin tapa"<<endl;
}

void ObjetoRevolucion::QuitarTapa(){
  cout<<"quitar tapa"<<endl;
  tapa_visible=false;
}



void ObjetoRevolucion::drawST(GLenum mode,int cota_inf,int cota_sup){
  vector<Triangulo> aux;

  aux=Cara_Sin_Tapa(cota_inf,cota_sup);

  glEnableClientState(GL_COLOR_ARRAY);
  //pasar el vertice de los colores para pintar
  //glColorPointer (size (si son 3 o 4 colores -> rgb o rgba),type,offset,pointer)
  vector<Color> color_aux;
  color_aux=Colores_Sin_Tapa(cota_inf,cota_sup,color_vert);

  glColorPointer(3,GL_FLOAT,0,&color_aux[0]);
  //habilitar array
  glEnableClientState(GL_VERTEX_ARRAY);
  //pasar el array de datos
  //3 por coordenadas [Puntos] (x y z)
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  //decirle de que manera queremos que pinte
  glPolygonMode(GL_FRONT_AND_BACK,mode);
  //mandar los datos a pintar
  glDrawElements(GL_TRIANGLES,3*aux.size(),GL_UNSIGNED_INT,&aux[0]);


}

void ObjetoRevolucion::drawChessST(int cota_inf,int cota_sup){
  //si están aquí no pasa nada porque los datos se mandan antes de que se destruyan
  vector<Triangulo> aux;
  aux=Cara_Sin_Tapa(cota_inf,cota_sup);
  vector<Color> color_aux_der,color_aux_izq;
  color_aux_izq=Colores_Sin_Tapa(cota_inf,cota_sup,color_aux_izq);
  color_aux_der=Colores_Sin_Tapa(cota_inf,cota_sup,color_chess_der);
  vector<Triangulo> car_pares,car_imp;

  for(int i = 0; i<aux.size();i++){
    if(i%2==0)
      car_pares.push_back(aux[i]);
    else
      car_imp.push_back(aux[i]);
  }
  glEnableClientState(GL_COLOR_ARRAY);
  //especificamos el vector de colores
  glColorPointer(3,GL_FLOAT,0,&color_aux_izq[0]);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  //pintamos caras impares
    glDrawElements(GL_TRIANGLES, 3*car_imp.size(),GL_UNSIGNED_INT,&car_imp[0]);

  //glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  //ponemos el nuevo color
  glColorPointer(3,GL_FLOAT,0,&color_aux_der[0]);
  //pintamos caras pares
  glDrawElements(GL_TRIANGLES, 3*car_pares.size(),GL_UNSIGNED_INT,&car_pares[0]);
}

void ObjetoRevolucion::drawTodoST(int cota_inf,int cota_sup){
  ColoresRGB(1,0,0);//puntos rojos
  drawST(GL_POINT,cota_inf,cota_sup);
  ColoresRGB(0,1,0);//lineas verdes
  drawST(GL_LINE,cota_inf,cota_sup);
  ColoresRGB(0,0,1);//contenido azul
  drawST(GL_FILL,cota_inf,cota_sup);
}

vector<Triangulo> ObjetoRevolucion::Cara_Sin_Tapa(int cota_inf,int cota_sup) {
  vector<Triangulo> aux;

    for(int i = 0; i<=cota_inf;i++){
      aux.push_back(cara[i]);
    }
    for(int i = cota_sup; i<cara.size();i++){
      aux.push_back(cara[i]);
    }
  return aux;
}

vector<Color> ObjetoRevolucion::Colores_Sin_Tapa(int cota_inf,int cota_sup,const vector<Color>& orig){
  vector<Color> aux;

  for(int i = 0; i<=cota_inf;i++){
    if(i!=cota_sup && i!=cota_inf)
    aux.push_back(orig[i]);
  }
  return aux;

}

void ObjetoRevolucion::draw(GLenum mode){
  if(tapa_visible == true){
    draw(mode);
  }
  else{
    if(tapa_visible == false){
      drawST(mode,empieza_tapa,cara.size());
    }
  }

}


void ObjetoRevolucion::drawChess(){
  if(tapa_visible == true){
    drawChess();
  }
  else{
    if(tapa_visible == false){
      drawChessST(empieza_tapa,cara.size());
    }

  }

}

void ObjetoRevolucion::drawTodo(){
  if(tapa_visible == true){
    drawTodo();
  }
  else{
    if(tapa_visible == false){
      drawTodoST(empieza_tapa,cara.size());
    }
  }
}
