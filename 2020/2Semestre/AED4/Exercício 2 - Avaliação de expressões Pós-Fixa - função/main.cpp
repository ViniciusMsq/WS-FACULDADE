#include <iostream>
#include <string.h>
#include "TPilha.h"

using namespace std;

// NPR - Nota��o Polonesa Reversa

//--- Converte Um Caracter em Inteiro ----------------------------------------
int char_to_int(char c)
{
	return int(c) - 48 /* 48 � o c�digo ACII do 0 */;
}
//----------------------------------------------------------------------------
int Calcular_POSFIXA( char * posfixa)
{
	int i, n, A, B;
	
	bool erro=false;
	
	TPilha pilha;
	
	
	// A express�o � lida da esquerda para a direita
	//for(int i=0; i<strlen(expressao); i++)
	
	i = 0;
	while( i<strlen(posfixa) && !erro )
	{
		switch( posfixa[i] )
		{
			// Se o elemento for uma vari�vel ou constante, coloque-o no topo da pilha
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				
				n = char_to_int(posfixa[i]);
				
				pilha.Push(n);
				
				break;
				
			// Se for um operador, retire DOIS operandos do topo da pilha, efetue a opera��o e empilhe o resultado	
			case '+':				
				B = pilha.Pop();				
				A = pilha.Pop();
				n = A + B;				
				pilha.Push(n);				
				break;
				
			case '-':				
				B = pilha.Pop();				
				A = pilha.Pop();
				n = A - B;				
				pilha.Push(n);				
				break;

			case '*':				
				B = pilha.Pop();				
				A = pilha.Pop();
				n = A * B;				
				pilha.Push(n);				
				break;

			case '/':				
				// na divis�o a ordem de retirada dos elementos da pilha importa
				B = pilha.Pop();				
				A = pilha.Pop();
				
				if( B != 0 )
				{
					n = A / B;				
					pilha.Push(n);				
				}
				else 
				{
					cout << "\n\nERRO: Nao eh possivel realizar uma divisao por zero !!!";
					erro = true;
				}
				break;

			default: 
				cout << "\n\nERRO: A expressao Pos-Fixa informada nao eh valida !!!";
				erro = true;
				break;				
		
		} // switch
			
		i++;
		
	} // while...
	
	if( !erro )
	{
		n = pilha.Top();		
	}
	else
	{
		n = 0;
	}
	
	return n;

	
} // Calcular_POSFIXA

string Converter_POSFIXA(char *infixa){
	char posfixa[100];
	char caractere, topo, simbulo;
	TPilha pilha;
	
	for(int i = 0; i<strlen(infixa); i++){
		caractere = infixa[i];
		
		
	}
}
//----------------------------------------------------------------------------
int main(int argc, char** argv) 
{
	
	char expressIn[100], expresPos[100];	
	
/* -------------------------------------
Exemplos de entrada:
	Express�o INFIXA        Express�o P�S-FIXA
	(3+1)*4/2+7 = 15		31+4*2/7+
	

	Express�o INFIXA	    Express�o P�S-FIXA
	(5 + 3) * 7 = 56		53+7*
*/	
	
	cout << "\n\nInforme a expressao Pos-Fixa: ";
	cin >> expressao;
	
	 expressPos = Converter_POSFIXA( expressao );
	
	cout << "\n\nO resultado da avaliacao ou calculo da expressao eh: " << expressPos;
	
	cout << "\n\n";
		
	return 0;
}
