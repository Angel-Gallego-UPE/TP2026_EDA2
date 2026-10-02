#include <iostream>
#include <fstream> //archivos
#include "clase.h" 

using namespace std;
//Declaraciones de funciones-------------------------------------------------------------------------
void menu();
void mostrar();
void escribir();
void borrar();

//Func. Secundarias----------------------------------------------------------------------------------
void menu(){
	cout<<"------------------------\n";
	cout<<"0- Salir\n";
	cout<<"1- Leer archivo\n";
	cout<<"2- Agregar texto\n";
	cout<<"3- Borrar ultimo elemento\n";
	cout<<"opc: ";
}
void mostrar(){
	string linea=""; 
	string texto="";
	
	ifstream archivo_txt("documento.txt"); //abro para input[salida]
			
	while(getline(archivo_txt,linea))//lee linea x linea
	{
		texto=texto+linea+"\n"; //acumula las lineas en el texto
	}	
	
	cout<<texto; //muestro el string texto completamente cargados despues del ciclo de carga		
	archivo_txt.close();//cierro el archivo
}
void escribir(){
	string cadena="";
	
	cout<<"Texto: ";
	cin.ignore(); //cin >> opc, toma el case:[2], pero el enter(\n) queda pendiente en el buffer de entrada
				//[Ignorá ese carácter que quedó pendiente]
				
	getline(cin, cadena); //leo la linea completa
	ofstream archivo2_txt("documento.txt",ios::app); //abro el archivo2 justo en el final
	archivo2_txt<<cadena<<endl;  //archivo2 + cadena + \n
	archivo2_txt.close();	 //cierro el archivo	
}
void borrar(){
	string linea="";
    string texto="";
    string anterior="";

    ifstream archivo_txt("documento.txt"); //abro para leer al archivo
    while(getline(archivo_txt, linea)){//lee la primera linea y la guarda en la variable linea

        if(anterior != ""){ //si anterior es distinto de "vacio"
            texto = texto + anterior + "\n"; //acumula el texto anterior en texto
        }

        anterior = linea; //y despues asigna la linea leida a anterior
    }
    archivo_txt.close(); //cierro el arhivo
    
    ofstream archivo2_txt("documento.txt"); //abro para modificarlo
    archivo2_txt << texto; //sobre escribo el texto del archivo, sin la ultima linea
    archivo2_txt.close(); //cierro el archivo
}

//Func. Principal------------------------------------------------------------------------------------
int main(){
	//variables
	int opc;
	//objeto con parametros
	Cuidad mg(01,8,6,"monteGrande",2);
	
//Ciclo principal
do{
	menu();
	cin>>opc; //Switch Case
	switch(opc){
		
		case 1: //mostrar
				mostrar();
			break;
		case 2: //escribir
			 	escribir();
			break;
		case 3: //borrar ultimo de la fila
				borrar();
			break;
		default:
				cout<<"OPCION INCORRECTA";  //opcion DEFAULT
			break;		
	}
}while(opc!=0);

	return 0;
}
