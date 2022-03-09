#include <iostream>

using namespace std;

void fun(char a[], int *b, float *c)
{
			
	cout<<"Digite o seu Nome: ";
	gets(a);
	cout<<"\n";
	
	cout<<"Digite a Quantidade de Filhos: ";
	cin>>*b;
	cout<<"\n";
	
	cout<<"Digite o seu Salário: ";
	cin>>*c;
	cout<<"\n";
	
}

// Calculando imposto do diabo.
void salario(float *sa, int *b)
{
	float sl;
	
	if(*sa<=1000)
	{
		sl=*sa;
	}
	else if(*sa>1000 && *sa<=1800)
	{
		sl= *sa-(*sa*0.15);
	}
	else if(*sa>1800)
	{
		sl= *sa-(*sa*0.275);
	}
	// Calculando os auxilo bolsa famila.
	if (*b==1)
	{
		sl= sl+100;
	}
	else if(*b==2)
	{
		sl= sl+180;	
	}
	else if(*b>=3)
	{
		sl= sl+240;	
	}
		*sa= sl;
		
}

//FUNÇÃO PRINCIPAL.
int main(int argc, char** argv) 
{
	char nome[10];
	int fi=0;
	float sa=0;
	fun(nome,&fi,&sa);
	salario(&sa,&fi);
	
	cout<<"Nome do Coitado: "<< nome <<" "<<"Salario Bruto: "<< sa<<"\n\n";
	
	return 0;
}
