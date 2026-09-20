#include <iostream>
using namespace std;

class Cuidad{
	//atributo
	int id;
	int x;
	int y;
	string nombre;
	int cant_aristas;
	//metodos
	public:
		Cuidad(int, int, int, string, int); //constructor
		Cuidad(); //contructor inicializado en 0
		~Cuidad(); //destructor
		
		//metodos
		void mostrar(Cuidad x);	
};