#include <iostream>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct cad_livro{
	int codigo, quant;
	char nome[400], autor[30];
};

struct emp_livro{
	int num, dia, mes, ano, cod[3];
};
void func_cad(struct cad_livro cad[], int *c){
	char op;
	int i= 0;
	do{
		cout<<"Informe o código: "<<endl;
		cin>>cad[i].codigo;
		cout<<"Nome do livro: "<<endl;
		fflush(stdin);
		gets(cad[i].nome);
		cout<<"Nome do Autor: "<<endl;
		fflush(stdin);
		gets(cad[i].autor);
		cout<<"Quantidade para o acervo: "<<endl;
		cin>>cad[i].quant;
		c++;
		i++;
		cout<<"\n\nDeseja fazer mais um cadastro?(S/N)"<<endl;
		cin>>op;		
	}while(op=='s' || op=='S');
}

void func_emp(struct cad_livro cad[] ,struct emp_livro emp[], int *c2, int c){
	char op;
	int i = 0;
	int i2= 0;
	do{
		cout<<"Informe o numero do emprestimo: ";
		cin>>emp[i].num;
		cout<<"Informe o dia:";
		cin>>emp[i].dia;
		cout<<"Informe o mes:";
		cin>>emp[i].mes;
		cout<<"Informe o ano:";
		cin>>emp[i].ano;
		do{
		cout<<"codigo do livro emprestado";
		fflush(stdin);
		cin>>emp[i].cod[i2];
		for(int k = 0; k<c; k++){
			if(cad[k].codigo==i2){
				cad[k].quant--;
			}
		}
		
		cout<<"\n\nMais um livro?(S/N)"<<endl;
		cin>>op;
		i2++;
		}while(op=='s' || op=='S');
		c2++;
		i++;
		cout<<"\n\nDeseja fazer mais um cadastro de emprestimo?(S/N)"<<endl;
		cin>>op;		
	}while(op=='s' || op=='S');
	
}

func_acervo(struct cad_livro cad[], int c){
	
	for(int i=0; i<c; i++){
		cout<<"|"<<cad[i].codigo;cout<<"|";puts(cad[i].nome);cout<<"|";puts(cad[i].autor);cout<<"|"<<cad[i].quant<<"|"<<endl;
	}
}

func_empres(struct emp_livro emp[], int c2){
	
	for(int i=0; i<c2; i++){
		cout<<"|"<<emp[i].num<<"|"<<emp[i].dia<<"/"<<emp[i].mes<<"/"<<emp[i].ano<<"| livros(cod): "<<emp[i].cod[0]<<", "<<emp[i].cod[1]<<", "<<emp[i].cod[2]<<endl;
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
		int op, c, c2;
		struct cad_livro cad[3];
		struct emp_livro emp[3];	
		
		cout<<"-----MENU"<<endl;		
		cout<<" 1- Cadastrar livros\n 2- Efetuar empréstimos\n 3- Listar todos os livros\n 4- Listar todos os empréstimos\n 5- Encerrar o programa\n\n Digite a opção desejada: "<<endl;
		cin>>op;
		
		switch(op){
			case 1:system("cls");
				cout<<"Cadastrar Livros\n"<<endl;
				func_cad(cad, &c);
				break;
			case 2:system("cls");
				cout<<"Efetuar empréstimos: "<<endl;
				func_emp(cad, emp, &c2, c);
				break;
			case 3:system("cls");
				cout<<"Listar todos os livros: "<<endl;
				func_acervo(cad, c);
				break;
			case 4:system("cls");
				cout<<"Listar todos os empréstimos: "<<endl;
				break;
			case 5: exit(0);
			    break;
			default: cout<<"Opção inválida";
		}
	return 0;
}
