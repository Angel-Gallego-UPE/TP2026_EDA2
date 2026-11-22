#ifndef HistorialH
#define HistorialH

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Historial {
private:
    char fecha[25];
    char origen[50];
    char destino[50];
    char recorrido[250];
    double distanciaTotal;

public:
    Historial();
    Historial(string _fecha, string _origen, string _destino, string _recorrido, double _distancia);

    // Getters para mostrar en la interfaz
    string getFecha();
    string getOrigen();
    string getDestino();
    string getRecorrido();
    double getDistanciaTotal();

    // Persistencia en archivo binario (historial.bin)
    void guardar();
    static vector<Historial> leerTodo();
};

#endif
