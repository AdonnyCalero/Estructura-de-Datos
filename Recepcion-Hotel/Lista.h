#pragma once
#include "Nodo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class ListaCircularDoble {
private:
    Nodo<T>* ultimo;
    Nodo<T>* primero;
public:
    Nodo<T>* getPrimero() {
        return primero;
    }
    
    ListaCircularDoble();
    void insertar(T dato, const std::string& nombreArchivo);
    void buscarPorCedula(string cedula);
    Nodo<T>* obtenerNodoPorCedula(string cedula);
    void eliminarPorCedula(string cedula);
    void mostrar(Nodo<T>* aux);
    void CargarArchivo(string nombreArchivo);
    void GuardarArchivo(string nombreArchivo);
    static std::string cifrarTexto(const std::string &texto);
    static std::string descifrarTexto(const std::string &texto);
};

// IMPLEMENTACIÓN DE LA CLASE (se mueve desde Lista.cpp)

template <typename T>
ListaCircularDoble<T>::ListaCircularDoble() {
    primero = nullptr;
    ultimo = nullptr;
}

template <typename T>
void ListaCircularDoble<T>::insertar(T dato, const std::string& nombreArchivo) {
    Nodo<T>* nuevoHuesped = new Nodo<T>(dato);
    if (primero == nullptr) {
        primero = nuevoHuesped;
        primero->setSiguiente(primero);
        primero->setAnterior(primero);
        ultimo = primero;
    } else {
        ultimo->setSiguiente(nuevoHuesped);
        nuevoHuesped->setAnterior(ultimo);
        ultimo = nuevoHuesped;
        ultimo->setSiguiente(primero);
        primero->setAnterior(ultimo);
    }
    GuardarArchivo(nombreArchivo);
}

template <typename T>
void ListaCircularDoble<T>::buscarPorCedula(string cedula) {
    if (primero == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Nodo<T>* aux = primero;
    do {
        if (aux->getDato().getCedula() == cedula) {
            cout << "========================================" << endl;
            cout << "   HUÉSPED REGISTRADO" << endl;
            cout << "========================================" << endl;
            cout << aux->getDato() << endl;
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != primero);
    cout << "El huésped con la cédula " << cedula << " no está registrado." << endl;
}

template <typename T>
void ListaCircularDoble<T>::eliminarPorCedula(string cedula) {
    if (primero == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Nodo<T>* aux = primero;
    Nodo<T>* anterior = nullptr;
    if (primero == ultimo && primero->getDato().getCedula() == cedula) {
        delete primero;
        primero = nullptr;
        ultimo = nullptr;
        cout << "El huésped con la cédula " << cedula << " ha sido eliminado." << endl;
        GuardarArchivo("huespedes.txt");
        return;
    }
    do {
        if (aux->getDato().getCedula() == cedula) {
            if (aux == primero) {
                primero = primero->getSiguiente();
                primero->setAnterior(ultimo);
                ultimo->setSiguiente(primero);
            } else if (aux == ultimo) {
                ultimo = ultimo->getAnterior();
                ultimo->setSiguiente(primero);
                primero->setAnterior(ultimo);
            } else {
                anterior = aux->getAnterior();
                anterior->setSiguiente(aux->getSiguiente());
                aux->getSiguiente()->setAnterior(anterior);
            }
            delete aux;
            cout << "El huésped con la cédula " << cedula << " ha sido eliminado." << endl;
            GuardarArchivo("huespedes.txt");
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != primero);
    cout << "El huésped con la cédula " << cedula << " no se encontró." << endl;
}

template <typename T>
void ListaCircularDoble<T>::CargarArchivo(std::string nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << "." << std::endl;
        return;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string cedula, nombre, apellido, correo;
        if (std::getline(ss, cedula, ',') &&
            std::getline(ss, nombre, ',') &&
            std::getline(ss, apellido, ',') &&
            std::getline(ss, correo, ',')) {
            T huesped(nombre, apellido, cedula, correo);
            this->insertar(huesped, nombreArchivo);
        }
    }
    archivo.close();
}

template <typename T>
void ListaCircularDoble<T>::GuardarArchivo(std::string nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << "." << std::endl;
        return;
    }
    Nodo<T>* actual = primero;
    do {
        T huesped = actual->getDato();
        archivo << huesped.getCedula() << ","
                << huesped.getNombre() << ","
                << huesped.getApellido() << ","
                << huesped.getCorreo() << endl;
        actual = actual->getSiguiente();
    } while (actual != primero);
    archivo.close();
}


