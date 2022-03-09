#include <cstdlib>
#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

// variávies Globais
    int n=-1;
    int *V, *V_ORIGINAL;    
    char opc;


//------------------------------------------------------------------------------
void print_vetor( int *v, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\n %5d", v[i]);
    }     
} // void print_vetor

//------------------------------------------------------------------------------
void ShellSort(int *v, int n)
{	
    int j, ch, i, k, h, ih;
	
	h=880;
	while( h>=1)
	{
		ih=1;
		while( ih<= h)
		{
			i = (ih-1) + h;
			while( i<=n-1)
			{
				ch= v[i];
				k=i;
				j=i - h;
				while( j>= ih-1)
				{
					if( ch<v[j])
					{
						v[j+h] = v[j];
						k=j;
						j = j -h;
					} else break;
					
				 } 
				 
				 v[k] = ch;
				 i=i + h;
			}
			ih = ih +1;
		}
		h=h/2;
	}
	
}

//------------------------------------------------------------------------------
void copiar_vetor(int *destino, int *origem, int n)
{
	for(int i=0; i<n; i++) destino[i] = origem[i];
}



//================================================================================================================================================================
int* AlocarVetorInt(int n)
{  
   int i; 

   int *v = (int*) malloc(n * sizeof(int)); 
   
   //Percorre o Vetor de Inteiros atual.
   for (i = 0; i < n; i++)
   { 
        v[i] = 0; //Inicializa com 0.
   }
 
  return v; 
  
} // AlocarVetorInt

//============================================================================================================
void print_menu()
{
	
	system("cls");
	printf("\n===================================================\n");
	printf("MÉTODOS DE ORDENAÇÃO");
	printf("\n===================================================\n");
	
	printf("\n\n");
		
	printf("\n1 - CARREGAR VETOR 100.000 VALORES");
	printf("\n2 - CARREGAR VETOR 1.000.000 VALORES");		
	printf("\n3 - ANALISAR MÉTODOS");
	
	
	if( n == -1)
	{
		printf("\n\n\nVetor: Vetor vazio");
	}
	else
	{
		printf("\n\n\nVETOR DE %d POSIÇÕES CARREGADO",n);
	}
	
	printf("\n\n\nPressione Esc para Sair");
	
	
	
} // print_menu()

//============================================================================================================
void carregar_vetor(char opc)
{
	FILE *F;
	
	int x;

    char nome_arquivo[100];
    
    if( opc == '1')
    {
    	sprintf(nome_arquivo,"%d.txt",100000);	
	}
	else
	{
		sprintf(nome_arquivo,"%d.txt",1000000);	
	}
	
	F = fopen(nome_arquivo,"r");
	
	if( F == NULL )
	{
		printf("Arquivo inválido !!!");
		getch();
		return;
	}	
	
	printf("\n\nCarregando arquivo...\n\n");
	
	n = 0;
	// Fazendo a contagem de linhas do arquivo para fazer a alocação do vetor-------------------------------
	while( !feof(F) )
	{
		fscanf(F,"%d",&x);		
		//printf("\n%d", x);		
		n++;		
	} // while linhas
	
	
	// reposicionando o arquivo no início		
	rewind(F);

	if( n != -1 ) 
	{
		free(V);
		free(V_ORIGINAL);
	}

	V = AlocarVetorInt(n);
	V_ORIGINAL = AlocarVetorInt(n);

	int i = 0;	
	while( !feof(F) )
	{
		fscanf(F,"%d",&x);
				
		V_ORIGINAL[i] = x;
		
		i++;		
		
	} // while linhas


	fclose(F);
		
	printf("\n\nVETOR DE %d VALORES CARREGADO COM SUCESSO, PRESSIONE ALGO PARA CONTINUAR...", n);
	getch();
	
	
} // carregar_vetor(char opc)

//============================================================================================================
void analisar_metodos()
{
	
	clock_t t0, tf;
	double tempo;
	
	system("cls");
	printf("\n============= ANALISANDO MÉTODOS =============", n);
	printf("\n\nORDENANDO VETOR DE %d VALORES\n\n", n);	
	
	if( n == -1 )
	{
		printf("VETOR VAZIO !!!\nCARREGUE O VETOR ANTES DE ANALISAR...");
		getch();
		return;
	}
	
	
	printf("\nMétodo                        Tempo");
	

	// Analizando o metodo ShellSort.
	copiar_vetor(V, V_ORIGINAL, n);
    t0 = clock(); // pegando tempo inicial 
    ShellSort(V,n); // aplicando metodo ShellSort.
    tf = clock();  // pegando tempo final   
   	tempo = ((double)(tf - t0)) / (double)CLOCKS_PER_SEC;   // Variavel tempo calcula tempo inicia "t0"- tempo final"tf", depois divide pelo clocks por segundo. 	 
   	printf("\nShellSort                  %10.5f segundos", tempo); // imprimindo nome do metodo e tempo gasto. 


	printf("\n\n\nPressione algo para encerrar...\n\n");
	getch();
	
	
} // void analisar_metodos()

//============================================================================================================
int main(int argc, char *argv[])
{
    // Alterando o charset para o padrão do sistema operacional, caracteres e formato de números
    setlocale(LC_ALL,""); 

	opc = '0';
	while( opc != 27 )
	{
		
		print_menu();
		
		
		opc = getch();
		
		
		if( opc == '1')	
		{
			carregar_vetor('1');
			
		} // carregar de 100 000
		else
		if( opc == '2')	
		{
			carregar_vetor('2');
			
		} // carregar de 1 000 000
		else
		if( opc == '3')	
		{
			analisar_metodos();
			
		} // analisar
		
			
		
	} // while menu...
	
    
    // Liberando a memória do Vetor alocado dinamicamente
    free(V);
    
    
    printf("\n\n\n");
    //system("PAUSE");
    return EXIT_SUCCESS;
    
} // int main()
