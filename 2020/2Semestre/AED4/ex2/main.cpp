#include <iostream>
#include <string.h>
#include "TPilha.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	system("cls");
	
	TPilha::TInfoPilha aux;
	TPilha pilha;

	
	char expressao[100];
	
	cout << "Digite uma Expressao Matematica:\n ";
	gets(expressao);
	
	cout << "\n\n";
	
	int erros = 0;
	
	// Verificando se a express?o est? bem formada com rela??o a par?nteses e colchetes
	for(int i=0; i < strlen(expressao); i++)
	{
		if(expressao[i] == '(' ||expressao[i] == '[' )
		{
			pilha.Push(expressao[i]);
		}
		else
		if(expressao[i] == ')' )
		{
			if( pilha.Top() != '(' )
			{
				cout << "\n\nA expressao esta mal formada: Problemas com os parenteses !!!\n\n";
				erros++;
				break;
			}
			else pilha.Pop();
		}
		else
		if(expressao[i] == ']' )
		{
			if( pilha.Top() != '[' )
			{
				cout << "\n\nA expressao esta mal formada: Problemas com os colchetes !!!\n\n";
				erros++;
				break;
			}
			else pilha.Pop();
		}
		
	} 
	
	if( pilha.IsEmpty() && erros == 0 )
	{
		cout << "\nA EXPRESSAO BEM FORMADA\n\n";
	}
	else
	if( !pilha.IsEmpty() && erros == 0 )
	{
		cout << "\n\nA expressao esta mal formada: Problemas com os " << pilha.Top() <<" !!!\n\n";	
	}
	
	cout<<"\n\n";
	return 0;
}
