#include <iostream>
#include <string.h>

using namespace std; 

//--- Definição da Estrutura da Fila -------------------------

typedef char TInfoFila;

struct TNoFila {	
	TInfoFila dado;	
	TNoFila *prox;		
};

struct TFila {	
	TNoFila *Comeco;
	TNoFila *Final;
};

//-------------------------------------------------------------
void Q_Init(TFila *&Fila)
{
	Fila = new TFila;
	Fila->Comeco = NULL;
	Fila->Final  = NULL;
	
} // void Init()

//-------------------------------------------------------------
bool Q_IsEmpty(TFila *Fila)
{
	return Fila->Comeco == NULL;
	
} // bool IsEmpty()

//-------------------------------------------------------------
void Enqueue(TFila *&Fila, TInfoFila elemento)
{
	TNoFila *novo;
	novo = new TNoFila;

	novo->dado = elemento;
	novo->prox = NULL;
	
	if( Q_IsEmpty(Fila) )	
	{
		Fila->Comeco = novo;
		Fila->Final  = novo;		
		
	} // se a Fila estiver vazia
	else
	{
		Fila->Final->prox = novo;
		
		Fila->Final  = novo;		
				
	} // se a Fila NÃÃÃÃÕOOOO estiver vazia
	
} // void Enqueue(int n)

//-------------------------------------------------------------
TInfoFila Dequeue(TFila *Fila)
{
	TInfoFila aux;
	
	TNoFila *no_aux;
	
	if( !Q_IsEmpty(Fila) )	
	{		
		aux = Fila->Comeco->dado;
		
		no_aux = Fila->Comeco;
		
		Fila->Comeco = Fila->Comeco->prox;	
		
		delete(no_aux);
		
		return aux;	
	}
	else
	{
		return NULL;
	}
	
	
	
} // Dequeue

//-------------------------------------------------------------
TInfoFila Q_Comeco(TFila *Fila)
{
	// se a Fila não estiver vazia
	if( !Q_IsEmpty(Fila) )
	{
		return Fila->Comeco->dado;
	
	} 
	else return NULL;
	
} // TInfoFila Q_Comeco()

//-------------------------------------------------------------
TInfoFila Q_Final(TFila *Fila)
{
	// se a Fila não estiver vazia
	if( !Q_IsEmpty(Fila) )
	{
		return Fila->Final->dado;
	
	} 
	else return NULL;
	
} // TInfoFila Q_Final()


//-------------------------------------------------------------
void PrintFila(TFila *F)
{	
	if( !Q_IsEmpty(F) )
	{
		TNoFila *aux_no;	
	
		cout << "\n\nO CONTEUDO DA FILA E:\n";
		aux_no = F->Comeco;

		while( aux_no != NULL )		
		{
			cout << aux_no->dado << " ";
			aux_no = aux_no->prox;
		}

	} // se a fila não estiver fazia
	else 
	{
		cout << "\n\nA FILA esta vazia !!!";
	}
	
	cout << "\n\n";	
	
} // PrintFila

//-------------------------------------------------------------
int main(int argc, char** argv) {
	
	TInfoFila aux;		
	TFila *F;
		
	Q_Init(F);
	
	printf("\n=======================================");
	printf("\n=== FILA DINAMICA - EXERCICIO 3 ======\n\n");
	
	char frase[100];
	
	cout << "Digite uma frase: ";
	gets(frase);
	
	// empilhando os caracteres da frase
	for(int i=0; i < strlen(frase); i++)
	{
		Enqueue(F, frase[i]);
	}
	
	printf("\n\n");
	
	TNoFila *aux_no;	

	cout << "\n\nO CONTEUDO DA FILA E:\n";
	aux_no = F->Comeco;

	while( aux_no != NULL )		
	{
		cout << aux_no->dado;
		aux_no = aux_no->prox;
	}
	
	printf("\n\n");
	return 0;
	
} // main()
