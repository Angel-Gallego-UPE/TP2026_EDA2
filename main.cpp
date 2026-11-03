#include <iostream>
#include <fstream> //archivos
#include <vector>
#include "clase.h" 
#include "Grafo.h" 
#include "Ruta.h" 

using namespace std;
//Declaraciones de funciones-------------------------------------------------------------------------
void menu();
//Func. Secundarias----------------------------------------------------------------------------------
void menu(){
	cout<<"------------------------\n";
	cout<<"0- Salir\n";
	cout<<"1- agregar objeto a archivo\n";
	cout<<"2- cargar archivo archivo\n";
	cout<<"3- Probamos la matriz\n";
	cout<<"opc: ";

}
//Func. Principal------------------------------------------------------------------------------------
int main(){
	//su matriz comienza vacía y la cantidad de ciudades es 0
	Grafo mi_grafo;
	
	//cargo primero lo que hay en el archivo(.bin) en el vector_ciudades(RAM)
	//vector de objetos que guarda todo lo que hay en el archivo.bin
	vector<Ciudad> vector_ciudades = Ciudad::leerArchivo();
	
	//variables
	int opc;
//Ciclo principal
do{
	menu();
	
	cin>>opc; //Switch Case	
	switch(opc){
		case 0:	//salida del programa
			cout<<"Gracias por elegirnos...";
			break;
		case 1: {
			//variable que guarda la cantidad de objetos que hay en el vector
			int cantidad;
			
			Ciudad obj;
			
			obj.intanciarObjeto();
			
			// Esto copia el objeto y lo coloca al final del vector dinámico de obj´s
    		vector_ciudades.push_back(obj);
			
			//devuelve la cantidad de objetos que tiene el vector	
    		cantidad=vector_ciudades.size();
    		
    		if(cantidad>0){
			//escribo la nueva cuidad en el archivo
				vector_ciudades[cantidad-1].escribir();
			}
			else{
				vector_ciudades[cantidad].escribir();
			}
			
			break;
			}
	    case 3:
	    	// agregamos una ciudad a la matriz
			// cada llamada aumenta la cantidad de filas y columnas en 1
			mi_grafo.agregar_ciudad();
			mi_grafo.agregar_ciudad();
			mi_grafo.agregar_ciudad();
		  
		
			// mostramos la cantidad actual de ciudades
			// el resultado esperado es 3
			cout << "Cantidad de ciudades: "
			<< mi_grafo.obtener_cantidad_de_ciudades() << endl;
		
			// mostramos la matriz por pantalla
			// debería verse una matriz de 3 filas y 3 columnas
			mi_grafo.mostrar_matriz();
		
		    break;
	    default:
				cout<<"OPCION INCORRECTA";  //opcion DEFAULT
			break;		
	}
}while(opc!=0);

	return 0;
}
