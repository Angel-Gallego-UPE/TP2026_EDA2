#include "Grafo.h"
#include <iostream>
using namespace std;

//constructor

Grafo::Grafo(){
	
	matriz = 0;
	cantidad_de_ciudades = 0;

}

// funcion para agregar ciudades
void Grafo::agregar_ciudad(){
	
	    // Calculamos el nuevo tamaño de la matriz.
	int nueva_cantidad = cantidad_de_ciudades + 1;
	
	// Reservamos memoria para las nuevas filas.
	Ruta** nueva_matriz = new Ruta*[nueva_cantidad];
	
	// Reservamos memoria para las columnas de cada fila.
	for (int i = 0; i < nueva_cantidad; i++) {
		nueva_matriz[i] = new Ruta[nueva_cantidad];
	}
	
	// Copiamos las rutas que ya existían.
	for (int i = 0; i < cantidad_de_ciudades; i++) {
		for (int j = 0; j < cantidad_de_ciudades; j++) {
			nueva_matriz[i][j] = matriz[i][j];
		}
	}
	
	// Liberamos la matriz anterior.
	for (int i = 0; i < cantidad_de_ciudades; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
	
	// Actualizamos la matriz y su tamaño.
	matriz = nueva_matriz;
	cantidad_de_ciudades = nueva_cantidad;
	
}


//fncion para comprobar la cantidad de ciudades
int Grafo::obtener_cantidad_de_ciudades() {
	return cantidad_de_ciudades;
}

//funcion para probar que la matriz funciona correctamente
void Grafo::mostrar_matriz() {
	for (int i = 0; i < cantidad_de_ciudades; i++) {
		for (int j = 0; j < cantidad_de_ciudades; j++) {
			cout << "[ ] ";
		}
		cout << endl;
	}
}



// destructor 

Grafo::~Grafo(){
	
	// Recorre todas las filas de la matriz
	for(int i=0;i<=cantidad_de_ciudades;i++){
	
		delete[] matriz[i];  // Libera la memoria reservada para cada fila
	}
	
	delete[] matriz;  // Libera la memoria reservada para el conjunto de filas
}

