#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int verificar(int idade){
	
	if(idade>=18){
		cout<<"Maior de idade";
		return 0;
	}
	else{
		cout<<"Menor de Idade";
		return 0;
	}
}
int main(int argc, char** argv) {
	int idade;

	cout<<"Informe sua idade: ";
	cin>>idade;
	cout<<"\n";
	verificar(idade);

	return 0;
}
