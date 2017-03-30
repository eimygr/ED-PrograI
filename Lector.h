//
// Created by Eimy on 30/03/2017.
//
#ifndef PROGRAI_LECTOR_H
#define PROGRAI_LECTOR_H

#include "ListaDC.h"
#include <iostream>
using namespace std;


class Lector{


public:
    string Leer(string nomArchivo, int cont);
    void LeerProveedores(ListaDC listaProveedores);
    void LeerOriginal (string nomArchivo);
};
#endif //PROGRAI_LECTOR_H