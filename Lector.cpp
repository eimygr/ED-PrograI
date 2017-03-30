//
// Created by Eimy on 23/03/2017.
//
#include "Lector.h"
#include <fstream>
#include <iostream>

using namespace std;

//void Lector:: LeerProveedor(string archivo, listaDC Lista){

///

//}

void Lector:: LeerProvedores() {

    int codigo;
    string nombre;
    int cont = 0;

    string nomArchivo = "Proveedores.txt";
    Leer(nomArchivo, 0 );
   // cout <<cont;

}



int Lector:: Leer(string nomArchivo, int cont) {
    cout<< nomArchivo;
    ifstream is(nomArchivo);

    char c;
    string linea;
    int contA;  //cuenta cuantos chars se avanzan en este ciclo


    /*while(is.get(c)){
        while (contA < cont) {
            contA = contA + 1;

        }
    }*/

    while (is.get(c)) {
        cout<< "while";

        if (c != ';'){
            cout << c;
            linea = linea + c;
            cont = cont + 1;
            cout << "linea:" + linea;
        }else{
            break;
        }

    }
    cout<<cont;

    is.close();
}

/*int Lector:: LeerOriginal(string nomArchivo){


    string cod_p;
    string nom_p;
    string dir_p;
    string tel_p;
    int cont = 1;

    ifstream is("Proveedores.txt");  // open file

    char c;
    string linea;
    while (is.get(c)){// loop getting single characters
        if (cont <= 4 ){

            if (c != ';'){
                linea = linea + c;
                //std::cout << l << endl;
            }else {
                switch (cont)
                {
                    case 1: cod_p = linea;
                        break;

                    case 2: nom_p = linea;
                        break;

                    case 3: dir_p = linea;
                        break;

                    case 4: tel_p = linea;
                        cout << tel_p;
                        break;
                }
                cont++;
                linea = "";
            }
        } else {

            //LLAMAR A LA FUNCION PARA CREAR EL PROVEEDOR//

            cout << cod_p;
            cout << nom_p;
            cout << dir_p;
            cout << tel_p;

            cod_p = "";
            nom_p = "";
            dir_p = "";
            tel_p = "";

            cont = 1;
        }

    }

    is.close();                // close file

    return 0;
}
*/