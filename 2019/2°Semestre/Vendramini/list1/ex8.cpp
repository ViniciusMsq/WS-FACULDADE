#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float sal(float sala, int filho);

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	char nome[40];
	int filhos;
	float salario, res;
	
	res
	
	cout<<"qual seu nome? ";
	gets(nome);
	
	cout<<"quantos filhos você tem? ";
	cin>>filhos;
	
	cout<<"Qual o seu Salário? ";
	cin>>salario;
	
	res = sal(salario, filhos);
	
	cout<<"\n\nSeu salário agora é: R$ "<<res;
	return 0;
}

float sal(float sala, int filho){
		float res;
		if(sala<=1000){
			res += sala*1;
		}
		else if(sala>1000 && sala<=1800){
			res += sala*0.85;
		}
		else{
			res+= sala*0.725;
		}
		
		if(filho==1){
			res+=100;
		}
		else if(filho==2){
			res+=180;
		}
		else if(filho>2){
			res+=240;
		}
		
		return res;
}
