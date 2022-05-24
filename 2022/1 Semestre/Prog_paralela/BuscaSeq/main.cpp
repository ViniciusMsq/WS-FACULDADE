#include <iostream>
#include <omp.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int BuscaSeq(long int *vetor, long int pesquisa, long int i, long int n){
	
	if( i < n){
		
		if(vetor[i] == pesquisa)return i;
		
		return BuscaSeq(vetor, pesquisa, i+1, n);
	}
	else{
		return -1;
	}
}


int main(int argc, char** argv) {
	
	double t0, tf;
	long int n = 100000, i;
	long int vetor[100000];
	long int pesquisa;
	
	for(long int j = 0; j<100000; j++){
		vetor[j] = j+1;
	}
	
	printf("\n\nTotal de nucleos: %d", omp_get_max_threads());
	
	printf("\n\nInforme o valor a ser pesquisa: ");
	cin >> pesquisa;
	
	t0 = omp_get_wtime();
	
	i = BuscaSeq(vetor, pesquisa, 0, n);
	
	tf = omp_get_wtime();
	
	if( i != -1)
		printf("\n\nValor %d encontrado na posicao %i", pesquisa, i);
	else
		printf("\n\nValor %d nao encontrado!", pesquisa);
		
	
	printf("\n\nTempo: %.2f segundos", tf-t0);
	
	printf("\n\n\n");
	
	return 0;
}
