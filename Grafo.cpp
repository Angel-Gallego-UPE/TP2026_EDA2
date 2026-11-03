#include "Grafo.h"
#include <iostream>
using namespace std;

//constructor
Grafo::Grafo(){
	
	matriz = 0;
	cantidad_de_ciudades = 0;
	
}

void Grafo::agregar_ciudad(){ //funcion para agregar ciudades
	
	//calculamos el nuevo tamaño de la matriz.
	int nueva_cantidad = cantidad_de_ciudades + 1;
	
	//reservamos memoria para las nuevas filas.
	Ruta** nueva_matriz = new Ruta*[nueva_cantidad];
	
	//reservamos memoria para las columnas de cada fila.
	for (int i = 0; i < nueva_cantidad; i++) {
		nueva_matriz[i] = new Ruta[nueva_cantidad];
	}
	
	//copiamos las rutas que ya existían.
	for (int i = 0; i < cantidad_de_ciudades; i++) {
		for (int j = 0; j < cantidad_de_ciudades; j++) {
			nueva_matriz[i][j] = matriz[i][j];
		}
	}
	
	//liberamos la matriz anterior.
	for (int i = 0; i < cantidad_de_ciudades; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
	
	//Actualizamos la matriz y su tamaño.
	matriz = nueva_matriz;
	cantidad_de_ciudades = nueva_cantidad;
	
}


//funcion para comprobar la cantidad de ciudades
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

// SETTER: guarda o actualiza un objeto Ruta en coordenadas especificas [origen][destino]
void Grafo::set_ruta(int ciudad_origen, int ciudad_destino, Ruta nueva_ruta) {
	
	// primero validamos que los indices de las ciudades esten dentro de los límites reales de la matriz
	// las posiciones van desde 0 hasta (cantidad_de_ciudades - 1)
	if (ciudad_origen >= 0 && ciudad_origen < cantidad_de_ciudades && ciudad_destino >= 0 && ciudad_destino < cantidad_de_ciudades){
		
		// si los indices son validos, guardamos el objeto Ruta en esa celda de la matriz
		matriz[ciudad_origen][ciudad_destino] = nueva_ruta;
		
	} else {
		// si intentan acceder a una ciudad que no existe, mostramos un aviso por consola
		cout << "Error: intentaste asignar una ruta en ciudades fuera de rango.\n";
	}
}

// GETTER: devuelve el objeto Ruta que se encuentra en la celda [origen][destino]
Ruta Grafo::getRuta(int ciudad_origen, int ciudad_destino) {
	
	// validamos nuevamente que los índices sean correctos para evitar un desbordamiento o error de memoria
	if (ciudad_origen >= 0 && ciudad_origen < cantidad_de_ciudades && ciudad_destino >= 0 && ciudad_destino < cantidad_de_ciudades){
		
		// Retornamos el objeto Ruta almacenado en esa posición de la matriz
		return matriz[ciudad_origen][ciudad_destino];
		
	} else {
		// si los índices no son válidos, devolvemos una Ruta por defecto (vacia o inicializada en 0)
		cout << "Error: indices fuera de rango al intentar leer la ruta.\n";
		return Ruta(); 
	}
}

//destructor 
Grafo::~Grafo(){
	
	//recorre todas las filas de la matriz (CORREGIDO: < en lugar de <= para evitar desbordamiento)
	for(int i = 0; i < cantidad_de_ciudades; i++){
		delete[] matriz[i];  // Libera la memoria reservada para cada fila
	}
	
	delete[] matriz;  //Libera la memoria reservada para el conjunto de filas
}
