#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;


typedef char TInfoPilha;

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
            cout<<aux->dado<<"; ";
            aux = aux->prox;
        }
    }
    else printf("\nPilha Vazia !\n\n");
}

int main(int argc, char const *argv[])
{
    TNoPilha *P;
    Init(P);
    char frase[1000];
    int x;

    
    system("CLS");
    cout<<"Informe uma frase: ";
    fgets(frase, 1000, stdin);
    x = strlen(frase);

    cout<<"\n";
    
    for(int i = 0; i<x; i++){
        Push(P, frase[i]);
    }
    
    printf("\n\nO conteudo da Pilha e:\n");
    PrintPilha(P);

    printf("\n\n");
    system("PAUSE");
    system("CLS");
    return 0;
}