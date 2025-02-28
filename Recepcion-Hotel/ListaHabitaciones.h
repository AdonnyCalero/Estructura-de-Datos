#pragma once

#include "Habitacion.h"
#include <iostream>

class NodoHabitacion {
public:
    Habitacion habitacion;
    NodoHabitacion *siguiente;
    NodoHabitacion *anterior;

    NodoHabitacion(Habitacion hab) : habitacion(hab), siguiente(nullptr), anterior(nullptr) {}
};

class ListaHabitaciones {
private:
    NodoHabitacion *cabeza;

public:
    ListaHabitaciones();
    void agregarHabitacion(int numero);
    Habitacion* buscarHabitacion(int numero);
    void mostrarHabitaciones();
};
