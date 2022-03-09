#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void opcao1(float *x)
{
	int cont=0, soma=0, nota=0, i=0;
	
	for(i=0; i<10; i++)
	{
		cout<<"\nDigite o sua nota: ";
		cin>>nota;
		cout<<"\n\n";
		soma=soma+nota;
		cont++;
		
	} 
		*x = soma/cont;
		
		cout<<"Media das Notas: "<<*x;
		cout<<"\n";
}	

void opcao2(int *y)
{
	int num;
	
	while (num!=0)
	{
		cout<<"\nDigite um numero: ";
		cin>>num;
		cout<<"\n\n";
		
		if(num<0)
		{
			cout<<"O numero:"<< num <<" é negativo. ";
			cout<<"\n\n";
		}
		else if(num>0)
		{
			cout<<"O numero:"<< num <<" é positivo. ";
			cout<<"\n\n";
		}
		else
		{
			cout<<"Programa Encerrado !.";
			cout<<"\n\n";
		}
		
	} 

}





int main(int argc, char** argv) 
{
	setlocale (LC_ALL,"portuguese");
	
	float media;
	int numero, menu;
	
	cout<<"1-Calcular a Media. \n";
	cout<<"2-Positivo/Negativo. \n";
	cout<<"3-Encerra o Programa. \n\n";
	
	
	while (menu!=3)
	{
	
	
	cout<<"Escolha uma das Opações: ";
	cin>>menu;
	cout<<"\n\n";
	
	if (menu>3 || menu<1)
	{
		cout<<"Opção Invalida.\n\n";
	}
	
	switch(menu)
	{
		case 1:
			cout<<"A opção 1-Calcular a Média!";
			opcao1(&media);
			cout<<"\n\n";
		break;
			
		case 2:
			cout<<"A opção 2-Positivo e Negativo!";
			opcao2(&numero);
			cout<<"\n\n";
		break;
	
	}

}

}
	

