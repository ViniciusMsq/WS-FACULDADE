#include <iostream>
#include <math.h>

using namespace std;

//FUN��O CALCULO DO QUADRADO.
void opcao1(int *y)
{
	//Definindo Variavel do Quadrado.
	int l=0;
	
	cout<<"Digite o Valor do Lado do Quadrado: ";
	cin>>l;
	cout<<"\n";
	
	//Definindo valor de Y na multiplica��o.
	*y= l*l;	
}

//FUN��O CALCULO DO TRIANGULO
void opcao2(int *y)
{
	//Definindo Variavel do triangulo.
	int b=0,h=0;
	
	cout<<"Digite o Valor do Base do Tri�ngulo: ";
	cin>>b;
	cout<<"\n";
	cout<<"Digite o Valor do Altura do Tri�ngulo: ";
	cin>>h;
	cout<<"\n";

	*y= (b*h)/2;	
}

// FUN��O CALCULO DO CIRCULO
void opcao3(int *y)
{
	//Definindo Variavel do circulo.
	int r=0;
	
	cout<<"Digite o Valor do Raio do Circulo: ";
	cin>>r;
	cout<<"\n\n";

	*y= 3.1415*pow(r,2);	
}

// FUN��O CALCULO DO RETANGULO
void opcao4(int *y)
{
	//Definindo Variavel do retangulo.
	int b=0,h=0;
	
	cout<<"Digite o Valor da Base do Retangulo: ";
	cin>>b;
	cout<<"\n";
	cout<<"Digite o Valor da Altura do Retangulo: ";
	cin>>h;
	cout<<"\n";
	
	*y= b*h;	
}

//Fun��o Principal.
int main(int argc, char** argv) 
{
	setlocale (LC_ALL,"portuguese");
	
	//Definindo Variaveis.
	int opcao=0,x;
	
	cout<<"Escolha uma op��o de Calculo: "<<"\n\n";
	cout<<"1- �rea do Quadrado."<<"\n";
	cout<<"2- �rea do Tri�ngulo."<<"\n";
	cout<<"3- �rea do Circulo."<<"\n";
	cout<<"4- �rea do Ret�ngulo."<<"\n";
	cout<<"5- Encerrar o Programa."<<"\n\n";
	
	
	//Equanto a op��o digitada for menor que 5 ele entra no Case.
	while(opcao<5)
	{
	
	cout<<"Digite a op��o escolhida: ";
	cin>>opcao;
	cout<<"\n\n";
	
	switch(opcao)
	{
		case 1:
			cout<<"Op��o 1-�rea do Quadrado Escolhida! "<<"\n\n";
			opcao1 (&x);
			cout<<"A �rea do Quadro �: "<<x;
			cout<<"\n\n";
			break;
		
		case 2:
			cout<<"Op��o 2-�rea do Tri�ngulo Escolhida! "<<"\n\n";
			opcao2 (&x);
			cout<<"A �rea do Triangulo �: "<<x;
			cout<<"\n\n";
			break;
	
		case 3:
			cout<<"Op��o 3-�rea do Circulo Escolhida! "<<"\n\n";
			opcao3 (&x);
			cout<<"A �rea do Circulo �: "<<x;
			cout<<"\n\n";
			break;
	
		case 4:
			cout<<"Op��o 4-�rea do Ret�ngulo Escolhida! "<<"\n\n";
			opcao4 (&x);
			cout<<"A �rea do Retangulo �: "<<x;
			cout<<"\n\n";
			break;
	}
} 		

	return 0;
}
