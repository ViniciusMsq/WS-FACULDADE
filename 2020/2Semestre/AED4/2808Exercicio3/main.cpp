#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <cstring>
#include "TPilha.h"

using namespace std;


int Prioridade(char simbulo)
{
     switch(simbulo)
    {
        case '+':
        case '-':
            return 0;
 				//0 minino
        case '*':
        case '/':
        case '^':
            return 1;
                //1 seria 100% prioridade
    }
    
    return 0;
}

string Converter( char *express)
{
	TPilha pilha;
	
	int i = 0, cp=0, j= 0;
	char posFixa[20];
	
	
	for(i = 0; i<strlen(express); i++)
	{
		switch(express[i])
		{
			case'(':		
			pilha.Push(express[i]);
			cp++;
			break;
			
			case ')': 
				while(pilha.Top()!='(' || pilha.IsEmpty())
				{
					posFixa[j] = pilha.Pop();
					j++;
				}
				
				if(pilha.Top()=='(')
				{	
					pilha.Pop(); 
					cp--;
			    }
				break; 
			
			case'0':
			case'1':
			case'2':
			case'3':
			case'4':
			case'5':
			case'6':
			case'7':
			case'8':
			case'9':
							
			posFixa[j]=express[i];
			j ++;
			break;
		
			case '+': 
			case '-': 
			case '*':
			case '/':
					
				while( cp==0 &&  Prioridade(express[i])  <=  Prioridade(pilha.Top()) && !pilha.IsEmpty())
				{
					posFixa[j] = pilha.Pop();
					j++;
				}
				
				pilha.Push(express[i]);
				break;
			default:
				break;
		}
	}
	
	while(!pilha.IsEmpty())
	{
		posFixa[j] = pilha.Pop();
		j++;
	}
	
	return posFixa;
}


int main(int argc, char** argv) {
	
	char express[20];
	string teste;
	
	cout<<"Digite a expresssão: ";
	cin>> express;
	fflush(stdin);
	
	teste = Converter(express);
	
	printf("O resultado da Conversão ");
	cout<<teste;
	return 0;
}
