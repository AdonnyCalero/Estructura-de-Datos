/***********************************************************************
          Universidad de las Fuerzas Armadas ESPE
 * Module:  Fraccion.h
 * Author:  Adonny Calero
 * Modified: domingo, 3 de noviembre de 2024 14:10:17
 * Purpose: Division de fracciones
 * Materia:  Estructura de Datos
 * Profesor:  Fernando Solís
 * NRC:  1978
 ***********************************************************************/
#include <iostream>
#include <string>
#include <cctype>

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
                cout << "Entrada inválida. Por favor, ingrese un número entero sin decimales." << endl;
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


    Fraccion dividir(const Fraccion &otra) const {
        if (otra.numerador == 0) {
            throw invalid_argument("No se puede dividir por una fracción con numerador cero.");
        }
        int nuevoNumerador = numerador * otra.getDenominador();
        int nuevoDenominador = denominador * otra.getNumerador();
        return Fraccion(nuevoNumerador, nuevoDenominador);
    }


    void mostrar() const {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {

    int num1 = Utilidades::solicitarEntero("Ingrese el numerador de la primera fraccion: ");
    int den1;
    do {
        den1 = Utilidades::solicitarEntero("Ingrese el denominador de la primera fraccion (no puede ser cero): ");
        if (den1 == 0) {
            cout << "El denominador no puede ser cero. Intente de nuevo." << endl;
        }
    } while (den1 == 0);
    Fraccion f1(num1, den1);


    int num2 = Utilidades::solicitarEntero("Ingrese el numerador de la segunda fraccion: ");
    int den2;
    do {
        den2 = Utilidades::solicitarEntero("Ingrese el denominador de la segunda fraccion (no puede ser cero): ");
        if (den2 == 0) {
            cout << "El denominador no puede ser cero. Intente de nuevo." << endl;
        }
    } while (den2 == 0);
    Fraccion f2(num2, den2);


    try {
        Fraccion resultado = f1.dividir(f2);
        cout << "Resultado de la división: ";
        resultado.mostrar();
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
