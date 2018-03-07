#include"perro.h"
#include <unistd.h>

Perro::Perro(){
  gamma=0;gamma1=0;gamma2=0;gamma3=0;
  beta=0;beta1=0;beta2=0;beta3=0;
  w=0;w1=0,w2=0,w3=0;
  omega=0;
  delta=0;
  alfa=0;
  h=1;
  sentido_cola=0;
  sentido_pata=0;
  sentido_pata_abajo=0;
  sentido_pie=0;
  sentido_cara=0;
  sentido_cabeza=0;
  sentido_lengua=1;
  esfera.InicializarPLY("esfera.ply");
  lengua=0;
}


void Perro::cubo_unidad(MODO_DIBUJO tipo){
  glPushMatrix();
    glTranslatef(-0.5,-0.5,-0.5);
    glScalef(1.0/50,1.0/50,1.0/50);
  if(tipo == NORMAL)
    cub.draw(mode);
  else{
    if(tipo == AJED)
      cub.drawChess();
    else
      cub.drawTodo();
  }
  glPopMatrix();


}

void Perro::pata_abajo(MODO_DIBUJO tipo,float abajo ,float pie){

  glPushMatrix();
    glRotatef(abajo,0,0,1);
    glTranslatef(0,-10,-5);
    //palo
    glPushMatrix();
      glTranslatef(0,0,5);
      glScalef(10,20,10);
      cubo_unidad(tipo);
    glPopMatrix();
    //Esfera y pie
    glPushMatrix();
      glTranslatef(0,-10,0);
      //esfera
      glPushMatrix();
        glTranslatef(0,0,5);
        glScalef(10,10,10);
        if(tipo == NORMAL)
          esfera.draw(mode);
        else{
          if(tipo == AJED)
            esfera.drawChess();
          else
            esfera.drawTodo();
        }
      glPopMatrix();

      //pie
      glPushMatrix();
        glRotatef(pie,0,0,1);
        glTranslatef(7.5,-10,7.5);
        glScalef(15,10,15);
        cubo_unidad(tipo);
      glPopMatrix();

    glPopMatrix();

}

void Perro::pata(MODO_DIBUJO tipo,float p,float abajo,float pie){
  glPushMatrix();
    glRotatef(p,0,0,1);
    glTranslatef(5,-10,5);

    //esfera y pata abajo
    glPushMatrix();
      glTranslatef(0,-10,0);
      //Esfera
      glPushMatrix();
        glScalef(10,10,10);
        if(tipo == NORMAL)
          esfera.draw(mode);
        else{
          if(tipo == AJED)
            esfera.drawChess();
          else
            esfera.drawTodo();
        }
      glPopMatrix();
      //Pata
      glPushMatrix();
        pata_abajo(tipo,abajo,pie);
      glPopMatrix();
    glPopMatrix();

    //palo
    glPushMatrix();
      glScalef(10,20,10);
      cubo_unidad(tipo);
    glPopMatrix();

  glPopMatrix();

}

void Perro::cara(MODO_DIBUJO tipo){
  glPushMatrix();
    glRotatef(delta,0,0,1);
    //cabeza
    glPushMatrix();
      glTranslatef(15,-10,15);
      glScalef(30,20,30);
      cubo_unidad(tipo);
    glPopMatrix();

    //hocico
    glPushMatrix();
      glTranslatef(30,-20,10);
      hocico(tipo);
    glPopMatrix();

    //oreja1
    glPushMatrix();
      glTranslatef(0,0,25);
      glScalef(5,10,5);
      triangulo_unidad(tipo);
    glPopMatrix();

    //oreja2
    glPushMatrix();
      glTranslatef(0,0,5);
      glScalef(5,10,5);
      triangulo_unidad(tipo);
    glPopMatrix();

  glPopMatrix();
}


void Perro::hocico(MODO_DIBUJO tipo){
  glPushMatrix();
    //cubo
    glPushMatrix();
      glTranslatef(5,5,5);
      glScalef(10,10,10);
      cubo_unidad(tipo);
    glPopMatrix();
    //Esfera
    glPushMatrix();
      glTranslatef(10,10,5);
      glScalef(2.5,2.5,2.5);
      if(tipo == NORMAL)
        esfera.draw(mode);
      else{
        if(tipo == AJED)
          esfera.drawChess();
        else
          esfera.drawTodo();
      }
    glPopMatrix();

    //lengua
    if(lengua>0){
      glPushMatrix();
          glTranslatef(10,0,0);
          glTranslatef(lengua/2,5,5);
          glScalef(lengua,LENG,LENG);
          cubo_unidad(tipo);
      glPopMatrix();
    }

  glPopMatrix();

}

void Perro::triangulo_unidad(MODO_DIBUJO tipo){
  glPushMatrix();
    glScalef(1.0/50,1.0/50,1.0/50);
    if(tipo == NORMAL)
      triangulo.draw(mode);
    else{
      if(tipo == AJED)
        triangulo.drawChess();
      else
        triangulo.drawTodo();
    }
  glPopMatrix();
}

void Perro::cabeza(MODO_DIBUJO tipo){
  glPushMatrix();
    glTranslatef(5,0,15);
    glRotatef(omega,0,1,0);
    glTranslatef(-5,0,-15);
    //cuello
    glPushMatrix();
      glTranslatef(5,-5,15);
      glScalef(10,10,10);
      cubo_unidad(tipo);
    glPopMatrix();
    //cara
    glPushMatrix();
      glTranslatef(0,20,0);
      cara(tipo);
    glPopMatrix();

  glPopMatrix();

}

void Perro::pecho(MODO_DIBUJO tipo){

  glPushMatrix();
    glTranslatef(25,15,15);
    glScalef(50,30,30);
    cubo_unidad(tipo);
  glPopMatrix();

}

void Perro::dibujar_perro(MODO_DIBUJO tipo){
  cout<<"dibujar_perro"<<endl;
  glPushMatrix();
    glPushMatrix();
        pecho(tipo);
    glPopMatrix();

    //pata delantera izquierda
    glPushMatrix();
      glTranslatef(30,15,30);
      pata(tipo,w,beta,gamma);
    glPopMatrix();

    //pata delantera derecha
    glPushMatrix();
      glTranslatef(30,15,-10);
      pata(tipo,w2,beta1,gamma1);
    glPopMatrix();

    //pata trasera derecha
    glPushMatrix();
      glTranslatef(0,15,-10);
      pata(tipo,w1,beta2,gamma2);
    glPopMatrix();

    //pata trasera izq
    glPushMatrix();
      glTranslatef(0,15,30);
      pata(tipo,w3,beta3,gamma3);
    glPopMatrix();

  glPopMatrix();

  //cabeza
  glPushMatrix();
    glTranslatef(40,40,0);
    cabeza(tipo);
  glPopMatrix();

  //cola
  glPushMatrix();
    glTranslatef(0,35,15);
    cola(tipo);
  glPopMatrix();


}


void Perro::cola(MODO_DIBUJO tipo){
  glPushMatrix();

    glRotatef(alfa,1,0,0);

    //palo
    glPushMatrix();
      glScalef(1,h,1);//para alargar la cola
      glTranslatef(0,15,0);
      glScalef(10,30,10);
      cubo_unidad(tipo);
    glPopMatrix();

    //esfera
    glPushMatrix();
      glScalef(10,10,10);
      if(tipo == NORMAL)
        esfera.draw(mode);
      else{
        if(tipo == AJED)
          esfera.drawChess();
        else
          esfera.drawTodo();
      }
    glPopMatrix();

  glPopMatrix();

}


void Perro::draw(GLenum mod){
  mode=mod;
  dibujar_perro(NORMAL);
}

void Perro::drawChess(){
  dibujar_perro(AJED);
  //pata(AJED,0,0,0);
}

void Perro::drawTodo(){
  dibujar_perro(ALL);
}

void Perro::animar_cola(int velocidad){
  if(velocidad < 100)
    velocidad = 100;
  //sleep(velocidad);
  if(sentido_cola == 1){
    alfa++;
    if(alfa == ANG_MAX){
      sentido_cola = 0;
    }
  }
  else{
    alfa--;
    if(alfa == ANG_MIN)
      sentido_cola = 1;
  }
}

void Perro::animar_pata(int velocidad){
  /*if(velocidad < 100)
    velocidad = 100;
  //sleep(velocidad);*/

  if(sentido_pata==1){
    w++; w2++;
    w1--; w3--;
    if(w == ANG_MAX || w2 == ANG_MIN_PATAS || w1 == ANG_MAX || w3 == ANG_MIN_PATAS){
      sentido_pata=0;
    }
  }
  else{
    w--; w2--;
    w1++; w3++;
    if(w == ANG_MIN_PATAS || w2 == ANG_MAX_PATAS|| w1 == ANG_MIN_PATAS || w3 == ANG_MAX){
      sentido_pata=1;
    }
  }
  animar_patas_abajo();
  animar_pie();
}


void Perro::animar_patas_abajo(){

    if(sentido_pata_abajo==1){
      beta++; beta3++;
      beta1--; beta2--;
      if(beta1 == ANG_MIN || beta2 == ANG_MAX || beta == ANG_MAX || beta3 == ANG_MIN){
        sentido_pata_abajo=0;
      }
    }
    else{
      beta--; beta3--;
      beta1++; beta2++;
      if(beta1 == ANG_MAX || beta2 == ANG_MIN|| beta == ANG_MIN || beta3 == ANG_MAX){
        sentido_pata_abajo=1;
      }
    }
}

void Perro::animar_pie(){
  if(sentido_pie==1){
    gamma++; gamma2++;
    gamma1--; gamma3--;
    if(gamma == ANG_MAX || gamma2 == ANG_MIN || gamma1 == ANG_MAX || gamma3 == ANG_MIN){
      sentido_pie=0;
    }
  }
  else{
    gamma--; gamma2--;
    gamma1++; gamma3++;
    if(gamma == ANG_MIN || gamma2 == ANG_MAX|| gamma1 == ANG_MIN || gamma3 == ANG_MAX){
      sentido_pie=1;
    }
  }
}


void Perro::modificarCola(float alt){
  if(alt>=1.0)
    h=alt;

}

void Perro::animar_cabeza(){
  if(sentido_cabeza==1){
    omega++;
    if(omega == ANG_MAX)
      sentido_cabeza=0;
  }

  else{
    omega--;
    if(omega == ANG_MIN )
      sentido_cabeza=1;
  }


}

void Perro::animar_cara(){
  if(sentido_cabeza==1){
    delta++;
    if(delta == ANG_MAX_CARA)
      sentido_cabeza=0;
  }

  else{
    delta--;
    if(delta == ANG_MIN_CARA )
      sentido_cabeza=1;
  }

}

void Perro::animar_lengua(){
  if(sentido_lengua==1){
    lengua++;
    if(lengua == MAX_LENG)
      sentido_lengua=0;
  }

  else{
    lengua--;
    if(lengua == MIN_LENG )
      sentido_lengua=1;
  }

}
