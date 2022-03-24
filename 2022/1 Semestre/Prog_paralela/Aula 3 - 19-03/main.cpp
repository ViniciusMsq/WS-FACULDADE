#include <iostream>
#include <omp.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	const int n = 10;
	int A[n];
	int B[n];
	int C[n];
	
	#pragma omp parallel
	{
		#pragma omp sections nowait
		{
			#pragma omp section
			{
				for(int i=0; i<n; i++){
					printf("\nSection A: %d \n", omp_get_thread_num());
					A[i] = i + 10;
				}
			}
			
			#pragma omp section
			{
				for(int i=0; i<n; i++){
					printf("\nSection B: %d\n", omp_get_thread_num());
					B[i] = i * 8;
				}
			}
		}
		
		#pragma omp single
		{
			for(int i = 0; i<n; i++){
				printf("\nSingle: %d\n", omp_get_thread_num());
				C[i]= i + 158;
			}
		}
	}
	
	return 0;
}
