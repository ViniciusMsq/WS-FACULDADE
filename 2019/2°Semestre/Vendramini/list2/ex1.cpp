#include <iostream>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct cadastro{
	char nome[30], pais[20];
	int pont;
};

void func_cad(struct cadastro cad[], *c, *jb){
	
	for(int i=0; i<3; i++){
		cout<<"Nome: ";
		fflush(stdin);
		gets(cad[i].nome);
		cout<<"País: ";
		fflush(stdin);
		gets(cad[i].pais);
		if(cad[i].pais=='brasil' || cad[i].pais=='Brasil'){
			jb++;
		}
		cout<<"Pontuação: ";
		cin>>cad[i].pont;
		c++;
		system("cls");
	}
}

void func_con(struct cadastro cad[]){
	char n[30];
	cout<<"Informe o nome";
	gets(n);
	for(int i; i<3; i++){
		if(n==cad[i].nome){
			puts(cad[i].nome);puts(cad[i].pais);
			cout<<cad[i].pont;
		}
	}
}

void func_est(struct cadastro cad[], int c, int jb){
	int mpont;
	char nome[30];
	
	cout<<"Jogadores Cadastrados: "<<c;
	cout<<"Quantidade de jogadores Br: "<<jb;
	
	for(int i=0; i<3; i++){
		if(cad[i].pont>mpont){
			mpont=cad[i].pont;
			nome=cad[i].nome;
		}
	}
	cout<<"nome do maior pontuador: "<<nome;
	cout<<"maior pontuação: "<<mpont;
	
}
int main(int argc, char** argv) {
	setlocale (LC_ALL, "Portuguese");
	int op, c, jb;
	struct cadastro cad[3];
	
	cout<<"Informe a opção: ";
	cin>>op;
	
	switch(op){
		case 1:system("cls");
		cout<<"Cadastro"<<endl;
		func_cad(cad, &c, &jb);
		break;
		case 2:system("cls");
		cout<<"Consultar"<<endl;
		func_con(cad); 
		break;
		case 3:system("cls");
		cout<<"Estatisca"<<endl;
		func_est(cad, c, jb); 
		break;
		default: cout<<"Invalido";
	}
	return 0;
}
