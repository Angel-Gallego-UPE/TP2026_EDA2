#include <iostream>
#include <fstream> //archivos
#include "clase.h" 
#include "Grafo.h" 
//#include "Ruta.h" 


using namespace std;
//Declaraciones de funciones-------------------------------------------------------------------------
void menu();
void mostrar();
void escribir();
void borrarUltimo();
void borrarEspecifico();
void modificarEspecifico();

//Func. Secundarias----------------------------------------------------------------------------------
void menu(){
	cout<<"------------------------\n";
	cout<<"0- Salir\n";
	cout<<"1- Leer archivo\n";
	cout<<"2- Agregar texto\n";
	cout<<"3- Borrar ultimo elemento\n";
    cout<<"4- Borrar elemento especifico\n";
	cout<<"5- Modificar elemento especifico\n";
	cout<<"6- Probamos la matriz\n";
	cout<<"opc: ";

}
void mostrar(){
	string linea=""; 
	string texto="";
	
	ifstream archivo_txt("documento.txt"); //abro para input[salida]

    if(archivo_txt) //verifico que se puede abrir el archivo
    {
   		while(getline(archivo_txt,linea))//lee linea x linea
		{
			texto=texto+linea+"\n"; //acumula las lineas en el texto
		}

		cout<<texto; //muestro el string texto completamente cargados despues del ciclo de carga
		archivo_txt.close();//cierro el archivo
    }
    else //sino
    cout << "No se pudo acceder al archivo" << endl;
}
void escribir(){
	string cadena="";
    bool validarEspacio=false;
    int i=0;
	cout<<"Texto: ";
	cin.ignore(); //cin >> opc, toma el case:[2], pero el enter(\n) queda pendiente en el buffer de entrada
				//[Ignorá ese carácter que quedó pendiente]
	getline(cin, cadena); //leo la linea completa

    for(i=0;i<cadena.length();i++)
    {
        if(cadena[i]!=' ')
        validarEspacio=true;
    }
    if(validarEspacio)
    {
		ofstream archivo2_txt("documento.txt",ios::app); //abro el archivo2 justo en el final
        if(archivo2_txt) //verifico que se puede abrir el archivo
        {
        	archivo2_txt<<cadena<<endl;  //archivo2 + cadena + \n
			archivo2_txt.close();	 //cierro el archivo
        }
        else //sino
        cout << "No se pudo acceder al archivo" << endl;
    }
    else
    cout << "No se puede agregar una linea vacia" << endl;
}
void borrarUltimo(){
	string linea="";
    string texto="";
    string anterior="";

    ifstream archivo_txt("documento.txt"); //abro para leer al archivo

	if(archivo_txt) //verifico que se puede abrir el archivo
    {
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
    else //sino
    cout << "No se pudo acceder al archivo" << endl;
}
void borrarEspecifico(){
	string linea="";
    string texto="";
    string borrar="";
	bool encontrado=false;

    cout<<"Linea a borrar: ";
    cin.ignore();
    getline(cin, borrar);
    ifstream archivo_txt("documento.txt"); //abro para leer al archivo

    if(archivo_txt) //verifico que se puede abrir el archivo
    {
    	while(getline(archivo_txt, linea)){//lee la primera linea y la guarda en la variable linea

        	if(linea != borrar) //si linea es distinto de borrar
        	texto = texto + linea + "\n"; //acumula el texto
        	else
	    	encontrado=true;
    	}

    	archivo_txt.close(); //cierro el arhivo

        if(encontrado)
        {
        	ofstream archivo2_txt("documento.txt"); //abro para modificarlo
            if(archivo2_txt)
            {
	    		archivo2_txt << texto; //sobre escribo el texto del archivo, sin la linea a borrar
    			archivo2_txt.close(); //cierro el archivo
            }
            else
            cout << "No se pudo abrir el archivo" << endl;
        }
    	else
    	cout << "Linea no encontrada" << endl;
    }
    else //sino
    cout << "No se pudo acceder al archivo" << endl;
}

void modificarEspecifico(){
	string linea="";
    string texto="";
    string modificar="";
    string nuevo="";
	bool encontrado=false;

    cout<<"Linea a modificar ";
    cin.ignore();
    getline(cin, modificar);
    ifstream archivo_txt("documento.txt"); //abro para leer al archivo

    if(archivo_txt) //verifico que se puede abrir el archivo
    {
        while(getline(archivo_txt, linea)){//lee la primera linea y la guarda en la variable linea

            if(linea != modificar) //si linea es distinto de modificar
            texto = texto + linea + "\n"; //acumula el texto
            else
            {
                cout << "Nuevo texto: ";
                getline(cin, nuevo);

                linea = nuevo;
                texto = texto + linea + "\n";
                encontrado=true;
            }

        }

        archivo_txt.close(); //cierro el arhivo

        if(encontrado)
        {
            ofstream archivo2_txt("documento.txt");
            if(archivo2_txt)
            {
                archivo2_txt << texto;
                archivo2_txt.close();
            }
            else
            cout << "No se pudo abrir el archivo" << endl;
        }
        else
        cout << "Linea no encontrada" << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

//Func. Principal------------------------------------------------------------------------------------
int main(){
	// creamos un objeto Grafo.
	// su matriz comienza vacía y la cantidad de ciudades es 0
	 Grafo mi_grafo;
    

    //variables
	int opc;
	//objeto con parametros
	Ciudad mg(01,8,6,"monteGrande",2);

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
				borrarUltimo();
			break;
        case 4: //borrar elemento especifico de la fila
				borrarEspecifico();
			break;
        case 5: //borrar elemento especifico de la fila
				modificarEspecifico();
			break;
	    case 6:
		
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
