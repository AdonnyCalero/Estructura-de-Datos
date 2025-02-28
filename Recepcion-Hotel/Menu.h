#pragma once
#include <iostream>
#include <vector>
#include "Lista.h"
#include "ListaHuespedes.h"
#include "ArbolAA.h"

using namespace std;

void menu(ListaCircularDoble<Huesped> &lista, ListaCircularDoble<Huesped> &listaHistorial, ListaHuespedes &listaHuespedes);
void menuGestionHuespedes(ListaHuespedes &listaHuespedes);
int menuInteractivo(const vector<string> &opciones, const string &titulo = "Menu Interactivo");
void menuBusquedaAvanzada(ListaCircularDoble<Huesped> &lista, ListaCircularDoble<Huesped> &listaHistorial);
void menuOrdenar(ListaCircularDoble<Huesped> &lista, ListaCircularDoble<Huesped> &listaHistorial);
