#include <iostream>
#include <fstream> //archivos
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
	cout<<"2- leer archivo\n";
	cout<<"3- Probamos la matriz\n";
	cout<<"opc: ";

}
//Func. Principal------------------------------------------------------------------------------------
int main(){
	// creamos un objeto Grafo.
	// su matriz comienza vacía y la cantidad de ciudades es 0
	Grafo mi_grafo;
    

    //variables
	int opc;
	//objeto con parametros
	Ciudad mg(1,8,6,"monte Grande");
	Ciudad ez;

//Ciclo principal
do{
	cout<<"OBJETO______________________\n";
				cout<<"Nombre: "<<ez.getNombre()<<endl;
				cout<<"ID: "<<ez.getID()<<endl;
				cout<<"Coordenada X: "<<ez.getX()<<endl;
				cout<<"Coordenada Y: "<<ez.getY()<<endl;
				cout<<"_____________________________\n";
	menu();
	
	cin>>opc; //Switch Case
	
	switch(opc){
		case 0:	//salida del programa
				cout<<"Gracias por elegirnos...";
		case 1: //Ciudad guardada en el archivo binario
				mg.escribir();
				cout<<"Guardado\n";
			break;
		case 2: //leer archivo
				ez.leer();
				cout<<"OBJETO______________________\n";
				cout<<"Nombre: "<<ez.getNombre()<<endl;
				cout<<"ID: "<<ez.getID()<<endl;
				cout<<"Coordenada X: "<<ez.getX()<<endl;
				cout<<"Coordenada Y: "<<ez.getY()<<endl;
				cout<<"_____________________________\n";
			break;
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
