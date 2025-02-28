#ifndef ARBOLAA_H
#define ARBOLAA_H

#include "NodoAA.h"
#include "Lista.h"     
#include "Huesped.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

template <typename T>
class ArbolAA {
public:
    ArbolAA() : raiz(nullptr) {}

    void insertar(int clave);
    void insertarHuesped(T, T, T, T);
    void buscar(int clave);
    void eliminar(int clave);
    void mostrar();
    NodoAA<T>* raiz;
    void guardarEnArchivo(const std::string& nombreArchivo);
    void reconstruirDesdeArchivo(const std::string& nombreArchivo);

private:
    NodoAA<T>* inclinar(NodoAA<T>* nodo);
    NodoAA<T>* dividir(NodoAA<T>* nodo);
    NodoAA<T>* insertar(NodoAA<T>* nodo, int clave);
    NodoAA<T>* insertarHuesped(NodoAA<T>* nodo, T _nombre, T _apellido, T _cedula, T _correo);
    NodoAA<T>* eliminar(NodoAA<T>* nodo, int clave);
    void guardarEnArchivoRecursivo(NodoAA<T>* nodo, std::ofstream& archivo);
};

template <typename T>
NodoAA<T>* ArbolAA<T>::insertarHuesped(NodoAA<T>* nodo, T _nombre, T _apellido, T _cedula, T _correo) {
    if (nodo == nullptr)
        return new NodoAA<T>(_nombre, _apellido, _cedula, _correo);

    if (stoi(_cedula) < stoi(nodo->cedula))
        nodo->izquierda = insertarHuesped(nodo->izquierda, _nombre, _apellido, _cedula, _correo);
    else if (stoi(_cedula) > stoi(nodo->cedula))
        nodo->derecha = insertarHuesped(nodo->derecha, _nombre, _apellido, _cedula, _correo);
    else
        return nodo;

    nodo = inclinar(nodo);
    nodo = dividir(nodo);
    return nodo;
}

template <typename T>
void ArbolAA<T>::insertarHuesped(T _nombre, T _apellido, T _cedula, T _correo) {
    raiz = insertarHuesped(raiz, _nombre, _apellido, _cedula, _correo);
}

#endif // ARBOLAA_H