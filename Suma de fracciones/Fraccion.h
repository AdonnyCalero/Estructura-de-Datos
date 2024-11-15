#pragma once
// Fraccion.h
#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    // Constructor
    Fraccion(int num = 0, int denom = 1);

    // Métodos de acceso
    int getNumerador() const;
    int getDenominador() const;

    // Método para calcular el valor decimal de la fracción
    float valorDecimal() const;

    // Método para multiplicar dos fracciones
    Fraccion multiplicar(const Fraccion& otra) const;
};

#endif
