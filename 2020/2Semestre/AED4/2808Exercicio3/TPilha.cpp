#include "TPilha.h"
#include <iostream>

using namespace std;


	void TPilha::Init()
	{			
		Topo = NULL;		
				
	} 
	bool TPilha::IsEmpty()
	{
		return Topo == NULL;
		
	} 
	void TPilha::Push(TInfoPilha elemento)
	{
		TNoPilha *novo;
		
		novo = new TNoPilha;
		
		novo->dado = elemento;
		novo->prox = Topo;
		
		Topo = novo;
		
	} 
	TPilha::TInfoPilha TPilha::Pop()
	{
		if( !IsEmpty() )
		{
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
	TPilha::TInfoPilha TPilha::Top()
	{
		if( !IsEmpty() )
		{
			return Topo->dado;
		
		} 
		else return 0;
		
	} 
	void TPilha::PrintPilha()
	{
		TNoPilha *aux;
		
		if( !IsEmpty() )
		{
			aux = Topo;
			while(aux != NULL)
			{
				cout << "\n " << aux->dado;
				aux = aux->prox;
			}
		
		} 
		else printf("\nPilha Vazia !\n\n");
		
	} 
	TPilha::TPilha()
	{
		Init();
		
	} 	
	TPilha::~TPilha()
	{
		while( !IsEmpty() )
		{
			Pop();
		}
		
	}
