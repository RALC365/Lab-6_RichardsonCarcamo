#include <string>
#include <iostream>
#include "Item.h"
#include "Bombas.h"
#include "Normal.h"
#include "V_DosPuntos.h"
#include "Espina.h"
#include <vector>
using namespace std;

#ifndef ESCENARIO_H
#define ESCENARIO_H

class Escenario
{
  private:
    string nombre;
    Item*** Matriz;
    vector<Bombas *> bombas;

  public:
    Escenario(string, int);
    Escenario();
    void setMatrix(Item*, int, int);
    Item*** getMatrix();
    void setNombre(string);

    ~Escenario();
};
#endif
