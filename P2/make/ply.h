#ifndef _PLY_H
#define _PLY_H
#include"file_ply_stl.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include "modelo3D.h"

class Ply : public modelo3D {
private:
_file_ply fi;

public:
  Ply(){}
  Ply(string name);
  void InicializarPLY(string name);
  Ply& operator=(const Ply& p);
};


#endif
