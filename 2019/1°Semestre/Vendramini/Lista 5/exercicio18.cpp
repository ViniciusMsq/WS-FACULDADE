#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	float vetor1[20], vetor2[20], result[20];
	char vetor3[20];
	
	for(int i = 0 ; i < 20; i++){
		
		system("cls");
		printf("\n-> EXERCICIO 18");
		cout<<"\n\nVETOR 1 [ "<<i+1<<" ]: ";
		cin>>vetor1[i];	
		cout<<"\n\nVETOR 2 [ "<<i+1<<" ]: ";
		cin>>vetor2[i];
		cout<<"\n\nQual operação Aritimetica deseja realizar: ";
		cin>>vetor3[i];
		
		if(vetor3[i] == '+'){
			
			result[i] = vetor1[i] +	vetor2[i];
			
		}else if(vetor3[i] == '-'){
		
			result[i] = vetor1[i] -	vetor2[i];
			
		}else if(vetor3[i] == '*'){
		
			result[i] = vetor1[i] *	vetor2[i];
			
		}else if(vetor3[i] == '/'){
		
			result[i] = vetor1[i] /	vetor2[i];
			
		}
		
	}
	
	cout<<"\n\nVETOR 1: ";
	for(int i = 0 ; i < 20; i++){
		
		cout<<" "<<vetor1[i];	
	}
	
	cout<<"\n\nVETOR 2: ";
	for(int i = 0 ; i < 20; i++){
		
		cout<<" "<<vetor2[i];	
	}
	
	cout<<"\n\nOPERAÇÕES: ";
	for(int i = 0 ; i < 20; i++){
		
		cout<<" "<<vetor3[i];	
	}
	
	cout<<"\n\n\nRESULTADO: ";
	for(int i = 0 ; i < 20; i++){
		
		cout<<" "<<result[i];	
	}

	system("pause>>null");
	return 0;
}










