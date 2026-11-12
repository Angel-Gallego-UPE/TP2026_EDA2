#include <iostream>
#include <fstream> //archivos
#include <vector>
#include "clase.h" 
#include "Grafo.h" 
#include "Ruta.h" 

using namespace std;
//Declaraciones de funciones-------------------------------------------------------------------------
void menu();

//Func. Principal------------------------------------------------------------------------------------
int main(){
	//su matriz comienza vacía y la cantidad de ciudades es 0
	Grafo mi_grafo;
	
	//cargo primero lo que hay en el archivo(.bin) en el vector_ciudades(RAM)
	//vector de objetos que guarda todo lo que hay en el archivo.bin
	vector<Ciudad> vector_ciudades = Ciudad::leerArchivo();
	
	// sincronizamos el grafo con las ciudades que ya estaban cargadas en nuestro archivo antes de comenzar el programa
	for (int i = 0; i < vector_ciudades.size(); i++) {
		mi_grafo.agregar_ciudad();
	}

    mi_grafo.leerRuta();

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
		case 1:{//agregar una ciudad
			//variable que guarda la cantidad de objetos que hay en el vector
			int cantidad;
			Ciudad obj;
			
			obj = obj.intanciarObjeto();
			
			// Esto copia el objeto y lo coloca al final del vector dinámico de obj´s
    		vector_ciudades.push_back(obj);
			//devuelve la cantidad de objetos que tiene el vector	
    		cantidad=vector_ciudades.size();
    		
    		if(cantidad>0){
			//escribo la nueva cuidad en el archivo
				vector_ciudades[cantidad-1].escribir();
			}
			
			mi_grafo.agregar_ciudad();
            mi_grafo.guardarRuta();
			break;
			}
		case 2:
			//mientras que el vector no este vacio
			if(!vector_ciudades.empty()){
				//i < cantidad de objetos en el vector
				for(int i=0; i < vector_ciudades.size();i++){
					cout<<"---indice ["<<i<<"]"<<endl;
					cout<<"Nombre: "<<vector_ciudades[i].getNombre()<<endl;
					cout<<"ID: "<<vector_ciudades[i].getID()<<endl;
					cout<<"X: "<<vector_ciudades[i].getX()<<endl;
					cout<<"Y: "<<vector_ciudades[i].getY()<<endl;
				}
			}
			else{//vector vacio
				cout<<"El archivo esta vacio...\n";
			}
			break;
	    case 3:

			//mostramos la cantidad actual de ciudades
			cout << "Cantidad de ciudades: "<< mi_grafo.obtener_cantidad_de_ciudades() << endl;
		
			//mostramos la matriz por pantalla
			mi_grafo.mostrar_matriz();
		
		    break;
		
		case 4: {
					mi_grafo.cargar_ruta();
                    mi_grafo.guardarRuta();
					break;
				}
		case 5:{//Eliminar una ciudad
			int indice;
			
			//recorro para dar informacion de cual eliminar
			for(int i=0;i<vector_ciudades.size();i++){
				cout<<"indice["<<i<<"]= ";
				cout<<vector_ciudades[i].getNombre()<<endl;
			}
			
			cout<<"Ingrese el numero del indice a eliminar: ";
			cin>>indice;
			
			vector_ciudades.erase(vector_ciudades.begin()+indice);
			cout<<"\ndespues de eliminar el indice:"<<indice<<endl;
			
			//recorro para mostrar como quedo
			for(int i=0;i<vector_ciudades.size();i++){
				cout<<"indice["<<i<<"]= ";
				cout<<vector_ciudades[i].getNombre()<<endl;
			}
			
			Ciudad::reescribrir(vector_ciudades);
			
		// sincronizamos el grafo con las ciudades, despues de elimnar una ciudad
			mi_grafo.eliminar_ciudad(indice);
			mi_grafo.guardarRuta();
			
			break;
		}
		case 6:{//modificar elemento
			int indice;
			int opc;
			
			cout<<"Ingrese la ciudad a modificar\n";
			//muestro cada ciudad y su indice
			for(int i=0;i<vector_ciudades.size();i++){
				cout<<"indice["<<i<<"]= "<<vector_ciudades[i].getNombre()<<endl;
			}
			cout<<"Indice:";
			cin>>indice;
			
			do{
			cout<<"MODIFICAR\n1-nombre\n2-id\n3-X\n4-Y\n5-salir\nopc: ";
			cin>>opc;
			switch (opc){
			case 1:{//modificar nombre
				string auxnombre;
				do{
					cout<<"Ingrese el nuevo nombre: ";
					cin>>auxnombre;
				}while(auxnombre.size()<2);
				
				vector_ciudades[indice].setNombre(auxnombre);
				break;
			}
			case 2:{//modificar id
				int auxid;
				do{
					cout<<"Ingrese el nuevo id: ";
					cin>>auxid;
				}while(auxid<1);
				
				vector_ciudades[indice].setID(auxid);
				break;
			}
			case 3:{//modificar X
				int aux_x;
				do{
					cout<<"Ingrese el nuevo x: ";
					cin>>aux_x;
				}while(aux_x<1);
				
				vector_ciudades[indice].setX(aux_x);
				break;
			}
			case 4:{//modificar Y
				int aux_y;
				do{
					cout<<"Ingrese el nuevo y: ";
					cin>>aux_y;
				}while(aux_y<1);
				
				vector_ciudades[indice].setY(aux_y);
				break;
			}
			case 5://salgo y actualizo el archivo
				cout<<"Saliendo...\n\n";
				Ciudad::reescribrir(vector_ciudades);
				break;
			default:
				cout<<"OPCION INCORRECTA\n";
				break;
			}
			}while(opc!=5);
		}
		break;
	case 7:
		
	    mi_grafo.dijkstra();
		
		break;
	
	    default:
				cout<<"OPCION INCORRECTA";  //opcion DEFAULT
			break;		
        }
}while(opc!=0);

	return 0;
}

//Func. Secundarias----------------------------------------------------------------------------------
void menu(){
	cout<<"------------------------\n";
	cout<<"0- Salir\n";
	cout<<"1- agregar cuidad\n";
	cout<<"2- ver contenido de vector(RAM)\n";
	cout<<"3- ver la matriz\n";
	cout<<"4- cargar rutas en la matriz\n";
	cout<<"5- eliminar ciudad\n";
	cout<<"6- modificar datos de una ciudad\n";
    cout<<"7- buscar camino mas corto\n";
	cout<<"opc: ";
}
