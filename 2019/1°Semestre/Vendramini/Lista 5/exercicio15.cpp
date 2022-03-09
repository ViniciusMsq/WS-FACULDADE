#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int inicial[50], aux[50], final[50];
	int n, i, j=0, z=0, k, cont, num;

	printf("\n-> EXERCICIO 15");
	cout<<"\n\nDigite o tamanho do vetor: ";
	cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		system("cls");
		printf("\n-> EXERCICIO 15");
		cout<<"\n\nVETOR [ "<<i+1<<" ]: ";
		cin>>inicial[i];	
				
	}
	
	for(i = 0; i < n; i++)
	{
		cont = 0;
		
		num = inicial[i];
		aux[j] = num;
		j++;
		
		for(k = 0; k < n; k++)
		{
			if(aux[k] == num)
			{
				cont++;
			}

		}
					
		if(cont == 1)
		{
			final[z] = num;
			z++;				
		}
	}
	
	// IMPRIMINDO VETOR 1
	cout<<"\n\nIMPRIMINDO VETOR 1: ";
	for(int i = 0; i < n; i++)
	{
		cout<<" "<<inicial[i];
	}
	
		// IMPRIMINDO VETOR 1
	cout<<"\n\nIMPRIMINDO VETOR 2: ";
	for(int i = 0; i < z; i++)
	{
		cout<<" "<<final[i];
	}
		
	system("pause>>null");
	return 0;
}












