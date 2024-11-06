/***********************************************************************
          Universidad de las Fuerzas Armadas ESPE
 * Module:  Fraccion.h
 * Author:  Adonny Calero
 * Modified: domingo, 3 de noviembre de 2024 21:17:08
 * Purpose: Potenciación de fracciones
 * Materia:  Estructura de Datos
 * Profesor:  Fernando Solís
 * NRC:  1978
 ***********************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

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
                cout << "Entrada invalida. Por favor, ingrese un número entero sin decimales." << endl;
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

public:

    Fraccion(int num, int den) : numerador(num), denominador(den) {
        if (den == 0) {
            cout << "El denominador no puede ser cero. Se establece a 1." << endl;
            denominador = 1;
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
            cout << "El denominador no puede ser cero." << endl;
        } else {
            denominador = den;
            simplificar();
        }
    }


    void simplificar() {
        int mcd = calcularMCD(abs(numerador), abs(denominador));
        numerador /= mcd;
        denominador /= mcd;


        if (denominador < 0) {
            numerador = -numerador;
            denominador = -denominador;
        }
    }


    Fraccion potenciar(int exponente) const {
        int nuevoNumerador, nuevoDenominador;

        if (exponente < 0) {

            nuevoNumerador = pow(denominador, -exponente);
            nuevoDenominador = pow(numerador, -exponente);
        } else {

            nuevoNumerador = pow(numerador, exponente);
            nuevoDenominador = pow(denominador, exponente);
        }

        return Fraccion(nuevoNumerador, nuevoDenominador);
    }


    void mostrar() const {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {

    int num = Utilidades::solicitarEntero("Ingrese el numerador de la fracción: ");
    int den;
    do {
        den = Utilidades::solicitarEntero("Ingrese el denominador de la fracción (no puede ser cero): ");
        if (den == 0) {
            cout << "El denominador no puede ser cero. Intente de nuevo." << endl;
        }
    } while (den == 0);
    Fraccion fraccion(num, den);


    int exponente = Utilidades::solicitarEntero("Ingrese el exponente: ");


    Fraccion resultado = fraccion.potenciar(exponente);
    cout << "Resultado de la potenciación: ";
    resultado.mostrar();

    return 0;
}

