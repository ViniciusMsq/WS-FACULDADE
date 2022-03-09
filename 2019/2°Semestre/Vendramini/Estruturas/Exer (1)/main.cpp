#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

//Estrutura de Cadastro
struct cadastro
{		
	char nome[30],pais[15];
	float pont;	
}r[3];
	
	// Função do Cadastro 
	void fun_cadastro()
	{
		int i=0;
	
		for(i=0; i<3; i++)
		{
			// Imprimindo e declarando nome.
			cout<<"Digite o "<<i+1<<"º nome que deseja Cadastrar: ";
			fflush(stdin);
			gets(r[i].nome);
			cout<<"\n";
			
			// Imprimindo e declarando pais.
			cout<<"De qual Pais o "<< r[i].nome <<" veio: ";
			fflush(stdin);
			gets(r[i].pais);
			cout<<"\n";
			
			//imprimindo e declarando pontuação.
			cout<<"Digite a pontuação do "<<r[i].nome <<": ";
			fflush(stdin);
			cin>>r[i].pont;
			cout<<"\n";
			cout<<"----------------------------------------------\n\n";
		
		}
	
	}
	 
	 
	void fun_consulta()
	{
		
		char x[30];
		int i=0;
		
		cout<<"|-------Participantes Cadastrados-------|\n\n";
		for(i=0;i<3;i++)
		{
			cout<<" "<<i+1<<"º-Cadastro: "<<r[i].nome<<".\n";
		}
		cout<<"\n|---------------------------------------|\n\n";
		
		cout<<"Digite o nome dos participantes que deseja consultar: \n";
		fflush(stdin);
		gets(x);
		cout<<"\n";
		
		for (i=0; i<3; i++)
		{
			
			if(strcmp (x,r[i].nome)== 0)
			{
				cout<<"Nome: "<<r[i].nome<<".\n";
				cout<<"País: "<<r[i].pais<<".\n";
				cout<<"Pontuação: "<<r[i].pont<<".\n\n";
			}

		}
		

	}
		
	


int main(int argc, char** argv) 
{   
 	setlocale (LC_ALL, "Portuguese");
	
	int menu=0;
	
	// MENU DAS OPÇOES.	

	while (menu<3)
	{
		
		//Imprimindo Menu na tela.
		cout<<"| -------- MENU -------- | \n\n";
		cout<<"    1-Cadastro.   \n";
		cout<<"    2-Consulta.   \n";
		cout<<"    3-Estatística.   \n\n";
		cout<<"| ---------------------- | \n\n";
		
		// Lendo escolha do usuario.
		cout<<"Digite a opção escolhida! 1,2 ou 3: ";
		cin>>menu;
		cout<<"\n\n";
	
			// Switch esta trasendo a condição de qual opção o usuario Escolher.
			switch (menu)
			{
				case 1:
					cout<<"Você Escolheu a Opção 1 - Cadastro. \n\n";
					fun_cadastro();
					break;
				case 2:
					cout<<"Você Escolheu a Opção 2 - Consulta. \n\n";
					fun_consulta();
					break;
				case 3:
					cout<<"Você Escolheu a Opção 3 - Estatística. \n\n";
					break;
				default:
					cout<<"Opção Invalida! Somente Numeros de 1 a 3. \n\n";
					cout<<"-------------------------------------------\n\n";
					break;	
			}
			
	}
	
	
	system("pause");
}
