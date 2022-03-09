#include <iostream>
#include "TClasseFila.h"

using namespace std; 

//-------------------------------------------------------------
int main(int argc, char** argv) {
	
	TClasseFila::TInfoFila aux;		
	
	TClasseFila fila;
		
	printf("\n=======================================");
	printf("\n=== FILA DINAMICA - EXERCICIO 1 ======\n\n");
	
	for(int i=0; i < 5; i++ )
	{
		cout << "Informe um valor para a Fila: ";
		cin >> aux;
		
		fila.Enqueue(aux);		
	}
	
	
	cout << "\n\nO conteudo da fila eh: \n\n";
	
	//fila.PrintFila();
	
	
	TClasseFila::TNoFila *no_auxiliar;
	
	
	no_auxiliar = fila.GetComeco();
	
	while( no_auxiliar != NULL )
	{		 
		cout << no_auxiliar->dado << "\t";
		
		no_auxiliar = no_auxiliar->prox;
	}
	
	
	printf("\n\n");
	return 0;
	
} // main()
