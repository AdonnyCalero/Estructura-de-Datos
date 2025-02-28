#pragma once

#include <string>

class Habitacion {
private:
    int numero;
    bool ocupada;
    std::string cedulaHuesped;

public:
    Habitacion(int num) : numero(num), ocupada(false), cedulaHuesped("") {}

    int getNumero() const { return numero; }
    bool isOcupada() const { return ocupada; }
    std::string getCedulaHuesped() const { return cedulaHuesped; }

    void asignarHuesped(const std::string &cedula) {
        ocupada = true;
        cedulaHuesped = cedula;
    }

    void liberar() {
        ocupada = false;
        cedulaHuesped = "";
    }
};