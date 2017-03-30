//
// Created by Eimy on 25/03/2017.
//

#ifndef PROGRAI_MENU_H
#define PROGRAI_MENU_H
#include "lista.h"
#include "ListaDC.h"
#include <iostream>

using namespace std;

class Menu {
    int proveedor;
    int idCliente;



public:
    void start(ListaDC pListaProveedores , ListaDC pListaClientes , lista pListaCategorias , lista pListaProductos);
    bool pedirProveedor(ListaDC pListaProveedores);
    bool verificarCliente(ListaDC pListaClientes);
    bool verificarCategoria (lista pListaCategorias);
    void crearCliente (ListaDC listaClientes);


};








#endif //PROGRAI_MENU_H
