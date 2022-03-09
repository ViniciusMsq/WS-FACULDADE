#include <iostream>
#include <conio.h>

using namespace std;

// N�mero M�ximo de elementos da lista
int Max = 10;

// Lista propriamente dita
int Lista[10];

// n� de elementos da lista
int n = 0; 

//--------------------------------------------------------
// Inserir um elemento ap�s o �ltimo elemento
bool Inserir(int x)
{	
	if( n < Max )
	{
		n++;
		Lista[n-1] = x;
		return true;
	}
	else return false;

} // Inserir()

//--------------------------------------------------------
// Inserir um elemento em uma determinada posi��o da lista
bool Inserir(int x, int k)
{	
	// restri��es
	if( n == Max )
	{
		printf("\nA lista j� est� no seu limite !...");
		return false;
	}
	else
	if( k < 1 || k > n )
	{
		printf("\nA posi��o a inserir est� fora do limite da lista !...");
		return false;
	}
	else
	{
		n++;		
		
		for( int i = n-1; i > k-1; i-- )
		{
			Lista[i] = Lista[i-1];
		}		
		Lista[k-1] = x;
		
		return true;
	}
} // Inserir(int x, int k)

//--------------------------------------------------------
// Remove o k-�simo elemento da lista
bool Remover(int k)
{	
	// restri��es
	if( n == 0 )
	{
		printf("\nA lista j� est� vazia !...");
		return false;
	}
	else
	if( k < 1 || k > n )
	{
		printf("\nA posi��o a remover est� fora do limite da lista !...");
		return false;
	}
	else
	{
		for(int i = k-1; i < n-1; i++)
		{
			Lista[i] = Lista[i+1];
		}
		
		n--;		
		return true;
	}
} // Remover

//--------------------------------------------------------
// Altera o valor do k-�simo elemento da lista
bool Alterar(int valor_novo, int k)
{	


} // Alterar

//--------------------------------------------------------
// Verifica se um determado valor existe na lista
int Pesquisar(int ch)
{	
//se encontrar o valor ch vai retornar a posi��o do vetor deste valor
// senao vai retornar -1

	int i = 0;
	bool achou = false;
	
	while(i<n && !achou){
		if (Lista[i] == ch){
			achou = true;
		}
		else{
			i++;
		}
		
		if(achou){
			return i;
		}else{
			return -1;
		}
	}
} // Pesquisar

//--------------------------------------------------------
// Limpa a lista
bool Limpar()
{	
	if(n==0){
		cout<<"\n\nA lista ja est� vazia..."
		getch();
		return false;
	}
	while (n>0) Remover(1);
	return true;
} // Limpar

//--------------------------------------------------------
// Listar todos elementos da lista
void Listar()
{	
	if( n == 0 )
	{
		printf("\nA Lista esta vazia...");		
	}
	else
	{
		printf("\nO conte�do da Lista �:\n");
		for(int i=0; i<n; i++)
		{
			printf("\nElmento %d : %5d", i+1, Lista[i]);
		}
	}

} // Listar

//--------------------------------------------------------
int Menu()
{
	system("cls");
	printf("\n\nLISTA SEQUENCIAL EST�TICA\n");
	
	printf("\n 1 - Incluir um Elemento ap�s o �ltimo");
	printf("\n 2 - Incluir um Elemento em uma determinada posi��o");
	printf("\n 3 - Remover um Elemento");
	printf("\n 4 - Alterar um Elemento");
	printf("\n 5 - Pesquisar");
	printf("\n 6 - Listar");
	printf("\n 7 - Limpar");
	printf("\n99 - Sair");
	
	int opc;	
	printf("\n\n\nOp��o...: ");
	scanf("%d", &opc);
	
	return opc;
	
	
} // Menu()


//--------------------------------------------------------
int main(int argc, char** argv) {	
    // Alterando o charset para o padr�o do sistema operacional, caracteres e formato de n�meros
    setlocale(LC_ALL,""); 	
	int x, k;
	int opc = 0;	
	while( opc != 99 )
	{				
		opc = Menu();		
		if( opc == 1 ) // inserir no final
		{
			printf("\n\nInforme um elemento a ser inserido na lista: ");
			scanf("%d", &x);
			
			if( !Inserir( x ) )
			{
				printf("\nN�o foi poss�vel inserir um elemento na lista!");
			}
		}
		else
		if( opc == 2 ) // Incluir na k-�sima posi��o
		{						
			printf("\n\nInforme um elemento a ser inserido na lista e sua respectiva posi��o: ");
			scanf("%d %d", &x, &k);			
			Inserir(x, k);			
		}
		else
		if( opc == 3 ) // Excluir a k-�sima posi��o
		{						
			printf("\n\nInforme a posi��o a remover: ");
			scanf("%d", &k);			
			Remover(k);			
		}
		else
		if( opc == 6 ) // listar
		{
			Listar();
			getch();
		}
		else
		if(opc == 7){
			char resposta;
			
			cout<<"Deseja realmente limpar a lista ? (s/n)";
			resposta = getche();
			
			if(resposta == 's'){
				Limpar();
			}
		}					
	} // while...	 

	printf("\n\n\n");	
	return 0;
}














