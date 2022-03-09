#include <iostream>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int const n = 10;
	
	float A[n], B[n], C[n];
	
	for(int i=0; i<n; i++)
	{
		A[i] = i * sin(i);
		B[i] = A[i] - cos(i*i);
	}
	
	/*for(int i=0; i<n; i++){
		C[i] = A[i]  + B[i];
	}*/
	
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int 
	}
	
	for(int i=0; i<n; i++)
	{
		printf("\nA[%d] + B[%d] = %10.3f", i, i, C[i]);
	}
	
	return 0;
}
