#include "clase.h"
#include <iostream>
using namespace std;

	//CONSTRUCTOR (+ parametros)
Cuidad::Cuidad(int _id, int _x, int _y, string _nombre, int _cant_aristas){
	id=_id;
	x=_x;
	y=_y;
	nombre=_nombre;
	cant_aristas=_cant_aristas;
}
	//CONSTRUCTOR (Iniciado en 0)
Cuidad::Cuidad(){
	id = -1; //atributo bandera
    x = 0;
    y = 0;
    nombre = "";
    cant_aristas = 0;
}
	//DESTRUCTOR
Cuidad::~Cuidad(){
}
	
//METODOS PUBLICOS
void Cuidad::mostrar(Cuidad N){

    cout<<"Id: "<<N.id<<endl;
    cout<<"Nombre:"<<N.nombre<<endl;
    cout<<"Cantidad de Aristas: "<<N.cant_aristas<<endl;
    cout<<"eje_x: "<<N.x<<endl;  
	cout<<"eje_y: "<<N.y<<endl;
}