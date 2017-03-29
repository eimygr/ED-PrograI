//
// Created by Eimy on 23/03/2017.
//

#include <iostream>
#include "Lector.h"
using namespace std;

//void Lector:: LeerProveedor(string archivo, listaDC Lista){

///

//}


int Lector:: Leer(){


    // ESTE ES UN EJEMPLO COPIADO JAJA

    string cod_p;
    string nom_p;
    string dir_p;
    string tel_p;
    int cont = 1;

    ifstream is("Proveedores.txt");  // open file

    char c;
    string l;
    while (is.get(c)){// loop getting single characters
        if (cont <= 4 ){

            if (c != ';'){
                l = l + c;
                //std::cout << l << endl;
            }else {
                switch (cont)
                {
                    case 1: cod_p = l;
                        break;

                    case 2: nom_p = l;
                        break;

                    case 3: dir_p = l;
                        break;

                    case 4: tel_p = l;
                        cout << tel_p << endl;
                        break;
                }
                cont++;
                l = "";
            }
        } else {

            //LLAMAR A LA FUNCION PARA CREAR EL PROVEEDOR//

            std::cout << cod_p << endl;
            cout << nom_p << endl;
            cout << dir_p << endl;
            cout << tel_p << endl;

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
}