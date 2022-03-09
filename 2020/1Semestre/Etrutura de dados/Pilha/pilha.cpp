#include <stdio.h>
#include <iostream>
using namespace std;

typedef int TInfoPilha;

struct TNoPilha
{
    TInfoPilha dado;
    TNoPilha *prox;    
};

void Init(TNoPilha *&Topo){
    Topo = NULL;
}

bool IsEmpty(TNoPilha *Topo){
    return Topo == NULL;
}

void Push(TNoPilha *&Topo, TInfoPilha elemento){
    TNoPilha *novo;
    novo = new TNoPilha;

    novo->dado = elemento;
    novo->prox = Topo;

    Topo = novo;
}

TInfoPilha Pop(TNoPilha *&Topo){

    if(!IsEmpty(Topo)){

        TNoPilha *No_a_excluir;
        TInfoPilha valor;

        No_a_excluir = Topo;

        valor = Topo->dado;
        
        Topo = Topo->prox;

        delete(No_a_excluir);

        return valor;

    }
    else return 0;
}

TInfoPilha Top(TNoPilha *Topo){

    if(!IsEmpty(Topo)){
        return Topo->dado;
    }
    else return 0;

}

void PrintPilha(TNoPilha *Topo){

    TNoPilha *aux;

    if(!IsEmpty(Topo)){
        aux = Topo;
        while(aux !=NULL){
            cout<<"\n "<<aux->dado;
            aux = aux->prox;
        }
    }
    else printf("\nPilha Vazia !\n\n");
}

int main(int argc, char const *argv[])
{
    TNoPilha *P;
    Init(P);

    Push(P, 1);
    Push(P, 2);
    Push(P, 3);

    printf("\n\nO topo da Pilha e: %d", Top(P));
    printf("\n\nO Conteudo da Pilha e:\n");
    PrintPilha(P);

    TInfoPilha aux;

    aux = Pop(P);

    printf("\n\nO valor %d foi excuido do topo da pilha", aux);

    printf("\n\nDesempilhamento total da pulha");
    while (!IsEmpty(P)){
        aux = Pop(P);
        printf("\nValor excluido %2d", aux);
    }

    printf("\n\n");
    
    return 0;
}