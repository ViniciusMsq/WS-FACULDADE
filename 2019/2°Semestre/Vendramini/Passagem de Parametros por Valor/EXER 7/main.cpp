#include <iostream>
#include <math.h>

using namespace std;

//FUNÇÃO CALCULO DO QUADRADO.
void opcao1(int *y)
{
	//Definindo Variavel do Quadrado.
	int l=0;
	
	cout<<"Digite o Valor do Lado do Quadrado: ";
	cin>>l;
	cout<<"\n";
	
	//Definindo valor de Y na multiplicação.
	*y= l*l;	
}

//FUNÇÃO CALCULO DO TRIANGULO
void opcao2(int *y)
{
	//Definindo Variavel do triangulo.
	int b=0,h=0;
	
	cout<<"Digite o Valor do Base do Triângulo: ";
	cin>>b;
	cout<<"\n";
	cout<<"Digite o Valor do Altura do Triângulo: ";
	cin>>h;
	cout<<"\n";

	*y= (b*h)/2;	
}

// FUNÇÃO CALCULO DO CIRCULO
void opcao3(int *y)
{
	//Definindo Variavel do circulo.
	int r=0;
	
	cout<<"Digite o Valor do Raio do Circulo: ";
	cin>>r;
	cout<<"\n\n";

	*y= 3.1415*pow(r,2);	
}

// FUNÇÃO CALCULO DO RETANGULO
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

//Função Principal.
int main(int argc, char** argv) 
{
	setlocale (LC_ALL,"portuguese");
	
	//Definindo Variaveis.
	int opcao=0,x;
	
	cout<<"Escolha uma opção de Calculo: "<<"\n\n";
	cout<<"1- Área do Quadrado."<<"\n";
	cout<<"2- Área do Triângulo."<<"\n";
	cout<<"3- Área do Circulo."<<"\n";
	cout<<"4- Área do Retângulo."<<"\n";
	cout<<"5- Encerrar o Programa."<<"\n\n";
	
	
	//Equanto a opção digitada for menor que 5 ele entra no Case.
	while(opcao<5)
	{
	
	cout<<"Digite a opção escolhida: ";
	cin>>opcao;
	cout<<"\n\n";
	
	switch(opcao)
	{
		case 1:
			cout<<"Opção 1-Área do Quadrado Escolhida! "<<"\n\n";
			opcao1 (&x);
			cout<<"A área do Quadro é: "<<x;
			cout<<"\n\n";
			break;
		
		case 2:
			cout<<"Opção 2-Área do Triângulo Escolhida! "<<"\n\n";
			opcao2 (&x);
			cout<<"A área do Triangulo é: "<<x;
			cout<<"\n\n";
			break;
	
		case 3:
			cout<<"Opção 3-Área do Circulo Escolhida! "<<"\n\n";
			opcao3 (&x);
			cout<<"A área do Circulo é: "<<x;
			cout<<"\n\n";
			break;
	
		case 4:
			cout<<"Opção 4-Área do Retângulo Escolhida! "<<"\n\n";
			opcao4 (&x);
			cout<<"A área do Retangulo é: "<<x;
			cout<<"\n\n";
			break;
	}
} 		

	return 0;
}
