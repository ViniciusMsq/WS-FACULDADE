#include <iostream>
#include "TABB.h"
#include "funcoes.h"

using namespace std;

//---------------------------------------------------------------------------------
int main(int argc, char** argv) {
	
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
	/* --------------------------------------------------------------------------------------- */
	
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
	
} // main()
