#ifndef NodoAA_H
#define NodoAA_H

#include <iostream>

template <typename T>
class NodoAA {
public:
    T nombre, apellido, cedula, correo;
    T getNombre();
    void setNombre(T);
    T getApellido();
    void setApellido(T);
    T getCedula();
    void setCedula(T);
    T getCorreo();
    void setCorreo(T);

    int clave;
    int nivel;
    NodoAA* izquierda;
    NodoAA* derecha;

    NodoAA();
    ~NodoAA();
    NodoAA(int k);
    NodoAA(T _nombre, T _apellido, T _cedula, T _correo);
};

template <typename T>
NodoAA<T>::NodoAA() {}

template <typename T>
NodoAA<T>::~NodoAA() {}

template <typename T>
NodoAA<T>::NodoAA(int k) : clave(k), nivel(1), izquierda(nullptr), derecha(nullptr) {}

template <typename T>
NodoAA<T>::NodoAA(T _nombre, T _apellido, T _cedula, T _correo) {
    nombre = _nombre;
    apellido = _apellido;
    cedula = _cedula;
    correo = _correo;
    clave = stoi(_cedula);
    nivel = 1;
    izquierda = nullptr;
    derecha = nullptr;
}

template <typename T>
T NodoAA<T>::getNombre() { return nombre; }

template <typename T>
void NodoAA<T>::setNombre(T _nombre) { nombre = _nombre; }

template <typename T>
T NodoAA<T>::getApellido() { return apellido; }

template <typename T>
void NodoAA<T>::setApellido(T _apellido) { apellido = _apellido; }

template <typename T>
T NodoAA<T>::getCedula() { return cedula; }

template <typename T>
void NodoAA<T>::setCedula(T _cedula) { cedula = _cedula; }

template <typename T>
T NodoAA<T>::getCorreo() { return correo; }

template <typename T>
void NodoAA<T>::setCorreo(T _correo) { correo = _correo; }

#endif // NodoAA_H