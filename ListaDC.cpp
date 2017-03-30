//
// Created by Eimy on 30/03/2017.
//

#include <iostream>
#include "ListaDC.h"
#include "NodoDC.h"
#include "NodoDC.cpp"

using namespace std;



ListaDC::~ListaDC() {
    pnodo aux;

    while(primero) {
        aux = primero;
        primero = primero->siguiente;
        primero->anterior=aux->anterior;
        aux->anterior->siguiente=primero;
        delete aux;
    }
    actual = NULL;
}

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



/void ListaDC::InsertarFinal(int v)
{
    if (ListaVacia()) {
        cout<< "Lista VAcia";
        primero = new NodoDC(v);
        primero->anterior=primero;
        primero->siguiente=primero;

    } else {
        cout<< "No";
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
    while(aux->siguiente!=primero)
    {

        cout << aux->valor << "-> ";
        aux = aux->siguiente;
    }
    cout<<aux->valor<<"->";
    cout<<endl;
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

