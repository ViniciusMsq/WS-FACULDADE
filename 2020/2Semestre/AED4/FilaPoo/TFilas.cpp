#include <iostream>
#include "TFilas.h"

using namespace std;


void TFilas::Q_Init(TFila *&Fila){
    Fila = new TFila;
    Fila -> Comeco = NULL;
    Fila -> Final  = NULL;
}

bool TFilas::Q_IsEmpty(TFila *Fila){
    return Fila -> Comeco == NULL;
}

void TFilas::Enqueue(TFila *&Fila, TInfoFila elemento){
    TNoFila *novo;
    novo = new TNoFila;

    novo->dado = elemento;
    novo->prox= NULL;

    if(Q_IsEmpty(Fila)){
        Fila->Comeco = novo;
        Fila->Final = novo;
    }
    else{
        Fila->Final->prox=novo;

        Fila->Final = novo;
    }
}

TFilas::TInfoFila TFilas::Dequeue(TFila *Fila){
    
    TInfoFila aux;

    TNoFila *no_aux;

    if(!Q_IsEmpty(Fila)){
        aux = Fila->Comeco->dado;
        
        no_aux = Fila->Comeco;

        Fila->Comeco = Fila->Comeco->prox;

        delete(no_aux);
    }
    else{
        aux = 0;
    }
    return aux;
}

TFilas::TInfoFila TFilas::Q_Comeco(TFila *Fila){
    if(!Q_IsEmpty(Fila)){
        return Fila->Comeco->dado;
    }
    else return 0;
}

TFilas::TInfoFila TFilas::Q_Final(TFila *Fila){
    if(!Q_IsEmpty(Fila)){
        return Fila->Final->dado;
    }
    else return 0;
}

void TFilas::PrintFila(TFila *F){

    if(!Q_IsEmpty(F)){
        TNoFila *aux_no;

        cout<<"\n\nO Conteudo da Fila e:\n";
        aux_no = F->Comeco;

        while(aux_no != NULL){
            cout<<" "<<aux_no->dado;
            aux_no = aux_no->prox;
        }
    }
    else{
        cout<<"\n\nA Fila esta vazia !!!";
    }
    cout<<"\n\n";
}
