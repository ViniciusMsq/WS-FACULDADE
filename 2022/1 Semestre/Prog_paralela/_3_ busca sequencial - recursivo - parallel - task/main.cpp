#include <iostream>
#include <omp.h>

using namespace std;

int BuscaSeq( int *vetor, int pesquisa, int i, int n)
{
	int aux;
	
	if( i < n )
	{
	
		if( vetor[i] == pesquisa ) 
		{
			return i;		
		}
		else
		{
			#pragma omp task shared(aux) 
			{
				aux = BuscaSeq(vetor, pesquisa, i+1, n);
			}
				
			#pragma omp taskwait // deve-se esperar até que todas as tarefas sejam concluídas 				
				return aux;
			
		}		
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
	
	
	printf("\n\nTOTAL DE NUCLEOS: %d Versao do OpenMP %d", omp_get_max_threads(), _OPENMP);
	
	
	printf("\n\nInforme o valor a ser pesquisado: ");
	cin >> pesquisa;
	
	i = 13; // teste
	
	#pragma omp parallel
	{
		#pragma omp single
		{
			i = BuscaSeq(vetor, pesquisa, 0, n);
		}
	}
	
	
	if( i != -1 )
	{
		printf("\n\nValor %d encontrado na posicao %d", pesquisa, i);
	}
	else
	{
		printf("\n\nValor %d NAO encontrado!", pesquisa);
	}
	
	
	
	/*
	#pragma omp parallel num_threads(4)
	{
		int i=0;
		
		#pragma omp single
		{
			
			while( i < n && !achou )
			{
				#pragma omp task 
				{
					achou = pesq == vetor[i];
					printf("%d", omp_get_thread_num());
				} 

				if( !achou ) i++;	

			} // while
			
		} // single

		
	} // join
	
		
	if( achou )
	{
		printf("\n\nValor %d encontrado na posicao %i", pesq, i);
	}
	else
	{
		printf("\n\nValor %d NAO encontrado!", pesq);
	}
	*/
	
	printf("\n\n\n");
	
	
	return 0;
	
} // main()
