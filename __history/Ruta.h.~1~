#ifndef RUTA_H
#define RUTA_H
#include <iostream>
using namespace std;

class Ruta {
private:
	int ciudad_origen;
	int ciudad_destino;
	
	double distancia;
	bool estado_de_ruta;
	bool ruta_existe;
	
public:
	Ruta(int, int, double, bool, bool); //constructor
	Ruta(); //contructor inicializado en 0
	~Ruta(); //destructor	
	
	
	//metodos setters
	void set_ciudad_origen(int origen);
	void set_ciudad_destino(int destino);
	void set_estado_de_ruta(bool estado_de_ruta);
	
	//metodos getters
	double getdistancia();
    bool getruta_existe();	
	bool getestado_de_ruta();
};

#endif // RUTA_H
