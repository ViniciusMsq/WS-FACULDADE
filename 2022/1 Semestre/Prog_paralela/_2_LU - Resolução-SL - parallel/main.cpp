#include <iostream>
#include <stdlib.h>  /* malloc, free, rand */
#include <time.h>
#include <omp.h>
#include <conio.h>

using namespace std;

//=======================================================================
// Número inteiro aleatório entre i e n
int RandI(int i, int n) 
{
   return (rand() % n) + i;
}

//=======================================================================
// Número Float aleatório entre 0 e 1
float RandF() 
{
	return (float)rand() / (float)RAND_MAX; // ORIGINAL
}

//=======================================================================
// Número Float aleatório entre i e j
float RandF(float i, float j)  
{
	return i + RandF() * (j - i); 
}

//================================================================================================================================================================
float** AlocarMatrizFloat(int Linhas,int Colunas)
{  
  int i,j; 
 
  //Aloca uma Matriz de Ponteiros
  float **m = (float**)malloc(Linhas * sizeof(float*)); 
 
  //Percorre as linhas do Vetor de Ponteiros
  for (i = 0; i < Linhas; i++)
  { 
       //Aloca um Vetor de Float  para cada posição do Vetor de Ponteiros.
       m[i] = (float*) malloc(Colunas * sizeof(float)); 
       
       //Percorre o Vetor de Inteiros atual.
       for (j = 0; j < Colunas; j++)
       { 
            m[i][j] = 0; //Inicializa com 0.
       }
  }
  return m; //Retorna o Ponteiro para a Matriz Alocada
  
} // AlocarMatrizFloat

//================================================================================================================================================================
float* AlocarVetorFloat(int n)
{  
   int i; 

   float *v = (float*) malloc(n * sizeof(float)); 
   
   //Percorre o Vetor de Inteiros atual.
   for (i = 0; i < n; i++)
   { 
        v[i] = 0; //Inicializa com 0.
   }
 
  return v; 
  
} // AlocarVetorFloat

//================================================================================================================================================================
double** AlocarMatrizdouble(int Linhas,int Colunas)
{  
  int i,j; 
 
  //Aloca uma Matriz de Ponteiros
  double **m = (double**)malloc(Linhas * sizeof(double*)); 
 
  //Percorre as linhas do Vetor de Ponteiros
  for (i = 0; i < Linhas; i++)
  { 
       //Aloca um Vetor de double  para cada posição do Vetor de Ponteiros.
       m[i] = (double*) malloc(Colunas * sizeof(double)); 
       
       //Percorre o Vetor de Inteiros atual.
       for (j = 0; j < Colunas; j++)
       { 
            m[i][j] = 0; //Inicializa com 0.
       }
  }
  return m; //Retorna o Ponteiro para a Matriz Alocada
  
} // AlocarMatrizdouble

//================================================================================================================================================================
double* AlocarVetordouble(int n)
{  
   int i; 

   double *v = (double*) malloc(n * sizeof(double)); 
   
   //Percorre o Vetor de Inteiros atual.
   for (i = 0; i < n; i++)
   { 
        v[i] = 0; //Inicializa com 0.
   }
 
  return v; 
  
} // AlocarVetordouble


//=======================================================================
int main(int argc, char** argv) {
	
	
    setlocale(LC_ALL,""); //Alterando o charset para o padrão do sistema operacional //printf ("Localidade corrente: %s\n", setlocale(LC_ALL,NULL) );

	// definindo a semente para os números aleatórios
	//unsigned long int semente = (unsigned)time(0); // semente variada 	
	unsigned long int semente = 0; // semente fixa
	
	// recomenda-se utilizar apenas uma vez na execução do programa e antes de utilizar a função rand()
	srand( semente );  
	
	clock_t t0, tf;
	double tempo;
	
	long int i, j, k;
	double numerador, denominador, soma;

	double **A, **L, **U, *b, *y, *x;	

	/************************************************************
	int n = 4;
		
	A = AlocarMatrizFloat(n, n);
	L = AlocarMatrizFloat(n, n);
	U = AlocarMatrizFloat(n, n);
	
	b = AlocarVetorFloat(n);
	y = AlocarVetorFloat(n);
	x = AlocarVetorFloat(n);	
	
	A[0][0] =  3;
	A[0][1] =  2;
	A[0][2] =  0;
	A[0][3] =  1;
	
	A[1][0] =  9;
	A[1][1] =  8;
	A[1][2] = -3;
	A[1][3] =  4;
	
	A[2][0] = -6;
	A[2][1] =  4;
	A[2][2] = -8;
	A[2][3] =  0;

	A[3][0] =  3;
	A[3][1] = -8;
	A[3][2] =  3;
	A[3][3] = -8;
	
	b[0] =   3;
	b[1] =   6;
	b[2] = -16 ;
	b[3] =  22;
	/****************************************************************************/

	
	/*****************************************************************************
	int n = 3;
		
	A = AlocarMatrizFloat(n, n);
	L = AlocarMatrizFloat(n, n);
	U = AlocarMatrizFloat(n, n);
	
	b = AlocarVetorFloat(n);
	y = AlocarVetorFloat(n);
	x = AlocarVetorFloat(n);	
	
	A[0][0] =  2;
	A[0][1] =  3;
	A[0][2] = -1;
	
	A[1][0] =  4;
	A[1][1] =  4;
	A[1][2] = -3;
	
	A[2][0] =  2;
	A[2][1] = -3;
	A[2][2] =  1;
	
	b[0] =  5;
	b[1] =  3;
	b[2] = -1;
	/*****************************************************************************/

	/***GERANDO UM SISTEMA *******************************************************/ 
	printf("\n\nGerando o Sistema...\n\n");

	int n = 3000;
		
	A = AlocarMatrizdouble(n, n);
	L = AlocarMatrizdouble(n, n);
	U = AlocarMatrizdouble(n, n);
	
	b = AlocarVetordouble(n);
	y = AlocarVetordouble(n);
	x = AlocarVetordouble(n);
	
	for(i=0; i<n; i++)
	{
		soma=0;
		for(j=0; j<n; j++)
		{
			A[i][j] = RandI(1,20);
			soma = soma + A[i][j]; 
		}
		b[i] = soma;
	}
	/*****************************************************************************/



	printf("\n\nCalculando as Matrizes L e U...\n\n");

	t0 = clock();
	
	// Gerando as matrizes L e U COM paralelismo ----------------------------------------------

	//--- inicializando as matrizes L e U
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++) 
		{
			U[i][j] = A[i][j];
			
			if( i == j ) // diagonal principal
				L[i][j] = 1;
			else
			if( j > i ) // acima da diagonal principal
				L[i][j] = 0;
			//else              
				// i < j : abaixo da diagonal principal os valores serão calculados posteriormente
				//L[i][j] = 0; 
			
		}
	}
	
	//--- calculando as matrizes L e U ------------------------------------------------------------

	for(k=0; k<n-1; k++)
	{
		#pragma omp parallel for private(i, j, numerador, denominador)
		for(i=k+1; i<n; i++)
		{
			
			numerador = U[i][k];
			denominador = U[k][k];
			
			L[i][k] = numerador/denominador;
			
			for(j=k; j<n; j++)		
			{
				U[i][j] = U[i][j] - L[i][k] * U[k][j];
			}
			
		} // for i
		
	} // for k
		
	
	//--- RESOLVENDO O SISTEMA LINEAR ------------------------------------------
	
	//--- calculando o vetor y ---
	printf("\n\nCalculando o vetor y...\n\n");

	
	for(i=0; i<n; i++)
	{
		y[i] = b[i];
		
		for(j=0; j<=i-1; j++)
		{
			y[i] = y[i] - L[i][j] * y[j];
		}
	}
	
	//--- calculando o vetor x ---
	printf("\n\nCalculando o vetor x...\n\n");

	for(i=n-1; i>=0; i--)
	{
		x[i] = y[i];
		
		for(j=n-1; j>=i+1; j--)
		{
			x[i] = x[i] - U[i][j] * x[j];
		}
		
		x[i] = x[i] / U[i][i];
		
	}

	
	tf = clock();	
	
   	tempo = ((double)(tf - t0)) / (double)CLOCKS_PER_SEC;   	

   	printf("\n\nSistema com %d incógnitas: Tempo Computacional em Paralelo %10.5f segundos\n\n", n, tempo);

	
	// imprimindo o resultado ----------------
	/****************************************************************************/
	if( n <= 10 )
	{
		printf("\n\nU = \n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				printf("%5.0f", U[i][j]);
			}
			printf("\n");
		}	
		
		
		printf("\n\nL = \n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				printf("%5.0f", L[i][j]);
			}
			printf("\n");
		}	
		
		printf("\n\ny = \n");
		for(i=0; i<n; i++)
		{
			printf("%5.0f\n", y[i]);
		}		
	
		printf("\n\nx = \n");
		for(i=0; i<n; i++)
		{
			printf("%10d : %5.0f\n", i, x[i]);
		}			

	} // impressão do resultado if( n <= 10 )

	/****************************************************************************/

	/**
	printf("\n\nx = \n");
	for(i=0; i<n; i++)
	{
		printf("%10d : %5.0f\n", i, x[i]);
	}			
	/**/
	
	return 0;
	
} // main()












