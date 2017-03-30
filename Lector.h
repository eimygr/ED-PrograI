//
// Created by Eimy on 25/03/2017.
//

#ifndef PROGRAI_LECTOR_H
#define PROGRAI_LECTOR_H

#include "ListaDC.h"
#include <iostream>
using namespace std;


class Lector{


public:
    int Leer(string nomArchivo, int cont);
    void LeerProvedores();
    void LeerOriginal (string nomArchivo);
};
#endif //PROGRAI_LECTOR_H
