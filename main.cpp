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

private:
    int valor;
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

    ~lista();

    void InsertarInicio(int v);
    void InsertarFinal(int v);
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
    void sumarLista(int num1, int num2);
    void convLista(int num);
    bool existe(int codigo);
    void reducirStock (int pProducto , int pCantidad);



};

lista::~lista() {
    snodo aux;

    while(primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    actual = NULL;
}


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



bool lista ::existe(int codigo) {
    snodo aux = primero;

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

/*void ListaDC::InsertarFinal(string s){

    if (ListaVacia()) {
        primero = new NodoDC(s);
        primero->anterior=primero;
        primero->siguiente=primero;

    }else{
        pnodo nuevo = new NodoDC(s);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente=primero->anterior->siguiente;
        primero->anterior->siguiente=nuevo;
        primero->anterior=nuevo;
    }
}
*/


void ListaDC::InsertarPos(int v,int pos)
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
                InsertarFinal(v);
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
}

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


bool ListaDC ::existe(int codigo) {
    pnodo aux = primero;

    while (aux->siguiente != primero){

        if (aux -> valor == codigo){
            return true;

        }else{
            aux = aux -> siguiente;
        }

    }

    if (aux->valor == codigo){
        return true;
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
    string Leer(string nomArchivo, int cont);
    ListaDC LeerProveedores();
    void LeerOriginal (string nomArchivo);
};


ListaDC Lector:: LeerProveedores() {

    ListaDC lista;
    int codigo;
    string nombre;
    string leido;
    int cont = 0;
    string nomArchivo;

    nomArchivo = "Proveedores.txt";
    leido = Leer(nomArchivo, 0 );
    codigo = convInt(leido);
    lista.InsertarFinal(codigo);
    //lista.Mostrar();

    return lista;

}



string Lector:: Leer(string nomArchivo, int cont) {
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
    cout<< "termina";
    return linea;

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

    string input;
    int pProveedor;

    cout << "Digite el codigo del proveedor: \n";

    cin >> input;

    pProveedor = convInt(input);

    cout << pProveedor + 5;
    return  (pListaProveedores.existe(pProveedor));
    //return false;
}


bool Menu::verificarCliente(ListaDC pListaClientes){

    int pIdCliente;

    cout << "Digite el ID del cliente: \n";
    cin >> pIdCliente;

    return (pListaClientes.existe(pIdCliente));

}


bool Menu::verificarCategoria(lista pListaCategorias){

    int pCategoria;

    cout << "Digite la categoría del producto: \n";
    cin >> pCategoria;

    return (pListaCategorias.existe(pCategoria));

}


void Menu::crearCliente(ListaDC listaClientes){

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
//    listaClientes.InsertarFinal(pNombre);
 //   listaClientes.InsertarFinal(pDireccion);
 //   listaClientes.InsertarFinal(pTelefono);

}


void Menu::start(ListaDC pListaProveedores , ListaDC pListaClientes , lista pListaCategorias , lista pListaProductos) {

    int descuento = 0;
    int pCantidad = 1;
    int pProducto;

    cout<< "Bienvenido!\n";
    cout<< "  \n";
    cout << "Menu de Ventas\n";

    if (pedirProveedor(pListaProveedores)) {

        if (verificarCliente(pListaClientes)) {

            descuento = 5;

        } else {

            cout << "Cliente no existe\nAñadiendo nuevo cliente a la base de datos...\n";

            crearCliente(pListaClientes);

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
        start(pListaProveedores , pListaClientes , pListaCategorias , pListaProductos);

    }

}





int main (){
    Menu menu;
    ListaDC listaClientes;
    ListaDC listaProveedores;
    lista listaCategorias;
    lista listaProductos;
    Lector lector;


    //listaProveedores.Mostrar();
    //listaProveedores.InsertarFinal();
    //listaProveedores.Mostrar();

    listaProveedores = lector.LeerProveedores();
    listaProveedores.Mostrar();
    menu.start(listaProveedores, listaClientes, listaCategorias, listaProductos);

    //listaProveedores.existe(1889);

    return 0;
}

