#include <string>
#include <iostream>
#include "Bombas.h"
using namespace std;

#ifndef V_DOSPUNTOS_H
#define V_DOSPUNTOS_H
class V_DosPuntos : public Bombas{
    private:
        string simbolo=":'v";
    public:
        V_DosPuntos();
        V_DosPuntos(string);
        string getSimbolo();
        void setSimbolo(string);
	string toString();
    ~V_DosPuntos();
};


#endif
