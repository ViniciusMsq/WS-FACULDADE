#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int aulas;
	float valor, resultado;
	
	cout<<"Informe o numero de aulas: ";
	cin>>aulas;
	cout<<"\nInforme o valor recebido por cada aula: ";
	cin>>valor;
	
	resultado = valor*aulas;
	
	cout<<"\nO salario Bruto é: "<<resultado;
	cout<<"\nO salario Liquido e: "<<resultado-(resultado*0.11); 
	
	return 0;
}
