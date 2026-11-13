#include "Grafo.h"
#include <iostream>
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
	
	
	//comprobamos que la matriz no este vacia
	if (cantidad_de_ciudades == 0) {
		cout << "no hay ciudades para eliminar\n";
		return;
	}
	
    //comprobamos que el indice exista dentro de la matriz
	if (indice < 0 || indice >= cantidad_de_ciudades) {
		cout << "indice invalido\n";
		return;
	}
	
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
			   	   
					//copia el objeto ruta de la matriz original en una variable auxiliar
					Ruta r = matriz[i][j];
					
                    //actualiza el indice de la ciudad de origen para que coincida con la nueva fila
					r.set_ciudad_origen(fila_destino);
					
                    // actualizamos el indice de la ciudad de destino para que coincida con la nueva columna
					r.set_ciudad_destino(columna_destino);
					
                    //guarda la ruta con sus indices actualizados en la nueva posicion de la matriz
					nueva_matriz[fila_destino][columna_destino] = r;
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
	
	//variables para guardar el indice de la ciudad desde donde comienza el recorrido y hacia donde queremos llegar
	int ciudad_origen;
	int ciudad_destino;
	
	//le pedimos al usuario el indice de la ciudad desde donde quiere comenzar
	cout << "ingrese el indice de la ciudad de origen: ";
	cin >> ciudad_origen;
	
	//le pedimos al usuario el indice de la ciudad a la que quiere llegar
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
	//comienza con todas las distancias en el valor maximo para indicar que todavia no conocemos un camino hacia esas ciudades
	vector<double> vector_distancia_minima(cantidad_de_ciudades, 1.7976931348623158e308);
	//comienza con todos los valores en false porque ninguna ciudad fue visitada al comenzar el algoritmo
	vector<bool> vector_visitada(cantidad_de_ciudades,false);
	
	//este vector guarda los indices de las ciudades anteriores visitadas cuyo camino fue el mas corto
	//cada posicion representa una ciudad y almacena desde que ciudad llegamos a ella mediante el camino mas corto encontrado
	//se inicializa en -1 porque al principio todavia no conocemos ninguna ciudad anterior
	vector<int> vector_registro_ciudad(cantidad_de_ciudades,-1);
	
	//inicializo el vector de la posicion ciudad origen en 0
	//esto indica que para llegar desde la ciudad origen hasta ella misma no necesitamos recorrer ninguna distancia
	vector_distancia_minima[ciudad_origen] = 0;
	
	//variables auxiliares
	int ciudad_actual = -1;
	double distancia_minima = 1.7976931348623158e308;
	int ciudad_recorrida = ciudad_destino;
	
	
	//el ciclo se repite hasta que encontramos la ciudad destino y podemos obtener su distancia minima
	while(ciudad_actual != ciudad_destino){
		
		//variables auxiliares
		
		//reiniciamos la ciudad actual en -1 porque todavia no encontramos una ciudad valida para recorrer
		//utilizamos -1 porque los indices de las ciudades comienzan en 0
		ciudad_actual = -1;
		
		//reiniciamos la distancia minima con el valor maximo para poder buscar nuevamente la ciudad no visitada con menor distancia acumulada	
		distancia_minima = 1.7976931348623158e308;
		
		
		
		//recorremos todas las ciudades para buscar cual tiene la menor distancia acumulada y todavia no fue visitada	
		for(int i = 0; i < cantidad_de_ciudades;i++){
			
			//comprueba que la ciudad de la posicion actual todavia no haya sido visitada
			if(vector_visitada[i] == false){
				
				//compara la distancia acumulada de esta ciudad con la menor distancia encontrada hasta el momento
				if(vector_distancia_minima[i] < distancia_minima){
					//actualizamos la menor distancia encontrada
					distancia_minima = vector_distancia_minima[i];
					//guardamos el indice de la ciudad que tiene actualmente la menor distancia
					ciudad_actual = i;
				}	
			}	
		}
		
		//comprueba si no encontramos ninguna ciudad que tenga un camino disponible desde el origen 	
		if(distancia_minima == 1.7976931348623158e308){
			
			cout << "no existe un camino hacia la ciudad destino\n";
			return;
			
		}		
		
		//comprobamos si la ciudad con menor distancia encontrada es la ciudad destino	
		if(ciudad_actual == ciudad_destino){
			
			cout<<"la distancia minima encontrada fue: "<<vector_distancia_minima[ciudad_destino]<<"km \n";
			
			
			cout << "camino encontrado (desde destino hasta origen): \n";		 
			
			
			//comenzamos la reconstruccion del camino desde la ciudad destino
			//el ciclo termina cuando llegamos a una ciudad que no tenga una ciudad anterior registrada
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
		
		
		//marcamos la ciudad actual como visitada para no volver a seleccionarla en las siguientes iteraciones
		vector_visitada[ciudad_actual] = true;
		
		//recorremos todas las ciudades para comprobar si existe una ruta desde la ciudad actual hacia otra ciudad
		for(int j = 0;j < cantidad_de_ciudades;j++){
			
			//comprobamos que la ciudad hacia la que queremos avanzar todavia no haya sido visitada  
			if(vector_visitada[j] == false){
				
				//comprobamos que exista una ruta entre la ciudad actual y la ciudad de la posicion j
				if(matriz[ciudad_actual][j].getruta_existe() == true){
					
					//comprobamos que la ruta se encuentre habilitada y no este cortada
					if(matriz[ciudad_actual][j].getestado_de_ruta() == true){
						
						//variable para guardar la distancia total desde el origen hasta la ciudad j pasando por la ciudad actual
						double distancia_acumulada = 0;
						//sumamos la distancia minima conocida hasta la ciudad actual mas la distancia de la ruta que conecta ambas ciudades
						distancia_acumulada = distancia_minima + matriz[ciudad_actual][j].getdistancia();
						
						//comprobamos si encontramos un camino mas corto hacia la ciudad j que el que teniamos registrado anteriormente
						if(distancia_acumulada < vector_distancia_minima[j]){
							
							//actualizamos la distancia minima conocida para llegar a la ciudad j
							vector_distancia_minima[j] = distancia_acumulada; 
							
							//guarda el indice de la ciudad actual porque desde ella encontramos el camino mas corto hacia la ciudad j
							//este dato permite reconstruir el recorrido completo desde el destino hasta el origen
							vector_registro_ciudad[j] = ciudad_actual;
							
							
						}
						
					}
				}
			}
			
			
		}
		
	}
}



void Grafo::cambiar_estado_de_ruta(){
	
    int ciudad_origen;
	int ciudad_destino;
	short continuar = 0;
	short opcion;
	
	while(continuar == 0){
	//le pedimos al usuario el indice de la primer ciudad
	cout << "ingrese el indice de la ciudad de origen: ";
	cin >> ciudad_origen;
	
	//le pedimos al usuario el indice de la segunda ciudad
	cout << "ingrese el indice de la ciudad de destino: ";
	cin >> ciudad_destino;
	
	
	//compruebo el indice ingresado
	if(ciudad_origen < 0 || ciudad_origen >= cantidad_de_ciudades || ciudad_destino < 0 || ciudad_destino >= cantidad_de_ciudades){
		
		cout<<"el indice ingresado no coresponde a ninguna ciudad";	
		continuar = 1;		
	}
	
	//compruebo que la ciudad origen y la ciudad destino no sean la misma
	if(ciudad_origen == ciudad_destino){
		
		cout<<"ciudad origen y ciudad destino son la misma";	
		continuar = 1;	
	}
	
	if(matriz[ciudad_origen][ciudad_destino].getruta_existe() == false){
		
		cout<<"no existe ninguna ruta entre estas dos ciudades\n";
		continuar = 1;
		
	}
	
	if(continuar == 0){	
	short continuar_2 = 0;	
		
	while(continuar_2 == 0){
	cout<<"ingrese el nuevo estado de la ruta\n";
	cout<<"1- ruta libre\n";	
	cout<<"2- ruta cortada\n";	
	cout<<"3- salir\n";	
	cin>>opcion;
		
	switch (opcion) {
	case 1://cambiar a rua libre
		//habilitamos la ruta en ambas direcciones 
		matriz[ciudad_origen][ciudad_destino].set_estado_de_ruta(true);
		matriz[ciudad_destino][ciudad_origen].set_estado_de_ruta(true);
		//actualizamos el archivo
		guardarRuta();
		cout<<"ruta habilitada\n";
		break;
	case 2:
		//cortamos la ruta en ambas direcciones 
		matriz[ciudad_origen][ciudad_destino].set_estado_de_ruta(false);
		matriz[ciudad_destino][ciudad_origen].set_estado_de_ruta(false);
		//actualizamos el archivo
		guardarRuta();
		cout<<"ruta cortada\n";
		break;
	case 3:
		
		continuar_2 = 1;
		
		break;
	default:
		cout<<"OPCION INVALIDA"; 
		break;
	    }	
		continuar_2 = 1;
	   }
	
		continuar = 1;
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
