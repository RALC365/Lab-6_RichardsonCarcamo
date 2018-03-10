#include "V_DosPuntos.h"
#include <iostream>
#include <string>

using namespace std;

V_DosPuntos::V_DosPuntos(string simbolo){
    this->simbolo=simbolo;
}

V_DosPuntos::V_DosPuntos(){
}

string V_DosPuntos::getSimbolo(){
    return simbolo;
}

void V_DosPuntos:: setSimbolo(string simbolo){
    this->simbolo=simbolo;
}

V_DosPuntos::~V_DosPuntos(){
}

string V_DosPuntos:: toString(){
	return simbolo;
}
