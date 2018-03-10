#include "Escenario.h"
#include <string>
#include <iostream>
//#include "Item.h"
#include "Bombas.h"
#include "Normal.h"
#include "V_DosPuntos.h"
#include "Espina.h"
#include <vector>
using namespace std;

Escenario::Escenario(string nombre, int tipobomba)
{
    this->nombre = nombre;
    if (tipobomba == 1)
    {
        bombas.push_back(new Normal() );
    }
    if (tipobomba == 1)
    {
        bombas.push_back(new V_DosPuntos());
    }
    if (tipobomba == 1)
    {
        bombas.push_back(new Espina());
    }
}

Escenario::~Escenario()
{
}

void Escenario::setNombre(string nombre)
{
    this->nombre = nombre;
}

Item*** Escenario::getMatrix(){
    return Matriz;
}

void Escenario::setMatrix(Item* elemento,int i, int j){
    Matriz[i][j]=elemento;
}