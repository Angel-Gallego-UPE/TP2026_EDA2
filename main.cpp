#include <iostream>
#include <fstream> //archivos
#include "clase.h"

using namespace std;
//funciones secundarias
void menu();

//Func. Principal
int main(){
	//variables
	int opc;
	string cadena="";
	string linea=""; 
	string texto="";
	
	//objeto con parametros
	Cuidad mg(01,8,6,"monteGrande",2);
	
//Ciclo principal
do{
	menu();
	cin>>opc; //Switch Case
	switch(opc){
		
		case 1:{ //MOSTRAR
			ifstream archivo_txt("documento.txt"); //abro para input[salida]
			texto = "";//reseteo el texto
			
			while(getline(archivo_txt,linea))//lee linea x linea
			{
				texto=texto+linea+"\n"; //acumula las lineas en el texto
			}	
			cout<<texto; //muestro el string texto completamente cargados despues del ciclo de carga
			
			archivo_txt.close();		//cierro el archivo
		}
			break;
		case 2: //escribir
			cout<<"Texto: ";
			cin.ignore(); //cin >> opc, toma el case:[2], pero el enter(\n) queda pendiente en el buffer de entrada
				//[Ignorá ese carácter que quedó pendiente]
				
			getline(cin, cadena); //leo la linea completa
				{
					ofstream archivo2_txt("documento.txt"); //abro el archivo2 para output(entrada)
					archivo2_txt<<texto<<cadena;  //archivo2 = texto(lo que habia) + cadena(lo nuevo escrito)
					archivo2_txt.close();	 //cierro el archivo				 		
				break;
				}
		default:
			cout<<"OPCION INCORRECTA";  //opcion DEFAULT
			break;		
	}
}while(opc!=0);

	
	return 0;
}

void menu(){
	cout<<"------------------------\n";
	cout<<"1- Leer archivo\n";
	cout<<"2- Agregar texto\n";
	cout<<"opc: ";
}