#include <iostream>
#include <vector>
#include <conio.h>
#include "ListaHuespedes.h"
#include "Huesped.h"
#include "Lista.h"
#include "Validaciones.h"
#include "Menu.h"
#include "Ordenamiento.cpp"
#include "ArbolAA.h"
#include "ListaHabitaciones.h" // Incluir el archivo de encabezado de ListaHabitaciones
#include "Habitacion.h" // Incluir el archivo de encabezado de Habitacion

using namespace std;

Huesped huesped;
Validaciones validador;

void menu(ListaCircularDoble<Huesped> &lista, ListaCircularDoble<Huesped> &listaHistorial, ListaHuespedes &listaHuespedes) {
    ListaHabitaciones listaHabitaciones; // Declarar la lista de habitaciones
    bool salir = false;

    // Agregar algunas habitaciones de ejemplo
    for (int i = 1; i <= 10; ++i) {
        listaHabitaciones.agregarHabitacion(i);
    }

    while (!salir) {
        system("cls");
        cout << "========================================" << endl;
        cout << "         MENU PRINCIPAL DEL HOTEL       " << endl;
        cout << "========================================" << endl;

        vector<string> opciones = {
            "Gestion de Huespedes",
            "Asignar Habitacion",
            "Busqueda Avanzada",
            "Ordenar Huespedes",
            "Salir"
        };

        int seleccion = menuInteractivo(opciones, "Menu Principal");

        switch (seleccion) {
            case 0:
                menuGestionHuespedes(listaHuespedes);
                break;
            case 1: {
                string cedula;
                int habitacion;
                cout << "Ingrese cedula del huesped: ";
                cedula = validador.ingresarCedula("Ingrese cedula del huesped: ");
                cout << "Ingrese numero de habitacion: ";
                cin >> habitacion;
                Habitacion* hab = listaHabitaciones.buscarHabitacion(habitacion); // Buscar la habitación
                if (hab && !hab->isOcupada()) {
                    if (listaHuespedes.asignarHabitacion(cedula, habitacion)) { // Asignar la habitación
                        hab->asignarHuesped(cedula);
                        cout << "Habitacion asignada correctamente." << endl;
                    } else {
                        cout << "Huesped no encontrado." << endl;
                    }
                } else {
                    cout << "Habitacion no disponible." << endl;
                }
                system("pause");
                break;
            }
            case 2:
                menuBusquedaAvanzada(lista, listaHistorial);
                break;
            case 3:
                menuOrdenar(lista, listaHistorial);
                break;
            case 4:
                salir = true;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    }
}

int menuInteractivo(const vector<string> &opciones, const string &titulo) {
    int seleccion = 0;
    char tecla;

    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "           " << titulo << endl;
        cout << "========================================" << endl;

        for (size_t i = 0; i < opciones.size(); i++) {
            if (i == seleccion) {
                cout << " > " << opciones[i] << " < " << endl;  // Resalta la opción actual
            } else {
                cout << "   " << opciones[i] << endl;
            }
        }

        cout << "========================================" << endl;

        tecla = _getch();  // Captura la tecla sin necesidad de presionar Enter

        if (tecla == 72) { // Flecha arriba
            seleccion = (seleccion - 1 + opciones.size()) % opciones.size();
        } else if (tecla == 80) { // Flecha abajo
            seleccion = (seleccion + 1) % opciones.size();
        } else if (tecla == 13) { // Enter
            return seleccion;
        }
    }
}

void menuGestionHuespedes(ListaHuespedes &listaHuespedes)
{
    bool salirSubmenu = false;
    while (!salirSubmenu)
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "      Menu de Gestion de Huespedes   " << endl;
        cout << "========================================" << endl;

        vector<string> opcionesHuespedes = {
            "Agregar Huesped",
            "Mostrar Huespedes",
            "Buscar Huesped por Cedula",
            "Eliminar Huesped",
            "Volver al Menu Principal"};

        int seleccionHuespedes = menuInteractivo(opcionesHuespedes, "Menu de Gestion de Huespedes");

        switch (seleccionHuespedes)
        {
        case 0: {
            cin.ignore();
            string nombre = validador.ingresarString("Ingrese el nombre: ");
            cin.ignore();
            string apellido = validador.ingresarString("Ingrese el apellido: ");
            cin.ignore();
            string cedula = validador.ingresarCedula("Ingrese la cedula: ");
            cin.ignore();
            string correo = validador.ingresarCorreo("Ingrese el correo: ");
            listaHuespedes.agregarHuesped(Huesped(nombre, apellido, cedula, correo));
            listaHuespedes.guardarArchivo("huespedes.txt");
            cout << "Huesped agregado correctamente." << endl;
            system("pause");
            break;
        }
        case 1:
            listaHuespedes.mostrarHuespedes();
            system("pause");
            break;
        case 2: {
            string cedula = validador.ingresarCedula("Ingrese la cedula del huesped a buscar: ");
            Huesped* huesped = listaHuespedes.buscarHuespedPorCedula(cedula);
            if (huesped) {
                cout << "Huesped encontrado:\n" << *huesped << endl;
            } else {
                cout << "No se encontró un huesped con esa cedula." << endl;
            }
            system("pause");
            break;
        }
        case 3: {
            string cedula = validador.ingresarCedula("Ingrese la cedula del huesped a eliminar: ");
            listaHuespedes.eliminarHuesped(cedula);
            listaHuespedes.guardarArchivo("huespedes.txt");
            cout << "Huesped eliminado correctamente." << endl;
            system("pause");
            break;
        }
        case 4:
            salirSubmenu = true;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    }
}

void menuBusquedaAvanzada(ListaCircularDoble<Huesped>& lista, ListaCircularDoble<Huesped>& listaHistorial) {
    cout << "========================================" << endl;
    cout << "     MENU DE BUSQUEDA AVANZADA         " << endl;
    cout << "========================================" << endl;
    cout << "Esta funcionalidad está en desarrollo." << endl;
    system("pause");
}

void menuOrdenar(ListaCircularDoble<Huesped>& lista, ListaCircularDoble<Huesped>& listaHistorial) {
    cout << "========================================" << endl;
    cout << "        MENU DE ORDENAMIENTO            " << endl;
    cout << "========================================" << endl;
    cout << "Esta funcionalidad está en desarrollo." << endl;
    system("pause");
}