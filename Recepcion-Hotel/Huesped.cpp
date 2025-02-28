#include "Huesped.h"
#include <iostream>

using namespace std;

Huesped::Huesped() {
    nombre = "";
    apellido = "";
    cedula = "";
    correo = "";
    numeroHabitacion = -1; // 🚀 Se inicializa en -1 para indicar que no tiene habitación asignada
}

Huesped::Huesped(const std::string &nombre, const std::string &apellido, const std::string &cedula, const std::string &correo) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->cedula = cedula;
    this->correo = correo;
    this->numeroHabitacion = -1; // 🚀 Se inicializa en -1
}

void Huesped::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Huesped::setApellido(const string& apellido) {
    this->apellido = apellido;
}

void Huesped::setCedula(const string& cedula) {
    this->cedula = cedula;
}

void Huesped::setCorreo(const string& correo) {
    this->correo = correo;
}

string Huesped::getNombre() const {
    return nombre;
}

string Huesped::getApellido() const {
    return apellido;
}

string Huesped::getCedula() const {
    return cedula;
}

string Huesped::getCorreo() const {
    return correo;
}

void Huesped::setNumeroHabitacion(int numero) {
    this->numeroHabitacion = numero;
}

int Huesped::getNumeroHabitacion() const {
    return numeroHabitacion;
}

ostream& operator<<(ostream& os, const Huesped& huesped) {
    os << "Nombre: " << huesped.getNombre() << "\n"
       << "Apellido: " << huesped.getApellido() << "\n"
       << "Cédula: " << huesped.getCedula() << "\n"
       << "Correo: " << huesped.getCorreo() << "\n"
       << "Habitación: " << (huesped.getNumeroHabitacion() == -1 ? "No asignada" : to_string(huesped.getNumeroHabitacion())) << "\n";
    return os;
}