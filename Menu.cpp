//
// Created by Eimy on 25/03/2017.
//

#include "Menu.h"
#include <iostream>
#include "ListaDC.cpp"

using namespace std;


bool Menu:: pedirProveedor(pListaProveedores){

    int pProveedor;

    cout << "Digite el codigo del proveedor: \n";
    cin >> pProveedor;

    return  (pListaProveedores.existe(pProveedor));

}


bool Menu::verificarCliente(pListaClientes){

    int pIdCliente;

    cout << "Digite el ID del cliente: \n";
    cin >> pIdCliente;

    return (pListaClientes.existe(pIdCliente));

}


bool Menu::verificarCategoria(pListaCategorias){

    int pCategoria;

    cout << "Digite la categoría del producto: \n";
    cin >> pCategoria;

    return (pListaCategorias.existe(pCategoria));

}


void Menu::crearCliente(){

    int pCedula;
    string pNombre;
    string pDireccion;
    int pTelefono;


    cout << "Digite la cédula del cliente : \n";
    cin >> pCedula;

    cout << "Digite el nombre del cliente : \n";
    cin >> pNombre;

    cout << "Digite la dirección del cliente : \n";
    cin >> pDireccion;

    cout << "Digite el teléfono del cliente : \n";
    cin >> pTelefono;


    listaClientes.InsertarFinal(pCedula);
    listaClientes.InsertarFinal(pNombre);
    listaClientes.InsertarFinal(pDireccion);
    listaClientes.InsertarFinal(pTelefono);

}


void Menu::start(pListaProveedores , pListaClientes , pListaCategorias , pListaProductos) {

    int descuento = 0;
    int pCantidad = 1;
    string pProducto;

    cout << "Menu de Ventas\n";
    
    if (pedirProveedor(pListaProveedores)) {

        if (verificarCliente(pListaClientes)) {

            descuento = 5;

        } else {

            cout << "Cliente no existe\nAñadiendo nuevo cliente a la base de datos...\n";

            crearCliente();

        }

        if (verificarCategoria(pListaCategorias)) {

            cout << "Digite el código del producto que desea adquirir : \n";
            cin >> pProducto;

            cout << "Digite la cantidad de producto que desea adquirir : \n";
            cin >> pCantidad;

            pListaProductos.reducirStock(pProducto , pCantidad);

        } else {

            cout << "La categoría no existe\n";

        }


    } else {
        cout << "El proveedor no existe\n";

    }

}