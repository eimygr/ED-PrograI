
#include "Nodo.h"
#include "lista.h"
#include <iostream>

using namespace std;


lista::~lista() {
    pnodo aux;

    while(primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    actual = NULL;
}


int lista::largoLista(){
    int cont=0;

    pnodo aux;
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
    { pnodo aux = primero;
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
            pnodo nuevo = new nodo(v);
            nuevo->siguiente= primero;
            primero= nuevo;
        }
        else{
            pnodo aux= primero;
            int i =2;
            while((i != pos )&&(aux->siguiente!= NULL)){
                i++;
                aux=aux->siguiente;
            }
            pnodo nuevo= new nodo(v);
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

            pnodo aux = primero;
            while (aux->siguiente->siguiente != NULL) {
                aux = aux->siguiente;

            }

            pnodo temp = aux->siguiente;
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

            pnodo aux = primero;
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
                pnodo aux=  primero;
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
    nodo *aux;

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

void lista ::convLista(int num) {
    while (v>0){
        Lista.InsertarInicio (v%10);
        v = v/10;
    }
}

int lista :: contarPares(){
    int cont = 0;
    pnodo aux;
    if (ListaVacia()){
        return cont;
    }
    else{
        while (aux!= NULL){
            if (aux -> valor %2 == 0){
                count ++;
                aux = aux -> siguiente;
            }
            else{
                aux = aux ->siguiente;
            }
        }
        return count;
    }
}

void lista:: sumaLista (int num1, int num2){
    Lista L1;
    Lista L2;
    int aux1;
    int aux2;

    while (num1>0){
        L1.InsertarInicio(num1%10);
        L2.InsertarInicio(num2%10);
        num1 = num1/10;
        num2 = num2/10;
    }

    if (L1.Largo()!= L2.Largo()){
        cout << "Los numeros deben ser del mismo largo";

    }
    else{
        aux1 = L1.Primero();
        aux2 = L2.Primero();
    }

    while (L3.Largo() != L1.Largo()){
        temp = aux1 -> valor + aux2 -> valor;
        L3.InsertarInicio(temp);
        temp = 0;
        aux1 = aux1 -> siguiente;
        aux2 = aux2 -> siguiente;
    }
    L3.Mostrar();

}