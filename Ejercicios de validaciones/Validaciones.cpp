/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programar una suma fracciones       *
 * Autor:                          Adonny Calero                       *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <algorithm>

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

int contarDigitos(int numero) {
    int contador = 0;

    if (numero == 0) {
        return 1;
    }

    numero = abs(numero);

    while (numero > 0) {
        numero /= 10;
        contador++;
    }

    return contador;
}

int contarVocales(string texto) {
    int contador = 0;

    for (char c : texto) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }

    return contador;
}

string esPalindromo(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);

    texto.erase(remove_if(texto.begin(), texto.end(), [](char c) { return !isalnum(c); }), texto.end());

    int longitud = texto.size();
    for (int i = 0; i < longitud / 2; i++) {
        if (texto[i] != texto[longitud - 1 - i]) {
            return "La cadena no es un pal�ndromo.";
        }
    }
    return "La cadena es un pal�ndromo.";
}

string invertirCadena(string texto) {
    string invertido = "";
    for (int i = texto.length() - 1; i >= 0; i--) {
        invertido += texto[i];
    }
    return invertido;
}

char convertirAMayusculaManual(char letra) {
    if (letra >= 'a' && letra <= 'z') {
        letra = letra - 32;
    }
    return letra;
}

string verificarVocalOConsonante(char letra) {
    letra = tolower(letra);

    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
        return "Es una vocal.";
    } else if (isalpha(letra)) {
        return "Es una consonante.";
    } else {
        return "No es una letra v�lida.";
    }
}

string concatenarStrings(string str1, string str2) {
    return str1 + str2;
}

float restarFlotantes(float num1, float num2) {
    return num1 - num2;
}

int main(){

    //Suma de Enteros
    cout << "Suma de enteros" << endl;
    int entero1 = ingresar("Ingrese el primer entero: ");
    cout << endl;
    int entero2 = ingresar("Ingrese el segundo entero: ");
    cout << endl;
    int sumaEnteros = sumarEnteros(entero1, entero2);
    cout << "La suma de los enteros es: " << sumaEnteros << endl;

    //Suma de flotantes
    cout << "Suma de flotantes" << endl;
    float flotante1 = ingresarFloat("Ingrese el primer flotante: ");
    cout << endl;
    float flotante2 = ingresarFloat("Ingrese el segundo flotante: ");
    cout << endl;
    float sumaFlotantes = sumarFlotantes(flotante1, flotante2);
    cout << "La suma de los flotantes es: " << sumaFlotantes << endl;

    //Contador de digitos
    cout << "Contar Digitos" << endl;
    int numero = ingresar("Ingrese el numero: ");
    cout << endl;
    int cantidadDigitos = contarDigitos(numero);
    cout << "El numero tiene " << cantidadDigitos << " digitos." << endl;

    //Contar Vocales
    cout << "Contar Vocales" << endl;
    string texto = ingresarString("ingrese un string: ");
    cout << endl;
    int cantidadVocales = contarVocales(texto);
    cout << "La cantidad de vocales en la cadena es: " << cantidadVocales << endl;

    //Es Palindromo
    cout << "Es Palindromo" << endl;
    string palindromo = ingresarString("ingrese un string: ");
    cout << endl;
    cout << esPalindromo(palindromo) << endl;

    //Invertir Cadena
    cout << "Invertir Cadena" << endl;
    string textoDerecho = ingresarString("Ingrese un string: ");
    cout << endl;
    string textoInvertido = invertirCadena(textoDerecho);
    cout << "La cadena invertida es: " << textoInvertido << endl;

    // Convertir a mayuscula manualmente
    cout << "Convertir a Mayuscula" << endl;
    char letra = ingresarLetra("Ingrese una letra: ");
    cout << endl;
    char letraMayuscula = convertirAMayusculaManual(letra);
    cout << "La letra en may�scula es: " << letraMayuscula << endl;

    //Verificar si es Vocal o Consonante
    char letra1 = ingresarLetra("Ingrese una letra: ");
    cout << endl;
    cout << verificarVocalOConsonante(letra1) << endl;

    //Concatenar Strings
    string str1 = ingresarString("Ingrese la primera cadena: ");
    cout << endl;
    string str2 = ingresarString("Ingrese la segunda cadena: ");
    cout << endl;
    string concatenado = concatenarStrings(str1, str2);
    cout << "La cadena concatenada es: " << concatenado << endl;

    //Resta de Flotantes
    cout << "Resta de flotantes" << endl;
    float flotante3 = ingresarFloat("Ingrese el primer flotante: ");
    cout << endl;
    float flotante4 = ingresarFloat("Ingrese el segundo flotante: ");
    cout << endl;
    float restaFlotantes = restarFlotantes(flotante3, flotante4);
    cout << "La resta de los flotantes es: " << restaFlotantes << endl;


    return 0;
}
