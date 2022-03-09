#include "TClasseFila.h"
#include <iostream>

using namespace std;

//--- Implementações dos Métodos da Classe Fila -------------------------


//-------------------------------------------------------------
TClasseFila::TNoFila * TClasseFila::GetComeco()
{
	// se a Fila não estiver vazia
	if( !Q_IsEmpty() )
	{
		return Fila->Comeco;
	
	} 
	else return NULL;
	
} // *TNoFila GetComeco()


//-------------------------------------------------------------
TClasseFila::TNoFila * TClasseFila::GetFinal()
{
	// se a Fila não estiver vazia
	if( !Q_IsEmpty() )
	{
		return Fila->Final;
	
	} 
	else return NULL;
	
} // *TNoFila GetFinal()


//-------------------------------------------------------------
TClasseFila::TClasseFila()
{
	Q_Init();
	
} // construtor

//-------------------------------------------------------------
TClasseFila::~TClasseFila()
{
	while( !Q_IsEmpty() ) Dequeue();
	
} // DEstrutor

//-------------------------------------------------------------
void TClasseFila::Q_Init()
{
	Fila = new TFila;
	Fila->Comeco = NULL;
	Fila->Final  = NULL;
	
} // void Init()

//-------------------------------------------------------------
bool TClasseFila::Q_IsEmpty()
{
	return Fila->Comeco == NULL;
	
} // bool IsEmpty()

//-------------------------------------------------------------
void TClasseFila::Enqueue(TClasseFila::TInfoFila elemento)
{
	TNoFila *novo;
	novo = new TNoFila;

	novo->dado = elemento;
	novo->prox = NULL;
	
	if( Q_IsEmpty() )	
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
TClasseFila::TInfoFila TClasseFila::Dequeue()
{
	TInfoFila aux;
	
	TNoFila *no_aux;
	
	if( !Q_IsEmpty() )	
	{		
		aux = Fila->Comeco->dado;
		
		no_aux = Fila->Comeco;
		
		Fila->Comeco = Fila->Comeco->prox;	
		
		delete(no_aux);
	}
	/*
	else
	{
		aux = NULL;
	}
	*/
	
	return aux;	
	
} // Dequeue

//-------------------------------------------------------------
TClasseFila::TInfoFila TClasseFila::Q_Comeco()
{
	TInfoFila aux;
	
	// se a Fila não estiver vazia
	if( !Q_IsEmpty() )
	{
		aux = Fila->Comeco->dado;
	
	} 	
	//else return 0;
	
	return aux;
	
} // TInfoFila Q_Comeco()

//-------------------------------------------------------------
TClasseFila::TInfoFila TClasseFila::Q_Final()
{
	TInfoFila aux;
	
	// se a Fila não estiver vazia
	if( !Q_IsEmpty() )
	{
		aux = Fila->Final->dado;
	
	} 
	//else return 0;
	
	return aux;
	
} // TInfoFila Q_Final()


//-------------------------------------------------------------
void TClasseFila::PrintFila()
{	
	if( !Q_IsEmpty() )
	{
		TNoFila *aux_no;	
	
		cout << "\n\nCONTEUDO DA FILA DE ESPERA:\n";
		aux_no = Fila->Comeco;

		int i=1;
		while( aux_no != NULL )		
		{
			printf("\n--------------------------------------------------------------------------");
			printf("\nPosicao No. %d", i);
			cout << "\nNome...............: " << aux_no->dado.nome;
			cout << "\nTelefone...........: " << aux_no->dado.telefone;
			printf("\nGrau de Urgencia...: %d", aux_no->dado.grau);
					
			
			i++;
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
int TClasseFila::GetSize()
{
	int n=0;
	
	if( !Q_IsEmpty() )
	{
		TNoFila *aux_no;	

		aux_no = Fila->Comeco;

		while( aux_no != NULL )		
		{
			n++;
			aux_no = aux_no->prox;
		}
	} // se a fila não estiver fazia

	return n;
	
} // GetSize

void TClasseFila::ConsultaNome(string nome){
	if( !Q_IsEmpty() )
	{
		TNoFila *aux_no;	
	
		cout << "\n\nCONTEUDO DA FILA DE ESPERA:\n";
		aux_no = Fila->Comeco;

		int i=1;
		while( aux_no != NULL )		
		{
			if(nome == aux_no->dado.nome){
				printf("\n--------------------------------------------------------------------------");
				printf("\nPosicao No. %d", i);
				cout << "\nNome...............: " << aux_no->dado.nome;
				cout << "\nTelefone...........: " << aux_no->dado.telefone;
				printf("\nGrau de Urgencia...: %d", aux_no->dado.grau);
				
				break;
			}
			
			i++;
			aux_no = aux_no->prox;
		}

	} // se a fila não estiver fazia
	else 
	{
		cout << "\n\nA FILA esta vazia !!!";
	}
	
	cout << "\n\n";	
}

