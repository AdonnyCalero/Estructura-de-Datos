/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programar una suma fracciones       *
 * Autor:                          Adonny Calero                        *
 * Fecha de creacion:              06/10/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

int ingresar(char *);

//Ingresar enteros------------------------------------------------------------------------

int ingresar(char *msj){
    char cad[10];
    char c;
    int i = 0;
    int valor = 0;
    printf("%s", msj);
    while((c = getch()) != 13){
        if (c >= '0' && c <= '9'){
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        }
    }
    cad[i++] = '\0';
    valor = atoi(cad);
    return valor;
}


//Ingresar una letra-------------------------------------------------------------------------
//int ingresarLetra(char *);

char ingresarLetra(char *msj) {
    char c;
    printf("%s", msj);
    while (true) {
        c = getch();
        if (isalpha(c)) {
            printf("%c", c);
            return c;
        } else if (c == 8) {
            printf("\b \b");
        }
    }
}



//Ingresar float------------------------------------------------------------------------------

float ingresarFloat(char *);
float ingresarFloat(char *msj){
    char cad[10];
    char c;
    int i = 0;
    float valor = 0;
    printf("%s", msj);
    while((c = getch()) != 13){
        if (c >= '0' && c <= '9'){
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (c == 46) {
            bool aux = false;
            for (int j = 0; cad[j] != '\0'; j++) {
                if (cad[j] == 46){
                    aux = true;
                    break;
                }
            }
            if(aux == false){
                printf("%c", c);
                cad[i++] = c;
            }
        }
    }
    cad[i++] = '\0';
    for (int j = 0; cad[j] != '\0'; j++) {
        valor = atof(cad);
    }
    return valor;
}

//ingresar un string---------------------------------------------------------------------------------------
string ingresarString(char *);
string ingresarString(char *msj) {
    char cad[10];
    char c;
    int i = 0;
    string valor;
    printf("%s", msj);
    while ((c = getch()) != 13) {
        if (isalpha(c)) {
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        }
    }
    cad[i] = '\0';
    for (int j = 0; cad[j] != '\0'; j++) {
        valor = valor + cad[j];
    }

    return valor;
}

//Ingresar double------------------------------------------------------------------------------
double ingresarDouble(char *msj){
    char cad[20];
    char c;
    int i = 0;
    double valor = 0;
    printf("%s", msj);
    bool puntoDecimal = false;
    while((c = getch()) != 13){
        if (c >= '0' && c <= '9'){
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (c == '.' && !puntoDecimal) {
            puntoDecimal = true;
            printf("%c", c);
            cad[i++] = c;
        }
    }
    cad[i] = '\0';
    valor = atof(cad);
    return valor;
}

int sumarEnteros(int a, int b){

    return a+b;
}

float sumarFlotantes(float a, float b) {
    return a + b;
}

int main(){
    int imprimirNumeros = ingresar("ingrese un valor entero: ");
    cout << endl;
    cout << imprimirNumeros << endl;
    char imprimirLetras = ingresarLetra("ingrese letra: ");
    cout << endl;
    cout << imprimirLetras << endl;
    float imprimir = ingresarFloat("ingrese un valor flotante: ");
    cout << endl;
    cout << imprimir << endl;
    string imprimirString = ingresarString("ingrese un string: ");
    cout << endl;
    cout << imprimirString << endl;
    double imprimirDoubleValue = ingresarDouble("Ingrese un valor double: ");
    cout << endl << imprimirDoubleValue << endl;

    int entero1 = ingresar("Ingrese el primer entero: ");
    cout << endl;
    int entero2 = ingresar("Ingrese el segundo entero: ");
    cout << endl;
    int sumaEnteros = sumarEnteros(entero1, entero2);
    cout << "La suma de los enteros es: " << sumaEnteros << endl;

    float flotante1 = ingresarFloat("Ingrese el primer flotante: ");
    cout << endl;
    float flotante2 = ingresarFloat("Ingrese el segundo flotante: ");
    cout << endl;
    float sumaFlotantes = sumarFlotantes(flotante1, flotante2);
    cout << "La suma de los flotantes es: " << sumaFlotantes << endl;

}
