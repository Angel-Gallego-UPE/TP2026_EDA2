#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include "Ruta.h"
using namespace std;


class Grafo {

private:

	Ruta **matriz; // creo matriz dinamica con puntero doble
	int cantidad_de_ciudades; // variable para saber la cantidad de filas y colmnas que necesitamos
	
public:
	
	Grafo(); //constructor
	~Grafo();//destructor
	
	void agregar_ciudad(); //funcion para agregar ciudades a la matriz
	void eliminar_ciudad(int indice);//funcion para eliminar ciudad de la matriz
	int obtener_cantidad_de_ciudades(); //funcion para comprobar la cantidad de ciudades cargadas
	void mostrar_matriz();//funcion para mostrar que la matriz funciona correctamente
	void cargar_ruta();//creamos una ruta entre 2 ciudades
    void leerRuta();
    void guardarRuta();
	void dijkstra();//algoritmo de busqueda de camino mas corto
	void cambiar_estado_de_ruta();
	
    //SETTERS
    void set_ruta(int ciudad_origen,int ciudad_destino, Ruta nueva_ruta);//guarda un objeto Ruta en la celda [ciudad_origen][ciudad_destino]	
	//GETTERS
    Ruta getRuta(int ciudad_origen, int ciudad_destino);//devuelve el objeto Ruta de la celda [origen][destino]
};

#endif // GRAFO_H
