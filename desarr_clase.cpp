#include "clase.h"
#include <iostream>
#include <fstream> //libreria de manejo de archivos
#include <string> //libreria necesaria

using namespace std;
//CONSTRUCTOR (+ parametros)
Ciudad::Ciudad(int _id, int _x, int _y, string _nombre){
	id=_id;
	x=_x;
	y=_y;
	nombre=_nombre;
}

//CONSTRUCTOR (Iniciado en 0)
Ciudad::Ciudad(){
	id = 0; //atributo bandera
    x = 0;
    y = 0;
    nombre = "";
}

//DESTRUCTOR
Ciudad::~Ciudad(){
}
//METODOS GET
int Ciudad::getID(){
	return id;
}
int Ciudad::getX(){
	return x;
}
int Ciudad::getY(){
	return y;
}
string Ciudad::getNombre(){
	return nombre;
}
//METODOS SET
void Ciudad::setID(int _id){
	id= _id;
}
void Ciudad::setX(int _x){
	x= _x;
}
void Ciudad::setY(int _y){
	y= _y;
}
void Ciudad::setNombre(string _nombre){
	nombre= _nombre;
}
//METODO LEER
void Ciudad::leer() {
    
	ifstream archivo("archivo.bin", ios::binary);//archivo + r

    int auxID; //variables aux
	int auxX;
	int auxY;
	string auxNombre;
	int longitud; 	//saber la cantidad de caracteres
    
	//copio lo del archivo a las variables aux (es lo que hace read)
    archivo.read((char*)&auxID, sizeof(auxID));
    archivo.read((char*)&auxX, sizeof(auxX));
    archivo.read((char*)&auxY, sizeof(auxY));
    
    archivo.read((char*)&longitud, sizeof(longitud));//obtengo el tamaño
    auxNombre.resize(longitud); //resize() prepara el string para recibir esa cantidad de caracteres

    if (longitud > 0){//por si no hay nada 
        archivo.read(&auxNombre[0], longitud);
		//archivo.read(& obtiene la primera[0] direccion de memoria de la primera letra, tamaño);
    }

	//Metodo SETTERS
    setID(auxID);
    setX(auxX);
    setY(auxY);
    setNombre(auxNombre);

    archivo.close();//cierro archivo
}
//METODO ESCRIBIR 
void Ciudad::escribir(){
	ofstream archivo("archivo.bin", ios::binary | ios::app);//archivo + outfile(write) + al final
	
	int longitud=0;//variable de caracteres
	//obtengo los nuevos datos del objeto(GET)
    int auxID = getID(); //y las guardo en auxiliares
    int auxX = getX();
    int auxY = getY();
    string auxNombre = getNombre();
    
	//escribe las variables enteras al archivo
    archivo.write((char*)&auxID, sizeof(auxID));
    archivo.write((char*)&auxX, sizeof(auxX));
    archivo.write((char*)&auxY, sizeof(auxY));
    
	//6 ejemplo
    longitud = auxNombre.size();//devuelve la cantidad de caracteres que contiene el string
    
	if(longitud>0){
    	archivo.write((char*)&longitud, sizeof(longitud)); //guarda espacio para la longitud
    	archivo.write(&auxNombre[0], longitud); //escribe lo que hay dentro de auxNombre
	}
    archivo.close();//cierro archivo
}





