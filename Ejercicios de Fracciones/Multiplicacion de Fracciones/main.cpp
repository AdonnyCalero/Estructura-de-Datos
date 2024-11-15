/***********************************************************************
          Universidad de las Fuerzas Armadas ESPE
 * Module:  Fraccion.h
 * Author:  Adonny Calero
 * Modified: sábado, 2 de noviembre de 2024 23:47:40
 * Purpose: Multiplicación de fracciones
 * Materia:  Estructura de Datos
 * NRC:  1978
 ***********************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Utilidades {
public:
    static bool esEntero(const string& str) {
        if (str.empty()) return false;
        int inicio = (str[0] == '-') ? 1 : 0;
        for (int i = inicio; i < str.size(); ++i) {
            if (!isdigit(str[i])) return false;
        }
        return true;
    }

    static int solicitarEntero(const string& mensaje) {
        string entrada;
        while (true) {
            cout << mensaje;
            cin >> entrada;

            if (esEntero(entrada)) {
                return stoi(entrada);
            } else {
                cout << "Entrada invalida. Por favor, ingrese un numero entero sin decimales." << endl;
            }
        }
    }
};

class Fraccion {
private:
    int numerador;
    int denominador;

public:

    Fraccion(int num, int den) : numerador(num), denominador(den) {
        while (denominador == 0) {
            cout << "El denominador no puede ser cero. Ingrese de nuevo: ";
            denominador = Utilidades::solicitarEntero("");
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
    }

    void setDenominador(int den) {
        if (den != 0) {
            denominador = den;
        } else {
            cout << "El denominador no puede ser cero." << endl;
        }
    }


    Fraccion multiplicar(const Fraccion& otra) const {
        int nuevoNumerador = this->numerador * otra.numerador;
        int nuevoDenominador = this->denominador * otra.denominador;
        return Fraccion(nuevoNumerador, nuevoDenominador);
    }


    void simplificar() {
        int mcd = calcularMCD(numerador, denominador);
        numerador /= mcd;
        denominador /= mcd;
    }


    void mostrar() const {
        cout << numerador << "/" << denominador << endl;
    }

private:

    int calcularMCD(int a, int b) const {
        if (b == 0) {
            return a;
        }
        return calcularMCD(b, a % b);
    }
};

int main() {

    int num1 = Utilidades::solicitarEntero("Ingrese el numerador de la primera fracción: ");
    int den1 = Utilidades::solicitarEntero("Ingrese el denominador de la primera fracción: ");
    Fraccion f1(num1, den1);

    int num2 = Utilidades::solicitarEntero("Ingrese el numerador de la segunda fracción: ");
    int den2 = Utilidades::solicitarEntero("Ingrese el denominador de la segunda fracción: ");
    Fraccion f2(num2, den2);


    Fraccion resultado = f1.multiplicar(f2);
    resultado.simplificar();


    cout << "Resultado de la multiplicación: ";
    resultado.mostrar();

    return 0;
}


