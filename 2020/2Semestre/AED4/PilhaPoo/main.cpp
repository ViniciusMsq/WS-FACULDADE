#include <iostream>
#include "TPilhah.h"

using namespace  std; 

//-------------------------------------------------------------
int main() {
	
	TPilha::TInfoPilha aux;
	TPilha pilha;
		
	pilha.Push(13);
	
	
	printf("\n=======================================");
	printf("\n=== PILHA DINAMICA ====================\n\n");
	
	printf("Informe um numero para incluir na Pilha.....: ");
	cin >> aux;
	
	pilha.Push(aux);
	
	printf("Informe outro numero para incluir na Pilha..: ");
	cin >> aux;
	
	pilha.Push(aux);
	
	printf("Informe outro numero para incluir na Pilha..: ");
	cin >> aux;
	
	pilha.Push(aux);
	
	printf("Informe outro numero para incluir na Pilha..: ");
	cin >> aux;
	
	pilha.Push(aux);
	
	printf("\n\nO topo da Pilha e: %d", pilha.Top() );
	
	printf("\n\n\nO Conteudo da Pilha e:\n");
	
	pilha.PrintPilha();
	
	// excluindo o top da pilha
	
	aux = pilha.Pop();		
	
	
	printf("\n\nO valor %d foi excluido do topo da pilha", aux ) ;

	printf("\n\n\nDesempilhamento Total da Pilha");
	while( !pilha.IsEmpty() )	
	{
		aux = pilha.Pop();
		
		printf("\nValor excluido: %2d", aux);
	}
	
	
	printf("\n\n");
	return 0;
	
} // main()

