#include <vector>
#include <iostream>
#include <string>
#include "ply.h"
#include "vertex.h"

Ply::Ply(string name){

  InicializarPLY(name);

}

void Ply::InicializarPLY(string name){
  vector<_vertex3f> v;
  vector<_vertex3i> tri;

  vertices.clear();
  cara.clear();

  cout<<"empezamos ply"<<endl;
  if(fi.open(name)){
    fi.read(v,tri);
  }
//  cout<<"fin de leer ply"<<endl;
  fi.close();
  //  cout<<"cerrar ply"<<endl;
  Puntos aux;

  vertices.clear();
  cara.clear();

  for(int i = 0;i<v.size();i++){
    aux.x=v[i].x;
    aux.y=v[i].y;
    aux.z=v[i].z;
    vertices.push_back(aux);
  }
  //colores y agrandar bichos

  //cout<<"fin de meter vertices"<<endl;
  Triangulo t;
  for(int i = 0;i<tri.size();i++){
    t.v_0=tri[i]._0;
    t.v_1=tri[i]._1;
    t.v_2=tri[i]._2;
    cara.push_back(t);
  }
  //cout<<"fin de meter caras"<<endl;
  //cout<<"n caras: "<<cara.size()<<"n vert: "<<vertices.size();

  color_vert.clear();
	color_chess_izq.clear();
	color_chess_der.clear();

  Colores(true);//inicializamos colores vertices
  Colores(false);//inicializamos modo ajedrez
}

Ply& Ply::operator=(const Ply& p){
  vertices.clear();
  cara.clear();
  color_vert.clear();//vector de colores

	color_chess_izq.clear();
  color_chess_der.clear();

  vertices=p.vertices;
  cara=p.cara;

  color_vert=p.color_vert;

  color_chess_izq=p.color_chess_izq;
  color_chess_der=p.color_chess_der;

  return *this;

}
