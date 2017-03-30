//
// Created by Eimy on 30/03/2017.
//

#include <iostream>
#include "Menu.h"
#include "Lector.h"
#include "lista.cpp"
#include "Lector.h"

#include "ListaDC.cpp"
#include "ListaDC.h"

using namespace std;



int main(){

    Menu menu;
    ListaDC listaClientes;
    ListaDC listaProveedores;
    lista listaCategorias;
    lista listaProductos;
    Lector lector;



    //listaProveedores.InsertarFinal(5);
    //listaProveedores.InsertarFinal(8);

    //listaProveedores.Mostrar();
    //listaProveedores.InsertarFinal();
    //listaProveedores.Mostrar();

    //lector.LeerProveedores(listaProveedores);
    menu.start(listaProveedores, listaClientes, listaCategorias, listaProductos);
    //listaProveedores.existe(1889);



    return 0;
}
