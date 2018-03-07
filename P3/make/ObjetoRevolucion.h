#ifndef _OBJETOREVOLUCION_H
#define _OBJETOREVOLUCION_H

#include"modelo3D.h"


class ObjetoRevolucion : public modelo3D {
  #define PI  3.14159
private:
float  P_Radianes(float ang);//pasa a radiantes
int empieza_tapa;
bool tapa_visible;

public:
  Puntos primer_vert;
  Puntos ult_vertice;

ObjetoRevolucion();
ObjetoRevolucion(vector<Puntos> v , int n,bool poner_tapa);
//void DrawSinTapaSup();
//void DrawSinTapaInf();

//para rotar el vertice
Puntos RotarY(Puntos &v,float ang);

//Metodo para construir el objeto a partir de unos veritces
void VerticesRevolucion(vector<Puntos> v , int n,bool poner_tapa);


void PonerTapa(Puntos vert,vector<Puntos> v);

void QuitarTapa();


//void ColorearRevolucion();

//float P_Radianes(float ang);
void drawChess();
void drawTodo();
vector<Triangulo> Cara_Sin_Tapa(int cota_inf,int cota_sup);
void drawChessST(int cota_inf,int cota_sup);
//void drawFILLST(int cota_inf,int cota_sup);
//void drawLineST(int cota_inf,int cota_sup);
//void drawPointsST(int cota_inf,int cota_sup);
void drawTodoST(int cota_inf,int cota_sup);
void draw(GLenum mode);
void drawST(GLenum mode,int cota_inf,int cota_sup);
void PedirVertices();
void PonerTapa(Puntos vert_sup,Puntos vert_inf,vector<Puntos> v);
vector<Color> Colores_Sin_Tapa(int cota_inf,int cota_sup,const vector<Color>& orig);
};
#endif
