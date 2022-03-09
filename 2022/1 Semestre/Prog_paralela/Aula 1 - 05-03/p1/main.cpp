#include <iostream>
#include <omp.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	printf("\n\nOpenMP : Hello, World!!!\n");
	
	int n_threads = 0;
	
	n_threads = omp_get_max_threads();
	
	
	printf("\nNumero de Threads (nucleos): %d \n\n ", n_threads);
	
	#pragma omp parallel
	{
		int id_thread = omp_get_thread_num();
		printf("\n ID trhd %d\n", id_thread);
		
	}
	return 0;
}
