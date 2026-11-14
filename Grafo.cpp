#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//constructor
Grafo::Grafo(){
	
	matriz = 0;
	cantidad_de_ciudades = 0;
	
}

void Grafo::agregar_ciudad(){ //funcion para agregar ciudades
	
	//calculamos el nuevo tamaño de la matriz
	int nueva_cantidad = cantidad_de_ciudades + 1;
	
	//reservamos memoria para las nuevas filas
	Ruta** nueva_matriz = new Ruta*[nueva_cantidad];
	
	//reservamos memoria para las columnas de cada fila
	for (int i = 0; i < nueva_cantidad; i++) {
		nueva_matriz[i] = new Ruta[nueva_cantidad];
	}
	
	//copiamos las rutas que ya existian
	for (int i = 0; i < cantidad_de_ciudades; i++) {
		for (int j = 0; j < cantidad_de_ciudades; j++) {
			nueva_matriz[i][j] = matriz[i][j];
		}
	}
	
	//liberamos la matriz anterior
	for (int i = 0; i < cantidad_de_ciudades; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
	
	//actualizamos la matriz y su tamaño
	matriz = nueva_matriz;
	cantidad_de_ciudades = nueva_cantidad;
	
}

void Grafo::eliminar_ciudad(int indice){
	
	int nueva_cantidad = cantidad_de_ciudades -1;
	
		//reservamos memoria para las nuevas filas.
	Ruta** nueva_matriz = new Ruta*[nueva_cantidad];
	
	//reservamos memoria para las columnas de cada fila.
	for (int i = 0; i < nueva_cantidad; i++) {
		nueva_matriz[i] = new Ruta[nueva_cantidad];
	}
	
	//copiamos las rutas que ya existian, ignorando la fila y columna eliminadas
	for (int i = 0; i < cantidad_de_ciudades; i++) {
		for (int j = 0; j < cantidad_de_ciudades; j++) {
				
             //variables auxiliares para calcular la posicion de la nueva matriz sin modificar las posiciones originales
			    int fila_destino = i;
				int columna_destino = j;
					
			if(i > indice){//si i (la fila) es mayor a nuestro indice, le restamos 1 (retrocediendola)
				
				fila_destino--;
			              
			}
				if(j > indice){//si i (la columna) es mayor a nuestro indice, le restamos 1 (retrocediendola)
				
					columna_destino--;
		                      
				}
			//evitamos copiar los elementos de la fila y columna eliminadas
			    if(i != indice && j != indice){
			   	   
					 //copiamos la ruta en su nueva posicion dentro de la matriz
					nueva_matriz[fila_destino][columna_destino] = matriz[i][j];
				
				}
	    }
	}
	//liberamos la matriz anterior
	for (int i = 0; i < cantidad_de_ciudades; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
	
	//actualizamos la matriz y su tamaño
	matriz = nueva_matriz;
	cantidad_de_ciudades = nueva_cantidad;
	
}


//funcion para comprobar la cantidad de ciudades
int Grafo::obtener_cantidad_de_ciudades() {
	return cantidad_de_ciudades;
}

void Grafo::cargar_ruta(){
			    
    int ciudad_origen;
	int ciudad_destino;
	int continuar = 0;
	double distancia;
	
	
	while(continuar == 0){
		
	cout << "Ingrese el indice de la ciudad origen: ";
	cin >> ciudad_origen;
	cout << "Ingrese el indice de la ciudad destino: ";
	cin >> ciudad_destino;
	cout << "Ingrese la distancia de la ruta: ";
	cin >> distancia;
	if(ciudad_origen == ciudad_destino){
	
		cout << "Operacion invalida el indice de ambas ciudades es el mismo\n";

	}else{
			if(distancia <= 0){
			
				cout << "Operacion invalida ingrese una distancia positiva mayor a 0\n ";
 	           
			}else{
				
	//crea el objeto Ruta con los datos ingresados
	//(origen, destino, distancia, estado_de_ruta=1, ruta_existe=true)
    //Ruta de ida (origen -> destino)
	Ruta ruta_ida(ciudad_origen, ciudad_destino, distancia, 1, true);
	set_ruta(ciudad_origen, ciudad_destino, ruta_ida); //guarda la ruta en la matriz del grafo usando el metodo set_ruta
	
    //Ruta de vuelta (destino -> origen)
	Ruta ruta_vuelta(ciudad_destino, ciudad_origen, distancia, 1, true);
	set_ruta(ciudad_destino, ciudad_origen, ruta_vuelta);
	cout << "Ruta cargada exitosamente\n";
			 
				continuar = 1; //si se cargan los datos correctamente salimos del bucle
			
			}
	    }
	}
}

void Grafo::leerRuta()
{
    ifstream archivo("rutas.bin", ios::binary);
    if(archivo)
    {
        int ciudades_guardadas = 0;
        if(archivo.read((char*)&ciudades_guardadas, sizeof(ciudades_guardadas)))
        {
            while(cantidad_de_ciudades < ciudades_guardadas)
            {
                agregar_ciudad();
            }
            for(int i = 0; i < cantidad_de_ciudades; i++)
            {
                for(int j = 0; j < cantidad_de_ciudades; j++)
                {
                    Ruta r;
                    if(archivo.read((char*)&r, sizeof(Ruta)))
                    {
                        matriz[i][j] = r;
                    }
                }
            }
        }
        archivo.close();
    }
}

void Grafo::guardarRuta()
{
    ofstream archivo("rutas.bin", ios::binary | ios::trunc);
    if(archivo)
    {
        archivo.write((char*)&cantidad_de_ciudades, sizeof(cantidad_de_ciudades));
        for(int i = 0; i < cantidad_de_ciudades; i++)
        {
            for(int j = 0; j < cantidad_de_ciudades; j++)
            {
                Ruta r = matriz[i][j];
                archivo.write((char*)&r, sizeof(Ruta));
            }
        }
        archivo.close();
    }
}


//funcion para probar que la matriz funciona correctamente
void Grafo::mostrar_matriz() {
	cout << "\n--- MATRIZ DE RUTAS (Distancias) ---\n";
	
	if (cantidad_de_ciudades == 0) {
		cout << "El grafo esta vacio.\n";
	} else {
		for (int i = 0; i < cantidad_de_ciudades; i++) {
			for (int j = 0; j < cantidad_de_ciudades; j++) {
				//llamamos al getter del grafo para obtener la ruta en la celda [i][j]
				Ruta r = getRuta(i, j);
				
				//Imprimimos la distancia guardada en esa ruta
				cout << "[" << r.getdistancia() << "] ";
			}
			cout << endl;
		}
	}
}

void Grafo::dijkstra(){

	
	int ciudad_origen;
	int ciudad_destino;
	
	cout << "ingrese el indice de la ciudad de origen: ";
	cin >> ciudad_origen;
	
	cout << "ingrese el indice de la ciudad de destino: ";
	cin >> ciudad_destino;
	
	
	//compruebo el indice ingresado
	if(ciudad_origen < 0 || ciudad_origen >= cantidad_de_ciudades || ciudad_destino < 0 || ciudad_destino >= cantidad_de_ciudades){
		
		cout<<"el indice ingresado no coresponde a ninguna ciudad";	
		return;		
	}
	
	//compruebo que la ciudad origen y la ciudad destino no sean la misma
		if(ciudad_origen == ciudad_destino){
			
			cout<<"ya estas en la ciudad destino";	
			return;	
		}

		
    //vectores para guardar la distancias minimas hacia cada ciudad y para comprobar si ya fue visitada o no
	vector<double> vector_distancia_minima(cantidad_de_ciudades, 1.7976931348623158e308);
	vector<bool> vector_visitada(cantidad_de_ciudades,false);

    //este vector guarda los indices de las ciudades anteriores visitadas cuyo camino fue el mas corto
	vector<int> vector_registro_ciudad(cantidad_de_ciudades,-1);
	
    //inicializo el vector de la posicion ciudad origen en 0
	vector_distancia_minima[ciudad_origen] = 0;
  
	//variables auxiliares
	int ciudad_actual = -1;
	double distancia_minima = 1.7976931348623158e308;
    int ciudad_recorrida = ciudad_destino;
	
	while(ciudad_actual != ciudad_destino){
	  
	  //variables auxiliares
	  
	  ciudad_actual = -1;//inicializamos en -1 para decir que no encontramos ninguna ciudad valida, es -1 porque nuestro indice comienza en 0
	  distancia_minima = 1.7976931348623158e308;

		
		
		
	for(int i = 0; i < cantidad_de_ciudades;i++){
		if(vector_visitada[i] == false){
		    if(vector_distancia_minima[i] < distancia_minima){
			
				distancia_minima = vector_distancia_minima[i];
				
				ciudad_actual = i;
			}	
		}	
	}

     	
	if(distancia_minima == 1.7976931348623158e308){
			
			cout << "no existe un camino hacia la ciudad destino\n";
			return;
			
   	 }		
		
		
	 if(ciudad_actual == ciudad_destino){
	   
		cout<<"la distancia minima encontrada fue: "<<vector_distancia_minima[ciudad_destino]<<"km \n";
		 
		 
		cout << "camino encontrado (desde destino hasta origen): \n";		 
		 
		 while(ciudad_recorrida != -1){

             cout << ciudad_recorrida << " <- ";
			 

             //busca en el vector la ciudad anterior a la ciudad recorrida actualmente
			 //el vector guarda el indice de la ciudad desde la cual llegamos a cada ciudad
			 int ciudad_anterior = vector_registro_ciudad[ciudad_recorrida];
			 
			 //retrocedemos a la ciudad anterior para reconstruir el camino hasta el origen
			 //repetimos el proceso hasta llegar a -1 que indica que ya no hay una ciudad anterior
			 ciudad_recorrida = ciudad_anterior;
			 
		 }

	    return;	
	 
	 }
		
	vector_visitada[ciudad_actual] = true;
	
	for(int j = 0;j < cantidad_de_ciudades;j++){
	    
	  if(vector_visitada[j] == false){
		if(matriz[ciudad_actual][j].getruta_existe() == true){
			if(matriz[ciudad_actual][j].getestado_de_ruta() == true){
				
				double distancia_acumulada = 0;
				distancia_acumulada = distancia_minima + matriz[ciudad_actual][j].getdistancia();
				
			if(distancia_acumulada < vector_distancia_minima[j]){
				 
				vector_distancia_minima[j] = distancia_acumulada; 
				 
				vector_registro_ciudad[j] = ciudad_actual;
				
		         	}
				 
			    }
			}
		}
		
		
	}
	
  }
}



// SETTER: guarda o actualiza un objeto Ruta en coordenadas especificas [origen][destino]
void Grafo::set_ruta(int ciudad_origen, int ciudad_destino, Ruta nueva_ruta) {
	
	//primero validamos que los indices de las ciudades esten dentro de los límites reales de la matriz
	//las posiciones van desde 0 hasta (cantidad_de_ciudades - 1)
	if (ciudad_origen >= 0 && ciudad_origen < cantidad_de_ciudades && ciudad_destino >= 0 && ciudad_destino < cantidad_de_ciudades){
		
		// si los indices son validos, guardamos el objeto Ruta en esa celda de la matriz
		matriz[ciudad_origen][ciudad_destino] = nueva_ruta;
		
	} else {
		//si intentan acceder a una ciudad que no existe, mostramos un aviso por consola
		cout << "Error: intentaste asignar una ruta en ciudades fuera de rango.\n";
	}
}

// GETTER: devuelve el objeto Ruta que se encuentra en la celda [origen][destino]
Ruta Grafo::getRuta(int ciudad_origen, int ciudad_destino) {
	
	//validamos nuevamente que los índices sean correctos para evitar un desbordamiento o error de memoria
	if (ciudad_origen >= 0 && ciudad_origen < cantidad_de_ciudades && ciudad_destino >= 0 && ciudad_destino < cantidad_de_ciudades){
		
		//Retornamos el objeto Ruta almacenado en esa posición de la matriz
		return matriz[ciudad_origen][ciudad_destino];
		
	} else {
		//si los índices no son válidos, devolvemos una Ruta por defecto (vacia o inicializada en 0)
		cout << "Error: indices fuera de rango al intentar leer la ruta.\n";
		return Ruta(); 
	}
}

//destructor 
Grafo::~Grafo(){
	
	//recorre todas las filas de la matriz (CORREGIDO: < en lugar de <= para evitar desbordamiento)
	for(int i = 0; i < cantidad_de_ciudades; i++){
		delete[] matriz[i];  //Libera la memoria reservada para cada fila
	}
	
	delete[] matriz;  //Libera la memoria reservada para el conjunto de filas
}
