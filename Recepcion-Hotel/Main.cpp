#include <iostream>
#include "Menu.h"
#include "ListaHuespedes.h"
#include "Lista.h"

//g++ -o hotel Main.cpp Huesped.cpp ListaHuespedes.cpp menu.cpp Validaciones.cpp -std=c++11
//g++ -o hotel Main.cpp Huesped.cpp ListaHuespedes.cpp menu.cpp Validaciones.cpp ListaHabitaciones.cpp -std=c++11

int main() {
    ListaHuespedes listaHuespedes;
    listaHuespedes.cargarArchivo("huespedes.txt");

    ListaCircularDoble<Huesped> listaHuespedesHistorial;
    listaHuespedesHistorial.CargarArchivo("huespedes_historial.txt");

    ListaCircularDoble<Huesped> listaHuespedesActivos;
    listaHuespedesActivos.CargarArchivo("huespedes.txt");
    
    menu(listaHuespedesActivos, listaHuespedesHistorial, listaHuespedes);
    
    return 0;
}