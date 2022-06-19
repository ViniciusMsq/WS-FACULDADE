#include <iostream>
#include <omp.h>

using namespace std;

//------------------------------------------------------------------
int BuscaSeq( int *vetor, int pesquisa, int i, int n)
{		
	if( i < n )
	{
		if( vetor[i] == pesquisa ) return i;
		
		return BuscaSeq(vetor, pesquisa, i+1, n);
	}
	else
	{
		return -1;
	}	
	
} // BuscaSeq

//------------------------------------------------------------------
int main(int argc, char** argv) {
	
	int n = 10, i;
	int vetor[] = {5, -1, 8, 109, 1093, 14, 25, -87, 4, 46};
	int pesquisa;
		
	printf("\n\nTOTAL DE NECLEOS: %d", omp_get_max_threads());
	
	printf("\n\nInforme o valor a ser pesquisado: ");
	cin >> pesquisa;	
	
	i = BuscaSeq(vetor, pesquisa, 0, n);
	
	if( i != -1 )
		printf("\n\nValor %d encontrado na posicao %i", pesquisa, i);
	else
		printf("\n\nValor %d NAO encontrado!", pesquisa);
		
	printf("\n\n\n");
	return 0;
	
} // main()




