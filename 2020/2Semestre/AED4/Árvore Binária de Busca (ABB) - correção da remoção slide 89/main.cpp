#include <iostream>
#include "TABB.h"
#include <conio.h>

using namespace std;

TABB arvore;

//---------------------------------------------------------------------------------
void incluir()
{
	system("cls");	
	printf("\n\n======================================================================================");
	printf("\nARVORE BINARIA DE BUSCA : INCLUSAO DE ELEMENTOS");
	printf("\n======================================================================================\n");
	
	TABB::TInfo n;
	
	printf("\n\nInforme o elemento a ser inserido: ");
	cin >> n;
	
	if( arvore.LocalizarNo( n ) == NULL )
	{
		arvore.InserirNo( n );
		cout << "\n\nElemento incluido com sucesso !";
	}
	else
	{
		cout << "\n\nNAO FOI POSSIVEL A INCLUSAO, pois este elemento ja se encontra na arvore!";
	}
	
	getch();
	
} // incluir

//---------------------------------------------------------------------------------
void remover()
{
	system("cls");	
	printf("\n\n======================================================================================");
	printf("\nARVORE BINARIA DE BUSCA : REMOCAO DE ELEMENTOS");
	printf("\n======================================================================================\n");
	
	TABB::TInfo n;
	
	printf("\n\nInforme o elemento a ser REMOVIDO: ");
	cin >> n;
	
	if( !arvore.Remover( n ) )
	{
		cout << "\n\nNao foi possivel remover o elemento, pois ele nao existe na arvore !";
	}
	else
	{
		cout << "\n\nElemento removido com sucesso !";
	}
	
	getch();
	
} // remover

//---------------------------------------------------------------------------------
void alterar()
{
	system("cls");	
	printf("\n\n======================================================================================");
	printf("\nARVORE BINARIA DE BUSCA : ALTERACAO DE VALORES DE ELEMENTOS");
	printf("\n======================================================================================\n");
	
	TABB::TInfo n1, n2;
	
	printf("\n\nInforme o elemento a ser ALTERADO: ");
	cin >> n1;
	
	if( arvore.LocalizarNo( n1 ) != NULL  )
	{
		
		printf("\n\nInforme o novo valor : ");
		cin >> n2;
		
		if( arvore.LocalizarNo( n2 ) == NULL  )
		{
			arvore.Remover(n1);
			arvore.InserirNo(n2);
			
			cout << "\n\nAlteracao realizada com sucesso !";
			
		} // se n2 nao existir
		else
		{
			cout << "\n\nNao foi possivel ALTERAR, pois o NOVO valor ja se encontra na arvore !";
		}
		
		
	} // se n1 existir
	else
	{
		cout << "\n\nO elemento informado nao existe na arvore...!";
	}
	
	getch();
	
} // alterar

//---------------------------------------------------------------------------------
void destruir()
{
	system("cls");	
	printf("\n\n======================================================================================");
	printf("\nARVORE BINARIA DE BUSCA : CORTE DE ARVORE (DESTRUICAO DA ARVORE)");
	printf("\n======================================================================================\n");
	
	if( arvore.IsEmpty() )
	{
		printf("\n\nEsta arvore ja esta vazia !!!");
		getch();
		return; // interrompe o método neste ponto
	}
		
	char opc;
	
	printf("\n\nTODOS OS ELEMENTOS DESTA ARVORE SERAO DESTRUIDOS");
	printf("\n\nDeseja realmente DESTRUIR esta arvore (s/n): ");
	opc = getche();
	
	if( opc == 's' )
	{
		while( !arvore.IsEmpty() ) arvore.Remover( arvore.Raiz->dado );
		
		cout << "\n\nArvore destruida com sucesso !";
		getch();
		
	} // se confirmou a destruição
	
	
} // destruir

//---------------------------------------------------------------------------------
void imprimir()
{
	system("cls");	
	printf("\n\n======================================================================================");
	printf("\nARVORE BINARIA DE BUSCA : IMPRESSAO DA ARVORE");
	printf("\n======================================================================================\n");
	
	arvore.print_elementos_da_arvore();

	
	printf("\n\nPressione algo para voltar ao menu...");
	getch();
	
} // imprimir

//---------------------------------------------------------------------------------
void pesquisar()
{
	system("cls");	
	printf("\n\n======================================================================================");
	printf("\nARVORE BINARIA DE BUSCA : PESQUISA DE ELEMENTOS");
	printf("\n======================================================================================\n");
	
	TABB::TInfo n;
	
	printf("\n\nInforme o elemento a ser Pesquisado: ");
	cin >> n;
	
	if( arvore.LocalizarNo( n ) == NULL )
	{
		cout << "\n\nEste elemento nao existe na arvore !";
	}
	else
	{
		cout << "\n\nElemento ENCONTRADO com sucesso !";
	}
	
	getch();

} // pesquisar

void Inserir_Data(){
	system("cls");	
	printf("\n\n======================================================================================");
	printf("\nARVORE BINARIA DE BUSCA : INCLUSAO DE DATA");
	printf("\n======================================================================================\n");
		
	cout<<"\n\n27/04/2000"; //27042000
	arvore.InserirNo( 2 );
	arvore.InserirNo( 7 );
	arvore.InserirNo( 0 );
	arvore.InserirNo( 4 );
	arvore.InserirNo( 2 );
	arvore.InserirNo( 0 );
	arvore.InserirNo( 0 );
	arvore.InserirNo( 0 );
	cout << "\n\nElementos incluidos com sucesso !";
	cout << "\n\n\nAperte para ver a arvore.....";
	getch();
}

void Total_Nos(){
	system("cls");	
	printf("\n\n======================================================================================");
	printf("\nARVORE BINARIA DE BUSCA : TOTAL DE NOS");
	printf("\n======================================================================================\n");
	
	TABB::TNo* raiz = arvore.GetRaiz();
	int x = arvore.TotalNos(raiz);
	cout<<"\nO total de nos da arvore: "<<x;
	cout<<"\n\nAperte algo para voltar ao menu...";
	getche();
	
}

//---------------------------------------------------------------------------------
char menu()
{
	system("cls");	
	printf("\n\n======================================================================================");
	printf("\nARVORE BINARIA DE BUSCA : MENU PRINCIPAL");
	printf("\n======================================================================================\n");
	
	printf("\n1 : Incluir elemento");
	printf("\n2 : Remover elemento");
	printf("\n3 : Alterar elemento");
	printf("\n4 : Destruir a arvore");
	printf("\n5 : Imprimir a arvore");
	printf("\n6 : Pesquisar");
	printf("\n7 : Inserir data nascimento");
	printf("\n8 : Total de nos");
	printf("\nEsc para sair");
	
	cout << "\n\nDigite sua opcao: ";
	char opc = getche();
	
	return opc;
}

//---------------------------------------------------------------------------------
int main(int argc, char** argv) {
	
	char opc = menu();
	
	while( opc != 27 )
	{
		switch( opc )
		{
			case '1':
				incluir();
				break;
			
			case '2':
				remover();
				break;

			case '3':
				alterar();
				break;
			
			case '4':
				destruir();
				break;
			
			case '5':
				imprimir();
				break;
			
			case '6':
				pesquisar();
				break;
			case '7':
				Inserir_Data();
				imprimir();
				break;
			case '8':
				Total_Nos();
				break;
			
		} // switch()
		
		opc = menu();
		
	} // while menu
	
		
/* Testes --------------------------------------------------------------------------------------------	


	TABB arvore;
	TABB::TNo* no;
	int n;
	
	
	arvore.InserirNo( 15 );
	arvore.InserirNo( 10 );
	arvore.InserirNo( 20 );
	arvore.InserirNo( 6  );
	arvore.InserirNo( 12 );
	arvore.InserirNo( 5  );
	arvore.InserirNo( 9  );
	arvore.InserirNo( 8  );
	
	arvore.print_elementos_da_arvore();
	
	if( arvore.LocalizarNo(99) != NULL )
	{
		cout << "Valor encontrado!";
	}
	else
	{
		cout << "Valor nao encontrado!";
	}


	TABB arvore;
	TABB::TNo* no;
	int n;
	
	//gotoxy(15,15);	printf("Teste");
	
	arvore.InserirNo( arvore.Raiz, 15 );
	arvore.InserirNo( arvore.Raiz, 10 );
	arvore.InserirNo( arvore.Raiz, 20 );
	arvore.InserirNo( arvore.Raiz, 6  );
	arvore.InserirNo( arvore.Raiz, 12 );
	arvore.InserirNo( arvore.Raiz, 5  );
	arvore.InserirNo( arvore.Raiz, 9  );
	arvore.InserirNo( arvore.Raiz, 8  );
	
	arvore.InserirNo( arvore.Raiz, 18 );
	arvore.InserirNo( arvore.Raiz, 25 );
	arvore.InserirNo( arvore.Raiz, 16 );
	arvore.InserirNo( arvore.Raiz, 19 );
	arvore.InserirNo( arvore.Raiz, 17 );
	arvore.InserirNo( arvore.Raiz, 30 );
	arvore.InserirNo( arvore.Raiz, 27 );
	
	arvore.InserirNo( arvore.Raiz, 13 );
	arvore.InserirNo( arvore.Raiz, 28 );
	arvore.InserirNo( arvore.Raiz, 24 );
	
//	printf("\n\nAltura da arvore: %d\n\n", arvore.Altura(arvore.Raiz) );		
//	printf("\n\nTotal de nos: %d\n\n", arvore.TotalNos(arvore.Raiz) );	
//	n = 17;
//	printf("\n\Nivel do no %d: %d\n\n", n, arvore.Nivel(n) );	
//	return 0;
	
	
//	arvore.print_arvore(arvore.Raiz, 80, 0);
//	return 0;
	
	arvore.print_elementos_da_arvore( arvore.GetRaiz() );
		
	no = arvore.Maior( 15 );	
	if( no != NULL ) cout << "\n\nO maior elemento da arvore eh: " << no->dado;
	
	
	no = arvore.Menor( 15 );
	if( no != NULL ) cout << "\n\nO menor elemento da arvore eh: " << no->dado;
	
	no = arvore.Maior( 10 );	
	if( no != NULL ) cout << "\n\nO maior elemento da subarvore 10 eh: " << no->dado;
	
	no = arvore.Menor( 20 );
	if( no != NULL ) cout << "\n\nO menor elemento da subarvore 20 eh: " << no->dado;
	
	no = arvore.Maior( 18 );	
	if( no != NULL ) cout << "\n\nO maior elemento da subarvore 18 eh: " << no->dado;
	
	no = arvore.Menor( 25 );
	if( no != NULL ) cout << "\n\nO menor elemento da subarvore 25 eh: " << no->dado;
	
	//--------------------------------------------------------------------
	n=20;	
	if( arvore.Remover(n) )
	{
		cout << "\n\nApos remecao do no " << n << "\n\n";	
		arvore.print_elementos_da_arvore( arvore.GetRaiz() );
	}
	else
	{
		cout << "\n\nNao foi possivel remover o elemento " << n << "\n\n";
	}

	/* --------------------------------------------------------------------------------------- 
	arvore.InserirNo( arvore.Raiz, 8);
	
	arvore.InserirNo( arvore.Raiz, 3);
	arvore.InserirNo( arvore.Raiz, 11);

	arvore.InserirNo( arvore.Raiz, 1);
	arvore.InserirNo( arvore.Raiz, 5);
	arvore.InserirNo( arvore.Raiz, 2);
	
	arvore.InserirNo( arvore.Raiz, 9);
	arvore.InserirNo( arvore.Raiz, 14);
	
	arvore.InserirNo( arvore.Raiz, 10);
	
	arvore.print_elementos_da_arvore( arvore.GetRaiz() );
	
	int n=10;
	
	if( arvore.Remover(n) )
	{
		cout << "\n\nApos remecao do no " << n << "\n\n";	
		arvore.print_elementos_da_arvore( arvore.GetRaiz() );
	}
	else
	{
		cout << "Nao foi possivel remover o elemento " << n << "\n\n";
	}

	
//	int pesquisa;	
//	cout << "\n\nInfome um numero a pesquisa: ";
//	cin >> pesquisa;
//	
//	TABB::TNo* aux;
//	
//	aux = arvore.LocalizarNo( arvore.Raiz, pesquisa);
//	
//	if( aux != NULL )
//	{
//		cout << "\n\nVALOR ENCONTRADO !!!\n\n";
//	}
//	else
//	{
//		cout << "\n\nValor NAO encontrado !!!\n\n";
//	}

	cout << "\n\n";
	
	return 0;
	/* --------------------------------------------------------------------------------------- */	
	
} // main()
