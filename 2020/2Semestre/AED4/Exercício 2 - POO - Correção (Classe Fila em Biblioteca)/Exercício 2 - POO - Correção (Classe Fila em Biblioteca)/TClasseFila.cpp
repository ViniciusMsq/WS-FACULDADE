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
	else
	{
		aux = 0;
	}
	
	return aux;	
	
} // Dequeue

//-------------------------------------------------------------
TClasseFila::TInfoFila TClasseFila::Q_Comeco()
{
	// se a Fila não estiver vazia
	if( !Q_IsEmpty() )
	{
		return Fila->Comeco->dado;
	
	} 
	else return 0;
	
} // TInfoFila Q_Comeco()

//-------------------------------------------------------------
TClasseFila::TInfoFila TClasseFila::Q_Final()
{
	// se a Fila não estiver vazia
	if( !Q_IsEmpty() )
	{
		return Fila->Final->dado;
	
	} 
	else return 0;
	
} // TInfoFila Q_Final()


//-------------------------------------------------------------
void TClasseFila::PrintFila()
{	
	if( !Q_IsEmpty() )
	{
		TNoFila *aux_no;	
	
		cout << "\n\nO CONTEUDO DA FILA E:\n";
		aux_no = Fila->Comeco;

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

