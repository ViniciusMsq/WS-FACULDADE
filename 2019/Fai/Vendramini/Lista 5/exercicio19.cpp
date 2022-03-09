#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int vetor[30], cont = 0;
	float media, soma = 0;
	
	for(int i = 0 ; i < 30; i++){
		
		system("cls");
		printf("\n-> EXERCICIO 19");
		cout<<"\n\nDigite um valor "<<i+1<<": ";
		cin>>vetor[i];	
		
		soma += vetor[i];
		cont++;
		
	}
	
	cout<<"\n\nVALORES: ";
	for(int i = 0 ; i < 30; i++){
		
		cout<<" "<<vetor[i];	
		
	}
	
	media = soma / cont;

	cout<<"\n\nMEDIA: "<<media;

	system("pause>>null");
	return 0;
}









