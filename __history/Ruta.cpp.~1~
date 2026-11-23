#include "Ruta.h"
#include <iostream>
using namespace std;

//CONSTRUCTOR (+ parametros)
Ruta::Ruta(int _ciudad_origen, int _ciudad_destino, double _distancia, bool _estado_de_ruta,bool _ruta_existe){
	ciudad_origen = _ciudad_origen;
	ciudad_destino = _ciudad_destino;
	distancia = _distancia;
	estado_de_ruta = _estado_de_ruta;
	ruta_existe = _ruta_existe;
}
//CONSTRUCTOR (Iniciado en 0)
Ruta::Ruta(){
	ciudad_origen = 0; //atributo bandera
	ciudad_destino = 0;
	distancia = 0;
	estado_de_ruta = true;
	ruta_existe = false;
}


//METODOS SETTERS
void Ruta::set_ciudad_origen(int _ciudad_origen) {
	ciudad_origen = _ciudad_origen;
}

void Ruta::set_ciudad_destino(int _ciudad_destino) {
	ciudad_destino = _ciudad_destino;
}

void Ruta::set_estado_de_ruta(bool _estado_de_ruta){
	
	estado_de_ruta = _estado_de_ruta;
}

//METODOS GETTERS
double Ruta::getdistancia(){
	
	return distancia;
}

bool Ruta::getruta_existe(){
	
	return ruta_existe;
}
bool Ruta::getestado_de_ruta(){
	
	return estado_de_ruta;
}
//DESTRUCTOR
Ruta::~Ruta(){
}

