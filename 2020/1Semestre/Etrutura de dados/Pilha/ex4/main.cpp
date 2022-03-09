#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

class TPilha{
    public:
        
        typedef char TInfoPilha;

        struct TNoPilha
        {
            TInfoPilha dado;
            TNoPilha *prox;    
        };

        void Init(TNoPilha *&Topo);

        bool IsEmpty(TNoPilha *Topo);

        void Push(TNoPilha *&Topo, TInfoPilha elemento);

        TInfoPilha Pop(TNoPilha *&Topo);

        TInfoPilha Top(TNoPilha *Topo);

        void PrintPilha(TNoPilha *Topo);

};
    void TPilha::Init(TNoPilha *&Topo){
            Topo = NULL;
        }

        bool TPilha::IsEmpty(TNoPilha *Topo){
            return Topo == NULL;
        }

        void TPilha::Push(TNoPilha *&Topo, TInfoPilha elemento){
            TNoPilha *novo;
            novo = new TNoPilha;

            novo->dado = elemento;
            novo->prox = Topo;

            Topo = novo;
        }

        TPilha::TInfoPilha TPilha::Pop(TNoPilha *&Topo){

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

        TPilha::TInfoPilha TPilha::Top(TNoPilha *Topo){

            if(!IsEmpty(Topo)){
                return Topo->dado;
            }
            else return 0;

        }

        void TPilha::PrintPilha(TNoPilha *Topo){

            TNoPilha *aux;

            if(!IsEmpty(Topo)){
                aux = Topo;
                while(aux !=NULL){
                    cout<<aux->dado;
                    aux = aux->prox;
                }
            }
            else printf("\nPilha Vazia !\n\n");
        }

int main(int argc, char const *argv[])
{
    TPilha::TNoPilha *P;
    TPilha pilha;
    pilha.Init(P);
    char frase[100];
    // char fraseFinal[100];
    int x;
    
    system("CLS");
    cout<<"Informe uma frase: ";
    fflush(stdin);
    gets(frase);
    
    x = strlen(frase);
    
    for(int i = 0; i<=x; i++){
        
        pilha.Push(P, frase[i]);

        if(frase[i] == ' ' || frase[i]=='\0'){ 
            
            while (!pilha.IsEmpty(P)){
                cout<<pilha.Pop(P);
            }
            cout<<" ";     
        }
    }

    printf("\n\n");
    system("PAUSE");
    system("CLS");
    return 0;
}
