#include <stdio.h>
#include <iostream>
using namespace std;

typedef float TInfoPilha;

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
    float valores = 0;

    do{
        cout<<"Informe um valor: ";
        cin>>valores;
        Push(P, valores);
    }while(valores!= -13);
    
    Pop(P);

    cout<<"\n\nTopo da Pilha: "<<Top(P);
    cout<<"\nDesempilhando:";

    TInfoPilha aux;

    while (!IsEmpty(P)){
        cout<<"\nvalor desempilhado: "<<Pop(P);
    }

    printf("\n\n");
    
    system("PAUSE");
    return 0;
}