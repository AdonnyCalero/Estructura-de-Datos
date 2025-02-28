#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Huesped.h"
#include "Lista.h"
#include <functional>
#include <cmath>

template <typename T, typename Comparator>
int partition(std::vector<T>& lista, int low, int high, Comparator comp) {
    T pivot = lista[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (comp(lista[j], pivot)) {
            i++;
            std::swap(lista[i], lista[j]);
        }
    }
    std::swap(lista[i + 1], lista[high]);
    return i + 1;
}

template <typename T, typename Comparator>
void quickSort(std::vector<T>& lista, int low, int high, Comparator comp) {
    if (low < high) {
        int pi = partition(lista, low, high, comp);
        quickSort(lista, low, pi - 1, comp);
        quickSort(lista, pi + 1, high, comp);
    }
}

template <typename T, typename Comparator>
void ordenarLista(ListaCircularDoble<T>& lista, Comparator comp) {
    std::vector<T> elementos;
    
    Nodo<T>* aux = lista.getPrimero();
    do {   
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    } while (aux != lista.getPrimero());

    quickSort(elementos, 0, elementos.size() - 1, comp);

    aux = lista.getPrimero();
    int index = 0;
    do {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    } while (aux != lista.getPrimero());

    lista.mostrar(lista.getPrimero());
};
