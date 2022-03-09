#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int vetor[40], inverso[40], k;
	
	
	printf("\n-> EXERCICIO 20");
	
	for(int i = 0 ; i < 40; i++){
		
		system("cls");
		cout<<"\n\nDigite um valor "<<i+1<<": ";
		cin>>vetor[i];	
		
	}
	
	// INVERTENDO VALORES
	for(int i=39; i >= 0; i--)
	{
	    inverso[k] = vetor[i]; 
	    k++; 
    }
   
    printf("\n\n");
	
	// IMPRIMINDO VETOR NORMAL	
	cout<<"VETOR NORMAL: ";
   for(int i=0; i < 40; i++)
   {
  	    cout<<""<<vetor[i];
  	    printf("");
   }

  printf("\n\n");
	
  // IMPRIMINDO VETOR INVERTIDO
  cout<<"VETOR INVERTIDO: ";
  for(int i=0; i < 40; i++)
  {
  	cout<<""<<inverso[i];
  	printf("");
  	
  }

	system("pause>>null");
	return 0;
}








