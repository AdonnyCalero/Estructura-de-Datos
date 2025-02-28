#include "ListaHabitaciones.h"

ListaHabitaciones::ListaHabitaciones() : cabeza(nullptr) {}

void ListaHabitaciones::agregarHabitacion(int numero) {
    Habitacion hab(numero);
    NodoHabitacion *nuevo = new NodoHabitacion(hab);
    if (!cabeza) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    } else {
        NodoHabitacion *ultimo = cabeza->anterior;
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
    }
}

Habitacion* ListaHabitaciones::buscarHabitacion(int numero) {
    if (!cabeza) return nullptr;
    NodoHabitacion *actual = cabeza;
    do {
        if (actual->habitacion.getNumero() == numero) {
            return &actual->habitacion;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);
    return nullptr;
}

void ListaHabitaciones::mostrarHabitaciones() {
    if (!cabeza) {
        std::cout << "No hay habitaciones disponibles.\n";
        return;
    }
    NodoHabitacion *actual = cabeza;
    do {
        std::cout << "Habitacion " << actual->habitacion.getNumero() << " - "
                  << (actual->habitacion.isOcupada() ? "Ocupada" : "Libre") << std::endl;
        actual = actual->siguiente;
    } while (actual != cabeza);
}
