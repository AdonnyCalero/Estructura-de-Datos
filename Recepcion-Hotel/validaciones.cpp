#include "Validaciones.h"  
#include <iostream>
#include <regex>

using namespace std;

string Validaciones::ingresarString(const string &msj)
{
    string input;
    cout << msj;
    getline(cin, input);
    return input;
}

string Validaciones::ingresarCedula(const string &msj)
{
    string cedula;
    cout << msj;
    cin >> cedula;
    return cedula;
}

string Validaciones::ingresarCorreo(const string &msj)
{
    string correo;
    cout << msj;
    cin >> correo;
    return correo;
}

bool Validaciones::validarCedula(const string &cedula)
{
    if (cedula.length() != 10)
    {
        return false;
    }

    int suma = 0;
    for (int i = 0; i < 9; i++)
    {
        int digito = cedula[i] - '0';
        if (i % 2 == 0)
        {
            digito *= 2;
            if (digito > 9)
            {
                digito -= 9;
            }
        }
        suma += digito;
    }

    int ultimoDigito = cedula[9] - '0';
    int digitoVerificador = (10 - (suma % 10)) % 10;

    return ultimoDigito == digitoVerificador;
}

bool Validaciones::validarCorreo(const string &correo)
{
    const regex pattern(R"((\w+)(\.{1}\w+)*@(\w+)(\.{1}\w+)+)");
    return regex_match(correo, pattern);
}
