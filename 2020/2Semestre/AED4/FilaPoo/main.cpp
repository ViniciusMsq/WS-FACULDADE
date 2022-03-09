#include <iostream>
#include <stdio.h>
#include "TFilas.h"

using namespace std;

int main(int argc, char const *argv[])
{
    TFilas::TInfoFila aux;
    TFilas::TFila *F;
    TFilas fila;
    int valor = 0;
    int x = 0;
    fila.Q_Init(F);

    while(x <5){
        system("CLS");
        cout<<"Informe um valor: ";
        cin>>valor;
        fila.Enqueue(F, valor);
        x++;
    }

    fila.PrintFila(F);

    cout<<"\n\n";
    return 0;
}

