#include <iostream>
#include <locale.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct registro{
	char nome[30], sexo[12];
	float nota;
};

void func_cad(struct registro r[], int *cont){
	for(int i=0; i<50; i++){
		cout<<"Digite o Nome: ";
		fflush(stdin);
		gets(r[i].nome);
		
		cout<<"Digite o sexo: ";
		fflush(stdin);
		gets(r[i].sexo);
		
		cout<<"Digite a nota: ";
		cin>>r[i].nota;
		cout<<endl;
		cont++;
		
	}
	
}

void func_exibir(struct registro r[], int cont){
	float media;
	for(int i=0; i<50;i++){
		media+=r[i].nota;
		cont++;
	}
	media=media/cont;	
	for(int i=0; i<50; i++){
		cout<<"Nome: "; puts(r[i].nome); cout<<" Sexo: "; puts(r[i].sexo); cout<<" Nota: "<<r[i].nota<<endl;
	}
	cout<<"Media dos alunos: "<<media;
}

int main(int argc, char** argv) {
	
	int cont;
	struct registro r[50];
	func_cad(r, &cont);
	func_exibir(r, cont);
	
	return 0;
}
