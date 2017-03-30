#include <iostream>
#include "Menu.cpp"
#include "Lector.h"
#include "Lector.cpp"


using namespace std;



int main(){

    Menu menu;
    ListaDC listaClientes;
    ListaDC listaProveedores;
    lista listaCategorias;
    lista listaProductos;
    Lector lector;
    lector.LeerProvedores();
    menu.start(listaProveedores, listaClientes, listaCategorias, listaProductos);



    return 0;
}


