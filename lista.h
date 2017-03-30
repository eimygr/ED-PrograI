//
// Created by Eimy on 30/03/2017.
//


#ifndef ED_PROGRAI_LISTA_H
#define ED_PROGRAI_LISTA_H

#include "Nodo.h"

class lista {


private:
    snodo primero;
    snodo actual;

public:
    lista() {
        primero = actual = NULL; }

    ~lista();

    void InsertarInicio(int v);
    void InsertarFinal(int v);
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
    void sumarLista(int num1, int num2);
    void convLista(int num);
    bool existe(int codigo);
    void reducirStock (int pProducto , int pCantidad);





};

#endif //ED_PROGRAI_LISTA_H