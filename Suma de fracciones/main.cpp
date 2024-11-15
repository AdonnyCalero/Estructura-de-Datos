
/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programar una suma fracciones       *
 * Autor:                          Adonny Calero                       *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/


#include <iostream>
#include "Fraccion.h"

using namespace std;
int main() {
    int num1, denom1, num2, denom2;

    cout << "Ingrese el numerador de la primera fraccion: ";
    cin >> num1;
    cout << "Ingrese el denominador de la primera fraccion: ";
    cin >> denom1;

    cout << "Ingrese el numerador de la segunda fraccion: ";
    cin >> num2;
    cout << "Ingrese el denominador de la segunda fraccion: ";
    cin >> denom2;

    try {
        Fraccion fraccion1(num1, denom1);
        Fraccion fraccion2(num2, denom2);

        Fraccion resultado = fraccion1.multiplicar(fraccion2);

        cout << "El resultado de la multiplicacion es: " << resultado.valorDecimal() <<endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
