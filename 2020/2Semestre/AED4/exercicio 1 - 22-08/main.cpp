#include <iostream>
#include "TClasseFila.h"
#include <conio.h>

using namespace std; 

/**************************************************************************************
Exercício 3: Um hospital de cardiologia precisa de um sistema para efetuar o cadastro de pacientes que
necessitam de doação de coração. Para cada paciente que é incluído no sistema deve ser
informado o nome, telefone e o grau de urgência para transplante. O grau de urgência é
definido na seguinte escala: (5) Muito urgente; (4) Urgente; (3) Médio; (2) Pouco urgente; (1) Sem urgência. 
Sempre que o hospital recebe um novo coração o sistema é consultado
para obter o próximo paciente que deverá ser operado. O sistema informa o nome e o
telefone do paciente. Também a qualquer momento é possível visualizar o tamanho da fila
de espera. Observação: Utilize a biblioteca de fila.
/**************************************************************************************/

// Variáveis e Objetos Globais
TClasseFila fila;

//-------------------------------------------------------------
char menu()
{
	system("cls");
	
	printf("\n\nSISTEMA DE GERENCIAMENTO DE TRANSPLANTES DE CORACAO\n\n");
	
	
	printf("\n1 - Cadastrar Paciente");
	printf("\n2 - Retirar Paciente da Fila para Transplante");
	printf("\n3 - Consultar o Tamanho da Fila de Espera");
	printf("\n4 - Imprimir Fila de Espera");
	printf("\n5 - Imprimir Paciente pelo nome");
	
	printf("\n\nEsc para sair");
	
	printf("\n\nOpcao: ");
	
	char opc = getche();
	
	return opc;
	
} // menu()

//-------------------------------------------------------------
void cadastrar_paciente()
{
	TClasseFila::TInfoFila aux;	
	
	system("cls");
	printf("\n\nSISTEMA DE GERENCIAMENTO DE TRANSPLANTES DE CORACAO");
	printf("\nCadastro de Pacientes\n\n");
	
	fflush(stdin); // resolve o problema do buffer de entrada de \n em strings	
	cout << "Informe o Nome do Paciente.......: ";
	getline(cin, aux.nome);
	
	
	fflush(stdin); // resolve o problema do buffer de entrada de \n em strings	
	cout << "Informe o Telefone do Paciente...: ";
	getline(cin, aux.telefone);

	cout << "\n\nGraus de Urgencia: (5) Muito urgente; (4) Urgente; (3) Medio; (2) Pouco urgente; (1) Sem urgencia";
	cout << "\nInforme o Grau de Urgencia.......: ";
	
	cin >> aux.grau;
		
	fila.Enqueue(aux);
	
} // cadastrar_paciente()

//-------------------------------------------------------------
void retirar_paciente()
{
	TClasseFila::TInfoFila aux;	
	
	system("cls");
	printf("\n\nSISTEMA DE GERENCIAMENTO DE TRANSPLANTES DE CORACAO");
	printf("\nRetirada de Paciente para Transplante\n\n");
	
	if( fila.Q_IsEmpty() )
	{
		printf("\n\nA FILA ESTA VAZIA !!! ");
		getch();
		
		return; // interrompe o metodo
	}
	
	printf("\n\nDeseja REALMENTE retirar o 1o Paciente da Fila ???? (s/n)...: ");
	char opc = getche();
	
	if( opc == 's' )
	{
		aux = fila.Dequeue();

		printf("\n\nO PACIENTE A RECEBER O TRANSPLANTE É: \n\n")		;
		cout << "\nNome...............: " << aux.nome;
		cout << "\nTelefone...........: " << aux.telefone;
		printf("\nGrau de Urgencia...: %d", aux.grau);
		
		printf("\n\nPressione algo para voltar...");
		getch();
		
		
	} // se confirmou a retirada
	
	
	
} // retirar_paciente()

//-------------------------------------------------------------
void consultar_tam_fila()
{
	system("cls");
	printf("\n\nSISTEMA DE GERENCIAMENTO DE TRANSPLANTES DE CORACAO");
	printf("\nConsulta do Tamanho da Fila\n\n");
	
	printf("\n\nO número de pacientes esperando um transplante é.....: %d", fila.GetSize() );
	
	printf("\n\nPressione algo para voltar...");
	getch();

} // consultar_tam_fila()

//-------------------------------------------------------------
void imprimir_fila()
{
	system("cls");
	printf("\n\nSISTEMA DE GERENCIAMENTO DE TRANSPLANTES DE CORACAO");
	printf("\nListagem de Pacientes\n\n");
	
	fila.PrintFila();
	
	cout << "\n\nPressione algo para voltar...";
	getch();
	
} // imprimir_fila()

void ConsultaPeloNome(){
	system("cls");
	printf("\n\nSISTEMA DE GERENCIAMENTO DE TRANSPLANTES DE CORACAO");
	printf("\nConsulta de Pacientes\n\n");
	
	cout<<"Informe o nome: ";
	string nome;
	cin>>nome;
	
	fila.ConsultaNome(nome);
	
	cout<"\n\n";
	system("PAUSE");
}

//-------------------------------------------------------------
int main(int argc, char** argv) {

	setlocale(LC_ALL, "");
	
	char opc = menu();
	
	while( opc != 27 /* Esc */ )
	{
		switch( opc )
		{
			case '1':
				cadastrar_paciente();
				break;
				
			case '2':
				retirar_paciente();
				break;
			
			case '3':
				consultar_tam_fila();
				break;
				
			case '4':
				imprimir_fila();
				break;
				
			case '5':
				ConsultaPeloNome();
				break;
			
		} // switch()
		
		opc = menu();
			
	} // while menu()
	
	
	
/*	
	for(int i=0; i<2; i++)
	{
		cout << "Informe o nome do paciente " << i << ": ";
		gets(aux.nome);
		
		fila.Enqueue(aux);
		
	} // for
	
	fila.PrintFila();
*/	
	
		
	/*
	printf("\n=======================================");
	printf("\n=== FILA DINAMICA - EXERCICIO 1 ======\n\n");
	
	for(int i=0; i < 5; i++ )
	{
		cout << "Informe um valor para a Fila: ";
		cin >> aux;
		
		fila.Enqueue(aux);		
	}
	
	
	cout << "\n\nO conteudo da fila eh: \n\n";
	
	//fila.PrintFila();
	
	
	TClasseFila::TNoFila *no_auxiliar;
	
	
	no_auxiliar = fila.GetComeco();
	
	while( no_auxiliar != NULL )
	{		 
		cout << no_auxiliar->dado << "\t";
		
		no_auxiliar = no_auxiliar->prox;
	}
	*/
	
	printf("\n\n");
	return 0;
	
} // main()
