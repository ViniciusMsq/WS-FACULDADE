#include <stdio.h>
#include <iostream>

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
    char frase[4];
    frase[0] = '(';
    frase[1] = '[';
    frase[2] = ']';
    frase[3] = ')';
    
    for(int i = 0; frase[i]!='\0'; i++){
        char c;
        switch (frase[i])
        {
            case ')':
                if(!IsEmpty(P)){
                    return 0;
                }
                c = Top(P);
                if(c != '('){
                    return 0;
                }
                break;  
            case ']':
                if(!IsEmpty(P)){
                    return 0;
                }
                c = Top(P);
                if(c != '['){
                    return 0;
                }
            default: Push(P, frase[i]);
                break;
        }
    }
    PrintPilha(P);
   
    return 0;
}