#pragma once

#include <iostream>
#include <string>

using namespace std;

class Huesped {
private:
    std::string nombre;
    std::string apellido;
    std::string cedula;
    std::string correo;
    int numeroHabitacion; 

public:
    Huesped();
    Huesped(const std::string &nombre, const std::string &apellido, const std::string &cedula, const std::string &correo);

    void setNombre(const std::string& nombre);
    void setApellido(const std::string& apellido);
    void setCedula(const std::string& cedula);
    void setCorreo(const std::string& correo);

    std::string getNombre() const;
    std::string getApellido() const;
    std::string getCedula() const;
    std::string getCorreo() const;

    void setNumeroHabitacion(int numero);
    int getNumeroHabitacion() const;

    friend ostream& operator<<(ostream& os, const Huesped& huesped);


};