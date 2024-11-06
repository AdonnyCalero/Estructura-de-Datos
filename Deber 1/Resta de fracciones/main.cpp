/***********************************************************************
          Universidad de las Fuerzas Armadas ESPE
 * Module:  Fraccion.h
 * Author:  Adonny Calero
 * Modified: sábado, 2 de noviembre de 2024 18:29:40
 * Purpose: Resta de fracciones
 * Materia:  Estructura de Datos
 * NRC:  1978
 ***********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Utilidades {
public:

    static bool esEntero(const string& entrada) {
        for (char c : entrada) {
            if (!isdigit(c) && c != '-' && c != '+') {
                return false;
            }
        }
        return true;
    }

    static int leerEntero(const string& mensaje) {
        string entrada;
        int valor;
        while (true) {
            cout << mensaje;
            cin >> entrada;

            if (esEntero(entrada) && entrada.find('.') == string::npos) {
                stringstream ss(entrada);
                ss >> valor;
                return valor;
            } else {
                cout << "Error: Ingrese un numero entero valido sin decimales." << endl;
            }
        }
    }
};

class Fraccion {
private:
    int numerador;
    int denominador;

    int calcularMCD(int a, int b) const {
        if (b == 0) {
            return a;
        }
        return calcularMCD(b, a % b);
    }

    void simplificar() {
        int divisor = calcularMCD(numerador, denominador);
        numerador /= divisor;
        denominador /= divisor;
    }

public:
    Fraccion(int num = 0, int den = 1) : numerador(num), denominador(den) {
        if (denominador == 0) {
            cout << "Error: el denominador no puede ser cero." << endl;
            exit(1);
        }
        simplificar();
    }

    int getNumerador() const {
        return numerador;
    }

    int getDenominador() const {
        return denominador;
    }

    void setNumerador(int num) {
        numerador = num;
        simplificar();
    }

    void setDenominador(int den) {
        if (den == 0) {
            cout << "Error: el denominador no puede ser cero." << endl;
            exit(1);
        }
        denominador = den;
        simplificar();
    }

    Fraccion restar(const Fraccion &otra) const {
        int nuevoNumerador = numerador * otra.denominador - otra.numerador * denominador;
        int nuevoDenominador = denominador * otra.denominador;
        Fraccion resultado(nuevoNumerador, nuevoDenominador);
        resultado.simplificar();
        return resultado;
    }

    void mostrar() const {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
    int num1 = Utilidades::leerEntero("Ingrese el numerador de la primera fracción: ");
    int den1;
    while (true) {
        den1 = Utilidades::leerEntero("Ingrese el denominador de la primera fracción: ");
        if (den1 != 0) break;
        cout << "Error: El denominador no puede ser cero." << endl;
    }

    int num2 = Utilidades::leerEntero("Ingrese el numerador de la segunda fracción: ");
    int den2;
    while (true) {
        den2 = Utilidades::leerEntero("Ingrese el denominador de la segunda fracción: ");
        if (den2 != 0) break;
        cout << "Error: El denominador no puede ser cero." << endl;
    }

    Fraccion fraccion1(num1, den1);
    Fraccion fraccion2(num2, den2);

    Fraccion resultado = fraccion1.restar(fraccion2);

    cout << "La resta de las fracciones es: ";
    resultado.mostrar();

    return 0;
}


