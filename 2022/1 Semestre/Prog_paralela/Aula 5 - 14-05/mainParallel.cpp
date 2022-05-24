#include <iostream>
#include <omp.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

long double Fibonacci(int n){
	
	long double i, j;
	
	if(n<1) return 0;
	
	if(n == 1 || n == 2){
		return 1;
	}
	else if(n<30){
		return Fibonacci(n-1) + Fibonacci(n-2);
	}
	else{
		#pragma omp task shared(i)
		{
			i = Fibonacci(n-1);
		}
		
		#pragma omp task shared(j)
		{
			j = Fibonacci(n-2);
		}
		
		#pragma omp taskwait
		{
			return i + j;
		}
	}
}

int main(int argc, char** argv) {
	
	double t0, tf;
	int n;
	long double fibo;
	
	cout<< "Informe qual elemento da sequencia de Fibonacci deseja: ";
	cin >> n;
	
	t0 = omp_get_wtime();
	
	#pragma omp parallel
	{
		#pragma omp single
		{
			fibo = Fibonacci(n);
		}	
	}
	
	tf = omp_get_wtime();
	
	printf("\n\nA sequencia %d de Fibonacci eh %.0Lf", n, fibo);
	
	printf("\n\nTempo: %.2f segundos", tf-t0);
	
	printf("\n\n\n");
	
	return 0;
}
