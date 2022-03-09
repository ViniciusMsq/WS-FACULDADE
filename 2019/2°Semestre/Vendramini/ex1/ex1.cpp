#include <iostream>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct cadastro{
	char nome[30], pais[20];
	int pont;	
};

struct cadastro ler(){
	struct cadastro cad;
	cout<<"Informe o nome: ";
	gets(nome);
	cout<<"Informe o pais: ";
	gets(pais);
	cout<<"Informe a pontuação: ";
	cin>>pont;
	return cad;
}

int main(int argc, char** argv) {
	
	struct cadastro cads;
	cads = ler();
	
	int escolha;
	
	/*cout<<"MENU"<<endl;
	cout<<"  1 - CADASTRO"<<endl;
	cout<<"  2 - CONSULTA"<<endl;
	cout<<"  3 - ESTATISTICA"<<endl;
	cout<<"Opção desejada: ";
	switch(escolha){
		case 1: 
	}*/
	return 0;
}
