#include "TPilha.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

void TPilha::Init(TNoPilha*& Topo) {
    Topo = NULL;
}

bool TPilha::IsEmpty(TNoPilha* Topo) {
    return Topo == NULL;
}

void TPilha::Push(TNoPilha*& Topo, TInfoPilha elemento) {
    TNoPilha* novo;
    novo = new TNoPilha;

    novo->dado = elemento;
    novo->prox = Topo;

    Topo = novo;
}

TPilha::TInfoPilha TPilha::Pop(TNoPilha*& Topo) {

    if (!IsEmpty(Topo)) {

        TNoPilha* No_a_excluir;
        TInfoPilha valor;

        No_a_excluir = Topo;

        valor = Topo->dado;

        Topo = Topo->prox;

        delete(No_a_excluir);

        return valor;

    }
    else return 0;
}

TPilha::TInfoPilha TPilha::Top(TNoPilha* Topo) {

    if (!IsEmpty(Topo)) {
        return Topo->dado;
    }
    else return 0;

}

void TPilha::PrintPilha(TNoPilha* Topo) {

    TNoPilha* aux;

    if (!IsEmpty(Topo)) {
        aux = Topo;
        while (aux != NULL) {
            cout << aux->dado;
            aux = aux->prox;
        }
    }
    else { 
        printf("\nPilha Vazia !\n\n");
    }
}
