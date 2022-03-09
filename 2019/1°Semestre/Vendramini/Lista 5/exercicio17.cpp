#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int tam, ord, aux;

	
	
	printf("\n-> EXERCICIO 17");
	cout<<"\n\nDigite o tamanho do vetor: ";
	cin>>tam;
	
	int vetor[tam+1];
	
	for(int i = 0 ; i < tam+1; i++)
	{
		
		if ( i == tam)
		{
			cout<<"\n\nDigite o valor que deseja ordenar: ";
			cin>>vetor[i];
			break;
		}
		
		system("cls");
		printf("\n-> EXERCICIO 17");
		cout<<"\n\nVETOR [ "<<i+1<<" ]: ";
		cin>>vetor[i];	
	
	}
	
	// VETOR DESORDENADO
	cout<<"\n\nVETOR DESORDENADO: ";
	for(int i = 0; i < tam+1; i++)
	{
		cout<<" "<<vetor[i];
	}

	
	// ORDENANDO VETOR MÉTODO (BUBBLE SORT)
    for(int cont1 = 0; cont1 < tam+1; cont1++)
	{
    	for(int cont2 = cont1+1; cont2 < tam+1; cont2++)
		{
    		if (vetor[cont1] > vetor[cont2]){
    			aux = vetor[cont1];
    			vetor[cont1] = vetor[cont2];
    			vetor[cont2] = aux;
    		}
    		
    	}
    	
    }
	
    cout<<"\n\nVETOR ORDENADO: ";
	for(int i = 0 ; i < tam+1; i++){
		
		cout<<" "<<vetor[i];	
	
	}

	system("pause>>null");
	return 0;
}










