#include <iostream>
using namespace std;

class Ciudad{
	//atributo priv
	int id;
	int x;
	int y;
	string nombre;
	int cant_aristas;
	//metodos
	public:
		Ciudad(int, int, int, string, int); //constructor
		Ciudad(); //contructor inicializado en 0
		~Ciudad(); //destructor
		
		//metodos
		void mostrar(Ciudad x);	
};
