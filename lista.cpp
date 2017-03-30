
#include "Nodo.h"
#include "lista.h"
#include <iostream>

using namespace std;


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