#include "ListaHuespedes.h"
#include <fstream>
#include <sstream>
#include "Lista.h"

void ListaHuespedes::agregarHuesped(const Huesped &huesped) {
    huespedes.push_back(huesped);
}

Huesped* ListaHuespedes::buscarHuespedPorCedula(const string &cedula) {
    for (auto &huesped : huespedes) {
        if (huesped.getCedula() == cedula) {
            return &huesped;
        }
    }
    return nullptr;
}

void ListaHuespedes::mostrarHuespedes() const {
    for (const auto &huesped : huespedes) {
        cout << huesped << endl;
    }
}

bool ListaHuespedes::estaVacia() const {
    return huespedes.empty();
}

void ListaHuespedes::cargarArchivo(const string &archivo) {
    ifstream file(archivo);
    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            stringstream ss(linea);
            string nombre, apellido, cedula, correo;
            getline(ss, nombre, ',');
            getline(ss, apellido, ',');
            getline(ss, cedula, ',');
            getline(ss, correo, ',');
            Huesped huesped(nombre, apellido, cedula, correo);
            agregarHuesped(huesped);
        }
        file.close();
    }
}

void ListaHuespedes::guardarArchivo(const string &archivo) const {
    ofstream file(archivo);
    if (file.is_open()) {
        for (const auto &huesped : huespedes) {
            file << huesped.getNombre() << ","
                 << huesped.getApellido() << ","
                 << huesped.getCedula() << ","
                 << huesped.getCorreo() << endl;
        }
        file.close();
    }
}

void ListaHuespedes::eliminarHuesped(const string &cedula) {
    for (auto it = huespedes.begin(); it != huespedes.end(); ++it) {
        if (it->getCedula() == cedula) {
            huespedes.erase(it);
            cout << "Huesped eliminado correctamente." << endl;
            guardarArchivo("huespedes.txt");  // Se actualiza el archivo después de eliminar
            return;
        }
    }
    cout << "No se encontró un huesped con esa cédula." << endl;
}

bool ListaHuespedes::asignarHabitacion(const string &cedula, int numeroHabitacion) {
    Huesped* huesped = buscarHuespedPorCedula(cedula);
    if (huesped) {
        huesped->setNumeroHabitacion(numeroHabitacion);  // Este método debe existir en Huesped.h
        return true;
    }
    return false;
}