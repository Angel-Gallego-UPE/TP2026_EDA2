#ifndef clase.h
#define clase.h
#include <iostream>
#include <vector>
using namespace std;

class Ciudad{
	//atributo privados
		int id;
		int x;
		int y;
		string nombre;
		
	public:
		//metodos contructores y destructor
		Ciudad(int, int, int, string); //constructor
		Ciudad();  //contructor inicializado en 0
		~Ciudad(); //destructor
		
		//metodos GETTERS
		int getID();
		int getX();
		int getY();
		string getNombre();
		//metodos SETTERS
		void setID(int _id);
		void setX(int _x);
		void setY(int _y);
		void setNombre(string _nombre);
		//metodos
		void escribir();
		static void reescribrir(vector<Ciudad>& vector_ciudades);
		static vector<Ciudad> leerArchivo();
		Ciudad intanciarObjeto();
        static bool eliminarCiudad(int idBuscado);
		static bool modificarCiudad(Ciudad CiudadModificar);
};
#endif
