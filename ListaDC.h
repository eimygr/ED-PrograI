//
// Created by Eimy on 30/03/2017.
//


#ifndef PROGRAI_LISTADC_H
#define PROGRAI_LISTADC_H


#include <iostream>
#include "NodoDC.h"

using namespace std;

class ListaDC {
public:
    ListaDC() { primero = actual = NULL; }
    ~ListaDC();

    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarFinal (string s);
    void InsertarPos (int v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    bool existe(int codigo);

private:
    pnodo primero;
    pnodo actual;
};


#endif //PROGRAI_LISTADC_H