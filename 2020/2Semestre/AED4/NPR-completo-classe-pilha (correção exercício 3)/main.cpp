#include <iostream>
#include <string.h>
#include "TPilha.h"

using namespace  std; 

//--- Converte Um Caracter em Inteiro ----------------------------------------
int char_to_int(char c)
{
	return int(c) - 48;
}

//----------------------------------------------------------------------------
// NOTAÇÃO POLONESA REVERSA - RESOLVE UMA EXPRESSÃO POSFIXA
//----------------------------------------------------------------------------
int resolver_NPR(string posfixa)
{
	int i;	
	char c;
	int operando1, operando2;

	TPilha P;
	
	for(i=0; i < posfixa.length(); i++)
	{		
		c = posfixa[i];
				
		switch( c )  
		{
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
				P.Push( char_to_int(c) );
				break;
					  
			case '+':
			    operando1 = P.Pop();
				operando2 = P.Pop();
				// a ordem dos operandos na operação deve ser feita na ordem inversa a que foi retirada da pilha
				P.Push(operando2 + operando1); 
				break;
				
			case '-':
			    operando1 = P.Pop();
				operando2 = P.Pop();
				P.Push(operando2 - operando1);
				break;
				
			case '*':
			    operando1 = P.Pop();
				operando2 = P.Pop();
				P.Push(operando2 * operando1);
				break;
				
			case '/': 
			    operando1 = P.Pop();
				operando2 = P.Pop();
				
				if( operando1 != 0)
				{
					P.Push(operando2 / operando1);
				}
				else 
				{
					printf("\n\nERRO: Divisao por zero!!!\n\n");
					P.Push(0);
				}					
				break;
			
		} // switch
		
	} // for posfixa...	
	
	return P.Top();

} // resolver_NPR

//----------------------------------------------------------------------------
int precedencia_op(char c)
{
	if( c == '-' || c == '+')
	{
		return 1;
	}
	else return 2;
}

//----------------------------------------------------------------------------
// NOTAÇÃO POLONESA REVERSA - CONVERTE UMA EXPRESSÃO INFIXA PARA POSFIXA
//----------------------------------------------------------------------------
string Infixa_To_Posfixa(string infixa)
{
	int i;
	char c;
	
	string posfixa;
	
	TPilha P;	
	
	posfixa = "";

	for(i = 0; i < infixa.length(); i++)
	{		
		c = infixa[i];
		
		//posfixa = posfixa + c;
		
		switch( c )
		{	
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
				posfixa = posfixa + c;				
				break;
			
			case '(':
				P.Push((int)c);
				break;
			
			case '+':
			case '-':
			case '*':
			case '/':
				while(!P.IsEmpty() ) 
				{
					if( P.Top() != '(' && precedencia_op(c) <= precedencia_op(P.Top()) )
					{
						posfixa = posfixa + (char)P.Pop();
					}
					else
					{
						break; // quebra o while...
					}					
				} // while...	
					
				P.Push((int)c);

				break;

			case ')':
				
				while( !P.IsEmpty() )
				{
					if( P.Top() != '(' )
					{
						posfixa = posfixa + (char)P.Pop();
					}
					else
					{
						P.Pop();
						break; // quebra o while interno : while( !IsEmpty(P) )
					}
				} // while( !IsEmpty(P) )
				
				break;
			
		} // switch( c )	
		
		
	} // for infixa (leitura da infixa caractere a caractere)
	
	
	while( !P.IsEmpty() )
	{
		if( P.Top() != '(')
		{
			posfixa = posfixa + (char)P.Pop();
		}
		else 
		{
			P.Pop();
		}		
		
	} // while( !IsEmpty(P) )
	
	return posfixa;
	
} // Infixa_To_Posfixa()


// --- main() ----------------------------------------------------------------
int main(int argc, char** argv) {
	
	string infixa, posfixa;
	
	//infixa = "1+2*3+(4+5)*6";
	//infixa = "(5+3)*7"; // 56
	//infixa = "(3+1)*4/2+7"; // posfixa="31+4*2/7+" o resultado é 15
	
	cout << "\n\nInforme a expressao INFixa: ";
	cin >> infixa;
	
	
	cout << "\n\nINFIXA..: " << infixa;
	
	posfixa = Infixa_To_Posfixa(infixa);
	
	cout << "\n\nPOSFIXA.: " << posfixa;
	
	printf("\n\nO resultado da expressao eh: %d ", resolver_NPR(posfixa));		

	printf("\n\n");	
	return 0;
	
} // fim main()

















