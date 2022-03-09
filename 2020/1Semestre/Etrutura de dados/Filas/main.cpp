#include <iostream>
using namespace std;
typedef int TInfoFila;

struct TNoFila{
    TInfoFila dado;
    TNoFila *prox;
};

struct TFila{
    TNoFila *Comeco;
    TNoFila *Final;
};

void Q_Init(TFila *&Fila){
    Fila = new TFila;
    Fila -> Comeco = NULL;
    Fila -> Final  = NULL;
}

bool Q_IsEmpty(TFila *Fila){
    return Fila -> Comeco == NULL;
}

void Enqueue(TFila *&Fila, TInfoFila elemento){
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

TInfoFila Dequeue(TFila *Fila){
    
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

TInfoFila Q_Comeco(TFila *Fila){
    if(!Q_IsEmpty(Fila)){
        return Fila->Comeco->dado;
    }
    else return 0;
}

TInfoFila Q_Final(TFila *Fila){
    if(!Q_IsEmpty(Fila)){
        return Fila->Final->dado;
    }
    else return 0;
}

void PrintFila(TFila *F){

    if(!Q_IsEmpty(F)){
        TNoFila *aux_no;

        cout<<"\n\nO Conteudo da Fila e:\n";
        aux_no = F->Comeco;

        while(aux_no != NULL){
            cout<< aux_no->dado;
            aux_no = aux_no->prox;
        }
    }
    else{
        cout<<"\n\nA Fila esta vazia !!!";
    }
    cout<<"\n\n";
}


int main(int argc, char const *argv[])
{
    TInfoFila aux;
    TFila *F;

    Q_Init(F);

    cout<<"\n==============================";
    cout<<"\n===FILA DINAMICA=================\n\n";

    Enqueue(F, 1);
    Enqueue(F, 2);
    Enqueue(F, 3);
    Enqueue(F, 4);

    PrintFila(F);

    cout<<"\n\nEste e o comeco da fila...: "<<Q_Comeco(F);
    cout<<"\n\nEste e o Final da fila...: "<<Q_Final(F);

    aux = Dequeue(F);

    cout<<"\n\nO elemento "<< aux << " foi retirado da fila";

    cout<<"\n\nAgora o comeco da fila e:"<< Q_Comeco(F);

    Enqueue(F, 13);
    Enqueue(F, 27);
    Enqueue(F, 48);

    PrintFila(F);

    cout<<"\n\nEsvaziando a pilha\n\n";
    while (!Q_IsEmpty(F))
    {
        cout<<"\nElemento excluido: "<<Dequeue(F);
    }

    printf("\n\n");
    
    return 0;
}
