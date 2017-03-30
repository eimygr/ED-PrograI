//Proyecto Programado I

// /Autor: Eimy Gonzalez


#include <iostream>
#include <fstream>
#include <sstream>



using  namespace std;

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

    nodo(string s) {
        valorS = s;
        siguiente = NULL;
    }

    nodo(string s, nodo * signodo) {
        valorS = s;
        siguiente = signodo;
    }


private:
    int valor;
    string valorS;
    nodo *siguiente;


    friend class lista;
};

typedef nodo * snodo;




class lista {


private:
    snodo primero;
    snodo actual;

public:
    lista() {
        primero = actual = NULL; }

    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarFinal(string s);
    void InsertarPos (int v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void MostrarS();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void convLista(int num);
    bool existe(string s);
    void reducirStock (int pProducto , int pCantidad);



};


int lista::largoLista(){
    int cont=0;

    snodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
            aux=aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void lista::InsertarInicio(int v)
{
    if (ListaVacia())
        primero = new nodo(v);
    else
        primero=new nodo (v,primero);
}

void lista::InsertarFinal(int v)
{
    if (ListaVacia())
        primero = new nodo(v);
    else
    { snodo aux = primero;
        while ( aux->siguiente != NULL)
            aux= aux->siguiente;
        aux->siguiente=new nodo(v);
    }
}

void lista::InsertarFinal(string s)
{
    if (ListaVacia())
        primero = new nodo(s);
    else
    { snodo aux = primero;
        while ( aux->siguiente != NULL)
            aux= aux->siguiente;
        aux->siguiente=new nodo(s);
    }
}


void lista::InsertarPos(int v,int pos)
{
    if (ListaVacia())
        primero = new nodo(v);
    else{
        if(pos <=1){
            snodo nuevo = new nodo(v);
            nuevo->siguiente= primero;
            primero= nuevo;
        }
        else{
            snodo aux= primero;
            int i =2;
            while((i != pos )&&(aux->siguiente!= NULL)){
                i++;
                aux=aux->siguiente;
            }
            snodo nuevo= new nodo(v);
            nuevo->siguiente=aux->siguiente;
            aux->siguiente=nuevo;

        }
    }
}

void lista::BorrarFinal()
{
    if (ListaVacia()){
        cout << "No hay elementos en la lista:" << endl;

    }else{
        if (primero->siguiente == NULL) {
            primero= NULL;
        } else {

            snodo aux = primero;
            while (aux->siguiente->siguiente != NULL) {
                aux = aux->siguiente;

            }

            snodo temp = aux->siguiente;
            aux->siguiente= NULL;


            delete temp;
        }
    }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
        cout << "No hay elementos en la lista:" << endl;

    }else{
        if (primero->siguiente == NULL) {
            primero= NULL;
        } else {

            snodo aux = primero;
            primero=primero->siguiente;
            delete aux;
        }
    }
}



void lista:: borrarPosicion(int pos){
    if(ListaVacia()){
        cout << "Lista vacia" <<endl;
    }else{
        if((pos>largoLista())||(pos<0)){
            cout << "Error en posicion" << endl;
        }else{
            if(pos==1){
                primero=primero->siguiente;
            }else{
                int cont=2;
                snodo aux=  primero;
                while(cont<pos){
                    aux=aux->siguiente;
                    cont++;
                }
                aux->siguiente=aux->siguiente->siguiente;
            }
        }
    }

}


void lista::Mostrar()
{
    snodo aux;

    aux = primero;
    while(aux) {
        cout << aux->valor << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}



void lista::MostrarS()
{
    snodo aux;

    aux = primero;
    while(aux) {
        cout << aux->valorS << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}


void lista::Siguiente()
{
    if(actual) actual = actual->siguiente;
}

void lista::Primero()
{
    actual = primero;
}

void lista::Ultimo()
{
    actual = primero;
    if(!ListaVacia())
        while(actual->siguiente) Siguiente();
}

void lista ::convLista(int v) {
    while (v>0){
        InsertarInicio (v%10);
        v = v/10;
    }
}



bool lista ::existe(string s) {
    snodo aux = primero;

    while (aux) {

        if (aux->valorS == s) {
            return true;

        } else {
            aux = aux->siguiente;
        }

    }


    return false;
}


void lista::reducirStock(int pProducto, int pCantidad) {
    cout<< "No";
    //FALTA

}




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




class ListaDC {
public:
    ListaDC() { primero = actual = NULL; }

    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarFinal (string s);
    void InsertarPos (int v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    bool existe(int codigo);
    bool existe(string s);
    void MostrarS();

private:
    pnodo primero;
    pnodo actual;
};


int ListaDC::largoLista(){
    int cont=0;

    pnodo aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=primero){
            aux=aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void ListaDC::InsertarInicio(int v)
{

    if (ListaVacia())
    {
        primero = new NodoDC(v);
        primero->anterior=primero;
        primero->siguiente=primero;
    }
    else
    {
        pnodo nuevo= new NodoDC (v);
        nuevo->siguiente=primero;
        nuevo->anterior= primero->anterior;
        primero->anterior->siguiente=nuevo;
        nuevo->siguiente->anterior=nuevo;
        primero= nuevo;
    }
}



void ListaDC::InsertarFinal(int v)
{
    if (ListaVacia()) {
        primero = new NodoDC(v);
        primero->anterior=primero;
        primero->siguiente=primero;

    } else {
        pnodo nuevo = new NodoDC(v);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente=primero->anterior->siguiente;
        primero->anterior->siguiente=nuevo;
        primero->anterior=nuevo;
    }
}

void ListaDC::InsertarFinal(string s){

    if (ListaVacia()) {
        primero = new NodoDC(s);
        primero->anterior=primero;
        primero->siguiente=primero;

    }else{
        pnodo nuevo = new NodoDC(s);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente=primero->anterior->siguiente;
        primero->anterior->siguiente = nuevo;
        primero->anterior=nuevo;
    }
}



/*void ListaDC::InsertarPos(int v,int pos)
{
    if (ListaVacia())
    {
        primero = new NodoDC(v);
        primero->anterior=primero;
        primero->siguiente=primero;
    }
    else
    {
        if(pos <=1)
            InsertarInicio(v);
        else
        {
            if (pos==largoLista())
                //InsertarFinal(v);
            else
            {
                pnodo aux= primero;
                int i =2;
                while((i != pos )&&(aux->siguiente!= primero))
                {
                    i++;
                    aux=aux->siguiente;
                }
                pnodo nuevo= new NodoDC(v);
                nuevo->siguiente=aux->siguiente;
                aux->siguiente=nuevo;
                aux->siguiente->anterior=aux;
                nuevo->siguiente->anterior=nuevo;
            }
        }
    }
}*/

void ListaDC::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp= primero;
            primero= NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodo temp = aux->siguiente;
            aux->siguiente= primero;
            delete temp;
        }
    }
}

void ListaDC::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp= primero;
            primero= NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero;
            pnodo temp= primero;
            while (aux->siguiente!=primero)
                aux= aux->siguiente;
            aux->siguiente=primero->siguiente;
            primero=primero->siguiente;
            primero->anterior=aux;
            delete temp;
        }
    }
}

void ListaDC:: borrarPosicion(int pos)
{
    if(ListaVacia())
        cout << "Lista vacia" <<endl;
    else
    {
        if((pos>largoLista())||(pos<0))
            cout << "Error en posicion" << endl;
        else
        {
            if(pos==1)
                BorrarInicio();
            else
            {
                int cont=2;
                pnodo aux=  primero;
                while(cont<pos)
                {
                    aux=aux->siguiente;
                    cont++;
                }
                pnodo temp = aux->siguiente;
                aux->siguiente=aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void ListaDC::Mostrar() {
    pnodo aux=primero;

    if (ListaVacia()){
        cout<< "No se puede mostrar, la lista esta vacia";

    }else {
        while (aux->siguiente != primero) {

            cout << aux->valor << "-> ";
            aux = aux->siguiente;
        }

        cout << aux->valor << "->";
        cout << endl;
    }
}

void ListaDC::MostrarS() {
    pnodo aux= primero;

    if (ListaVacia()){
        cout<< "No se puede mostrar, la lista esta vacia";

    }else {
        while (aux->siguiente != primero) {

            cout << aux->valorS << "-> ";
            aux = aux->siguiente;
        }

        cout << aux->valorS << "->";
        cout << endl;
    }
}

bool ListaDC ::existe(int codigo) {
    pnodo aux = primero;

    if (ListaVacia()){
        cout<< "Lista Vacia";

    }else {
        while (aux->siguiente != primero) {

            if (aux->valor == codigo) {
                return true;

            } else {
                aux = aux->siguiente;
            }

        }

        if (aux->valor == codigo) {
            return true;
        }
    }
    return false;

}


bool ListaDC :: existe(string s) {
    pnodo aux = primero;

    if (ListaVacia()){
        cout<< "*";

    }else {

        while (aux->siguiente != primero){

            if (aux->valorS == s){
                return true;

            }else{
                aux = aux->siguiente;
            }

        }

        if (aux->valorS == s){
            return true;
        }
    }
    return false;

}



int convInt(string s){
    int x;
    stringstream convert(s);
    convert >> x;
    //cout << x<<endl;
    return x;

}

class Lector{


public:
    ListaDC Leer1(string nomArchivo);
    lista Leer2(string nomArchivo);
    lista Leer3(string nomArchivo);

};




ListaDC Lector:: Leer1(string nomArchivo) {

    char c;
    string linea;
    ListaDC lista;
    int cont = 0;
    int contAvanza = 0;

    ifstream is(nomArchivo);


    while (is.get(c)) {

        if (c == ';' or c== 10){
            cont = cont +1;
        }

        if (contAvanza>0){
            if (c == ';' or c == 10){

                contAvanza = contAvanza -1;
            }
            continue;

        }else{
            if (c != ';' and c!= 10) {

                linea = linea + c;

            }else{

                if (lista.existe(linea) and isdigit(linea[0])){
                    linea = "";
                    contAvanza = 3;

                }else{

                    lista.InsertarFinal(linea);

                    linea = "";

                }
            }
        }

    }

    lista.InsertarFinal(linea);
    is.close();
    return lista;

}

lista Lector:: Leer2(string nomArchivo) {

    char c;
    string linea = "";
    lista Lista;
    int cont = 0;
    int contAvanza = 0;

    ifstream is(nomArchivo);


    while (is.get(c)) {

        if (c == ';' or c== 10){
            cont = cont +1;
        }

        if (contAvanza>0){
            if (c == ';' or c == 10){

                contAvanza = contAvanza -1;
            }
            continue;

        }else{
            if (c != ';' and c!= 10) {

                linea = linea + c;

            }else{

                if (Lista.existe(linea) and isdigit(linea[0])){
                    linea = "";
                    contAvanza = 1;

                }else{

                    Lista.InsertarFinal(linea);

                    linea = "";

                }
            }
        }

    }

    Lista.InsertarFinal(linea);
    is.close();
    return Lista;

}

lista Lector:: Leer3(string nomArchivo) {

    char c;
    string linea = "";
    lista Lista;
    int cont = 0;
    int contAvanza = 0;

    ifstream is(nomArchivo);


    while (is.get(c)) {

        if (c == ';' or c== 10){
            cont = cont +1;
        }

        if (contAvanza>0){
            if (c == ';' or c == 10){

                contAvanza = contAvanza -1;
            }
            continue;

        }else{
            if (c != ';' and c!= 10) {

                linea = linea + c;

            }else{

                if (Lista.existe(linea) and isdigit(linea[0]) and cont%5 == 0){
                    linea = "";
                    contAvanza = 1;

                }else{

                    Lista.InsertarFinal(linea);

                    linea = "";

                }
            }
        }

    }

    Lista.InsertarFinal(linea);
    is.close();
    return Lista;

}

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





bool Menu::pedirProveedor(ListaDC pListaProveedores){


    string pProveedor;

    cout << "Digite el codigo del proveedor: \n";

    cin >> pProveedor;

    return  (pListaProveedores.existe(pProveedor));
    //return false;
}


bool Menu::verificarCliente(ListaDC pListaClientes){

    string pIdCliente;

    cout << "Digite el ID del cliente: \n";
    cin >> pIdCliente;

    return (pListaClientes.existe(pIdCliente));

}


bool Menu::verificarCategoria(lista pListaCategorias){

    string pCategoria;

    cout << "Digite la categoria del producto: \n";
    cin >> pCategoria;

    return (pListaCategorias.existe(pCategoria));

}


void Menu::crearCliente(ListaDC listaClientes){

    string pCedula;
    string pNombre;
    string pDireccion;
    string pTelefono;


    cout << "Digite la cedula del cliente : \n";
    cin >> pCedula;

    cout << "Digite el nombre del cliente : \n";
    cin >> pNombre;

    cout << "Digite la direccion del cliente : \n";
    cin >> pDireccion;

    cout << "Digite el telefono del cliente : \n";
    cin >> pTelefono;


    listaClientes.InsertarFinal(pCedula);
    listaClientes.InsertarFinal(pNombre);
    listaClientes.InsertarFinal(pDireccion);
    listaClientes.InsertarFinal(pTelefono);

}


void Menu::start(ListaDC pListaProveedores , ListaDC pListaClientes , lista pListaCategorias , lista pListaProductos) {

    int descuento = 0;
    int pCantidad = 1;
    int pProducto;
    int opcion;

    cout<< "Bienvenido!\n";
    cout<< "  \n";
    cout << "Menu de Ventas\n";

    cout<< "1. Ventas\n";
    cout<< "2. Salir\n";

    while (true) {
        cout<< "Digite la opcion que desea:";
        cin>>opcion;

        if (opcion == 1) {
            if (pedirProveedor(pListaProveedores)) {

                if (verificarCliente(pListaClientes)) {

                    descuento = 5;

                } else {

                    cout << "Cliente no existe\nAñadiendo nuevo cliente a la base de datos...\n";

                    crearCliente(pListaClientes);

                }

                if (verificarCategoria(pListaCategorias)) {

                    cout << "Digite el codigo del producto que desea adquirir : \n";
                    cin >> pProducto;

                    cout << "Digite la cantidad de producto que desea adquirir : \n";
                    cin >> pCantidad;

                    pListaProductos.reducirStock(pProducto, pCantidad);

                } else {

                    cout << "La categoria no existe\n";

                }

            } else {
                cout << "El proveedor no existe\n";
                start(pListaProveedores, pListaClientes, pListaCategorias, pListaProductos);

            }
        }
        if (opcion == 2){
            cout<< "Gracias!";
            break;

        }else{
            cout<< "Opcion Invalida. Vuelva a intentar.";
        }
    }
}





int main (){
    Menu menu;
    ListaDC listaClientes;
    ListaDC listaProveedores;
    lista listaCategorias;
    lista listaProductos;
    Lector lector;
    lista Lista;
    Lista.InsertarFinal("hola");
    Lista.InsertarFinal("a");





    listaProveedores = lector.Leer1("Proveedores.txt");
    listaClientes = lector.Leer1("Clientes.txt");
    listaCategorias = lector.Leer2 ("Categorias.txt");
    listaProductos = lector.Leer3("Productos.txt");
    listaProveedores.MostrarS();
    listaClientes.MostrarS();
    listaCategorias.MostrarS();
    listaProductos.MostrarS();
    menu.start(listaProveedores, listaClientes, listaCategorias, listaProductos);

    //Lista.existe("hola");
    //listaProveedores.existe(1889);

    return 0;
}

