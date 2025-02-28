#pragma once

#include "Huesped.h"
#include <vector>

class ListaHuespedes {
private:
    std::vector<Huesped> huespedes;

public:
    void agregarHuesped(const Huesped &huesped);
    Huesped* buscarHuespedPorCedula(const string &cedula);
    void mostrarHuespedes() const;
    bool estaVacia() const;
    void cargarArchivo(const string &archivo);
    void guardarArchivo(const string &archivo) const;
    void eliminarHuesped(const string &cedula);
    bool asignarHabitacion(const string &cedula, int numeroHabitacion);
};