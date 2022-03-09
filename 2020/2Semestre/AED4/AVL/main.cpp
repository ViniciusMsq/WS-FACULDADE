#include <iostream>
#include "TABB.h"
#include <conio.h>
#include <math.h>
#include <graphics.h>

using namespace std;

TABB arvore;

//---------------------------------------------------------------------------------
void grafico()
{
	//Desenhando Arvore
	initwindow(arvore.Grafico_width, arvore.Grafico_height, "AVL Grafica");
	printf("\n1 - teste");
	arvore.Grafico_gerar_coordenadas(arvore.Raiz, arvore.Grafico_width/2 /* coord. x da raiz*/);
	printf("\n2 - teste");
	arvore.Grafico_print_ponterios(arvore.Raiz, NULL);
	printf("\n3 - teste");
	arvore.Grafico_print_nos(arvore.Raiz);
	printf("\n4 - teste");
	arvore.Grafico_print_textos(arvore.Raiz); 
	printf("\n5 - teste");
	
	getch();
	
	closegraph();
	
} // grafico

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

	
	printf("\n\nPressione algo para continuar...");
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
	printf("\n7 : Grafico");
	printf("\nEsc para sair");
	
	cout << "\n\nDigite sua opcao: ";
	char opc = getche();
	
	return opc;
}

//---------------------------------------------------------------------------------
int main(int argc, char** argv) {
	
	setbkcolor( WHITE );
	setcolor( BLACK );
	
	initwindow(arvore.Grafico_width, arvore.Grafico_height, "AVL Grafica");
	
	setbkcolor( WHITE ); setcolor( BLACK );
	line(1, 1, arvore.Grafico_width, 1 );
	
	setbkcolor( WHITE ); setcolor( BLACK );
	fillellipse(arvore.Grafico_width/2, arvore.Grafico_height/2 - 100,100,100);
	
	setbkcolor( WHITE ); setcolor( BLACK );
	outtextxy(arvore.Grafico_width/2 - 10, arvore.Grafico_height/2 - 100, "AVL");
	
	delay(1000);
	
	
	

	
	closegraph(); // fim da inicialização do ambiente grafico.
	for(int i=1; i<=63; i++) arvore.InserirNo(i);
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
				grafico();
				break;
			
		} // switch()
		
		opc = menu();
		
	} // while menu
	
} // main()
