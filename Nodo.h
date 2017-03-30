//
// Created by Eimy on 30/03/2017.
//


#ifndef ED_PROGRAI_NODO_H
#define ED_PROGRAI_NODO_H


class nodo {

public:
    nodo(int v) {
        valor = v;
        siguiente = NULL;
    }


    nodo(int v, nodo * signodo) {
        valor = v;
        siguiente = signodo;
    }

private:
    int valor;
    nodo *siguiente;


    friend class lista;
};

typedef nodo * snodo;





#endif //ED_PROGRAI_NODO_H