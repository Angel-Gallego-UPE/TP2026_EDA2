#include "Historial.h"

Historial::Historial() {
    strcpy(fecha, "");
    strcpy(origen, "");
    strcpy(destino, "");
    strcpy(recorrido, "");
    distanciaTotal = 0;
}

Historial::Historial(string _fecha, string _origen, string _destino, string _recorrido, double _distancia) {
    strncpy(fecha, _fecha.c_str(), 24);
    fecha[24] = '\0';

    strncpy(origen, _origen.c_str(), 49);
    origen[49] = '\0';

    strncpy(destino, _destino.c_str(), 49);
    destino[49] = '\0';

    strncpy(recorrido, _recorrido.c_str(), 249);
    recorrido[249] = '\0';

    distanciaTotal = _distancia;
}

string Historial::getFecha() { return string(fecha); }
string Historial::getOrigen() { return string(origen); }
string Historial::getDestino() { return string(destino); }
string Historial::getRecorrido() { return string(recorrido); }
double Historial::getDistanciaTotal() { return distanciaTotal; }

// Agrega un nuevo viaje calculado al final de historial.bin
void Historial::guardar() {
    ofstream archivo("historial.bin", ios::binary | ios::app);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<char*>(this), sizeof(Historial));
        archivo.close();
    }
}

// Lee todos los viajes guardados en historial.bin
vector<Historial> Historial::leerTodo() {
    vector<Historial> lista;
    ifstream archivo("historial.bin", ios::binary);
    if (archivo.is_open()) {
        Historial reg;
        while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Historial))) {
            lista.push_back(reg);
        }
        archivo.close();
    }
    return lista;
}
