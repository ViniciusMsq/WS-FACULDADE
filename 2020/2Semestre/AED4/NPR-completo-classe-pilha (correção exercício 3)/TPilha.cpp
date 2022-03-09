#include "TPilha.h"
#include <iostream>

using namespace std;

//-------------------------------------------------------------
// Implementação dos Métodos da Classe TPilha

	//-------------------------------------------------------------
	void TPilha::Init()
	{			
		Topo = NULL;		
				
	} // void Init()

	//-------------------------------------------------------------
	bool TPilha::IsEmpty()
	{
		return Topo == NULL;
		
	} // bool IsEmpty()

	//-------------------------------------------------------------
	void TPilha::Push(TInfoPilha elemento)
	{
		TNoPilha *novo;
		
		novo = new TNoPilha;
		
		novo->dado = elemento;
		novo->prox = Topo;
		
		Topo = novo;
		
	} // void Push(int n)
	
	//-------------------------------------------------------------
	TPilha::TInfoPilha TPilha::Pop()
	{
		// se a pilha não estiver vazia
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
		
	} // TInfoPilha Pop()
	
	//-------------------------------------------------------------
	TPilha::TInfoPilha TPilha::Top()
	{
		// se a pilha não estiver vazia
		if( !IsEmpty() )
		{
			return Topo->dado;
		
		} 
		else return 0;
		
	} // TInfoPilha Top()
	
	//-------------------------------------------------------------
	void TPilha::PrintPilha()
	{
		TNoPilha *aux;
		
		// se a pilha não estiver vazia
		if( !IsEmpty() )
		{
			aux = Topo;
			while(aux != NULL)
			{
				cout << "\n " << aux->dado;
				aux = aux->prox;
			}
		
		} 
		else printf("\nPilha Valiza !\n\n");
		
	} // PrintPilha()
	
	//-------------------------------------------------------------
	TPilha::TPilha()
	{
		Init();
		
	} // construtor
	
	//-------------------------------------------------------------		
	TPilha::~TPilha()
	{
		// Esvaziando ou destruindo a pilha
		while( !IsEmpty() )
		{
			Pop();
		}
		
	} // DEstrutor




