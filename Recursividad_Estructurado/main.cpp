/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programar una suma fracciones       *
 * Autor:                          Adonny Calero                        *
 * Fecha de creacion:              06/10/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <iostream>
#include <cstdlib>  // Para atoi, malloc y realloc
#include <conio.h>  // Para getch()
#include <memory>

using namespace std;

// Funci�n para ingresar solo enteros utilizando memoria din�mica sin vectores
int ingresar(const char *msj) {
    char *cad = (char*)malloc(10 * sizeof(char));  // Asignamos memoria din�mica inicial
    if (cad == nullptr) {  // Comprobamos que la asignaci�n fue exitosa
        cout << "Error al asignar memoria." << endl;
        exit(1);  // Terminamos el programa si no se pudo asignar memoria
    }

    char c;
    int i = 0;
    int valor = 0;

    cout << msj;
    while ((c = getch()) != 13) {  // 13 es el c�digo ASCII de Enter
        if (c >= '0' && c <= '9') {
            cout << c;
            cad[i++] = c;
        } else if (c == 8) {  // 8 es el c�digo ASCII de Backspace
            if (i > 0) {
                cout << "\b \b";
                i--;
            }
        }

        // Si el arreglo se llena, redimensionamos la memoria
        if (i % 10 == 0) {  // Cada vez que alcanzamos el l�mite de 10 caracteres
            cad = (char*)realloc(cad, (i + 10) * sizeof(char));  // Aumentamos el tama�o del arreglo
            if (cad == nullptr) {  // Comprobamos si realloc fue exitoso
                cout << "Error al redimensionar la memoria." << endl;
                exit(1);  // Terminamos el programa si no se pudo redimensionar
            }
        }
    }

    cad[i] = '\0';  // Agregamos el car�cter nulo al final de la cadena
    valor = atoi(cad);  // Convertimos la cadena a un entero usando atoi
    cout << endl;  // Nueva l�nea despu�s de Enter

    free(cad);  // Liberamos la memoria antes de salir de la funci�n

    return valor;
}

template <typename T>
class Recursividad {
public:
    // Recursividad Simple: Factorial
    T factorial(T n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    // Recursividad de Cola: Suma de los primeros N n�meros
    T sumaRecursivaCola(T n, T acumulador = 0) {
        if (n == 0) return acumulador;
        return sumaRecursivaCola(n - 1, acumulador + n);
    }

    // Recursividad no Cola: Potencia
    T potencia(T base, T exponente) {
        if (exponente == 0) return 1;
        return base * potencia(base, exponente - 1);
    }

    // Recursividad M�ltiple: Fibonacci
    T fibonacci(T n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    // Recursividad Indirecta: Par/Impar
    T esPar(T n) {
        if (n == 0) return 1; // 1 representa que es par
        return esImpar(n - 1);
    }

    T esImpar(T n) {
        if (n == 0) return 0; // 0 representa que es impar
        return esPar(n - 1);
    }

    // Recursividad Mutua: A y B llam�ndose mutuamente
    T funcionA(T n) {
        if (n <= 0) return n;
        return funcionB(n - 1);
    }

    T funcionB(T n) {
        if (n <= 0) return n + 1;
        return funcionA(n - 2);
    }

    // Recursividad Nida: N�mero de elementos en una secuencia hasta llegar a 1
    T cuentaNidada(T n) {
        if (n <= 1) return 1;
        return 1 + cuentaNidada(cuentaNidada(n - 1));
    }
};

int main() {
    // Creamos un objeto de la clase usando memoria din�mica
    unique_ptr<Recursividad<int>> recursividad = make_unique<Recursividad<int>>();
    int n;

    // Pedimos al usuario el valor para factorial
    n = ingresar("Ingrese un n�mero para calcular su factorial (Recursividad Simple): ");
    cout << "Factorial de " << n << " es: " << recursividad->factorial(n) << endl;

    // Pedimos al usuario el valor para suma recursiva de cola
    n = ingresar("Ingrese un n�mero para sumar los primeros N n�meros (Recursividad de Cola): ");
    cout << "Suma de los primeros " << n << " n�meros es: " << recursividad->sumaRecursivaCola(n) << endl;

    // Pedimos al usuario el valor para calcular la potencia
    int base = ingresar("Ingrese la base para calcular la potencia (Recursividad no Cola): ");
    int exponente = ingresar("Ingrese el exponente para la potencia: ");
    cout << "Resultado de " << base << "^" << exponente << " es: " << recursividad->potencia(base, exponente) << endl;

    // Pedimos al usuario el valor para el c�lculo de Fibonacci
    n = ingresar("Ingrese un n�mero para calcular Fibonacci (Recursividad M�ltiple): ");
    cout << "Fibonacci de " << n << " es: " << recursividad->fibonacci(n) << endl;

    // Pedimos al usuario un n�mero para verificar si es par o impar
    n = ingresar("Ingrese un n�mero para verificar si es par (Recursividad Indirecta): ");
    cout << n << " es " << (recursividad->esPar(n) ? "par" : "impar") << endl;

    // Pedimos al usuario un n�mero para la funci�n mutua A
    n = ingresar("Ingrese un n�mero para la funci�n mutua A (Recursividad Mutua): ");
    cout << "Resultado de la funci�n mutua A(" << n << ") es: " << recursividad->funcionA(n) << endl;

    // Pedimos al usuario un n�mero para la cuenta nidada
    n = ingresar("Ingrese un n�mero para contar recursivamente hasta 1 (Recursividad Nidada): ");
    cout << "Cuenta nidada de " << n << " es: " << recursividad->cuentaNidada(n) << endl;

    return 0;
}


