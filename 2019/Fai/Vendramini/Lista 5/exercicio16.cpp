#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int tam, valor, pos, cont = 1, cont2 = 1;

	printf("\n-> EXERCICIO 16");
	cout<<"\n\nDigite o tamanho do vetor: ";
	cin>>tam;
	
	int vetor[tam];
	
	// RECEBENDO OS VALORES 0
	for(int i = 1; i <= tam; i++)
	{
		vetor[i] = 0;
	}
	
	
	while(cont <= tam)
	{
		system("cls");
		printf("\n-> EXERCICIO 16");
		cout<<"\n\nDigite o valor ["<<cont<<"]: ";
		cin>>valor;
		
		cout<<"\n\nDigite a posição do valor ["<<cont<<"]: ";
		cin>>pos;	
		
		if(vetor[pos] == 0 )
		{	
			vetor[pos] = valor;
			
		}else{
			
			for(int i = 1; i <= tam; i++)
			{
				if(vetor[i] == 0)
				{
					vetor[i] = vetor[pos];
					vetor[pos] = valor;	
					
					break;
				}
			}
				
		}
		
		cont++;
			
	}
	
	// IMPRIMINDO VETOR
	cout<<"\n\nIMPRIMINDO VETOR: \n";
	for(int i = 1; i <= tam; i++)
	{
		cout<<" "<<vetor[i];
	}
		
	system("pause>>null");
	return 0;
}











