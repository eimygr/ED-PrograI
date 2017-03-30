//
// Created by Eimy on 30/03/2017.
//

#ifndef PROGRAI_NODODC_H
#define PROGRAI_NODODC_H

#include <iostream>
using namespace std;

class NodoDC {

public:
    NodoDC(int v){
        valor = v;
        siguiente = NULL;
        anterior =NULL;
    }

    NodoDC(int v, NodoDC * signodo){
        valor = v;
        siguiente = signodo;
    }

    NodoDC(string s){
        valorS = s;
        siguiente = NULL;
        anterior =NULL;
    }

    NodoDC(string s, NodoDC *signodo){
        valorS = s;
        siguiente = signodo;
    }

private:
    int valor;
    string valorS;
    NodoDC *siguiente;
    NodoDC *anterior;


    friend class ListaDC;
};


typedef NodoDC *pnodo;




#endif //PROGRAI_NODODC_H
