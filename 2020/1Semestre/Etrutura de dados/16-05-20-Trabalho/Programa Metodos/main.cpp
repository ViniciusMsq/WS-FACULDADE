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


//---------------------------------------------------------------------

void CombSort(int *vetor, int tamanho)
{
   int gap = tamanho; //inicializa o tamanho do espaÃ§o com o tamanho da vetor
   bool flag = true;
   while(gap != 1 || flag == true)
   {
      gap = (gap*10)/13; //minimizar a folga pelo fator de contraÃ§Ã£o
      if(gap<1)
      
      	gap = 1;
      	flag = false;
	      for(int i = 0; i<tamanho-gap; i++)//comparar elementos com gap
	      { 
	         if(vetor[i] > vetor[i+gap])
	         {
	            swap(vetor[i], vetor[i+gap]);
	            flag = true;
	         }
	      }  
   }
}
//------------------------------------------------------------------------------
void Troca(int* vetor, int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}
	int Pivo(int* vetor, int inicial, int final)
	{
		int i = inicial + 1;
		int j = final;
		int pivo = vetor[inicial];
		
		while (i <= j)
		{
			if (vetor[i] <= pivo)
			{
				i++;
			}
			else if (vetor[j] > pivo)
			{
				j--;
			}
			else if (i <= j)
			{
				Troca(vetor, i, j);
				i++;
				j--;
			}
		}
		Troca(vetor, inicial, j);
		return j;
	}

void QuickSort(int* vetor, int inicial, int final)
{
	if (inicial < final)
	{
		int j = Pivo(vetor, inicial, final);
		QuickSort(vetor, inicial, j - 1);
		QuickSort(vetor, j + 1, final);
	}
}

//------------------------------------------------------------------------------
void ShellSort(int *vetor, int tamanho)
{
	int aux, i, j, contr = tamanho / 2; // O controlador da divisão do vetor ex: contr = 10/2; contr=5
	while (contr > 0) // enquanto o contro > 0 (contro = 5)
	{
		i = contr; // variavel i recebe o valor 5
		while (i < tamanho) // 5 < tamanho (10)
		{
			aux = vetor[i];
			j = i;
				while (((j >= contr) && (aux < vetor[j - contr])))
				{
					vetor[j] = vetor[j - contr];
					j = j - contr;
				}
			vetor[j] = aux;
			i = i + 1;
		}
		contr = contr / 2;
	}
}
//------------------------------------------------------------------------------
void InsercaoDireta(int *vetor, int tamanho)
{
	int i, j, menor, aux; // Declarando as variaveis.
	for (i = 0; i < tamanho - 1; i++) // enquanto i for menor que o tamnho ele vai diminuindo -1.
	{
		menor = i; // menor passa a receber o valor de i.
	// J recebe valor de i e começa a comparar as posiçoes
	for (j = i + 1; j < tamanho; j++)
	{
		if (vetor[j] < vetor[menor])
		{
			menor = j;
		}
	}
		aux = vetor[i]; // aux ta recebendo o vetor[i].
		vetor[i] = vetor[menor]; // vetor[i] esta recebendo o valor do vetor[menor].
		vetor[menor] = aux; // vetor[menor] esta recebendo o velor da aux.
	} 
}

//------------------------------------------------------------------------------
void Bolha(int *V, int n)
{
    int i, j, aux;
 
    // ordenando o vetor
    for(i=n-1; i>=0; i--)
    {
        for(j=0; j<i; j++)
        {
            if( V[j] > V[j+1] )
            {
                aux    = V[j+1];
                V[j+1] = V[j];
                V[j]   = aux;                    
            }                 
        } // for j           
    } // for i
     
} // void Bolha()


//------------------------------------------------------------------------------

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  

// Uma função para implementar a classificação de bolhas  
void BubbleSort(int v[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      

// Os últimos elementos i já estão em vigor 
    for (j = 0; j < n-i-1; j++)  
        if (v[j] > v[j+1])  
            swap(&v[j], &v[j+1]);  
}  
  

/* Função para imprimir uma matriz */
void printArray(int v[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << v[i] << " ";  
     cout<<"\n";  
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
	
	// Analizando o metodo CombSort.
   	copiar_vetor(V, V_ORIGINAL, n);
    t0 = clock(); // pegando tempo inicial 
    CombSort(V,n); // aplicando metodo CombSort.
    tf = clock();   // pegando tempo final   
   	tempo = ((double)(tf - t0)) / (double)CLOCKS_PER_SEC; // Variavel tempo calcula tempo inicia "t0"- tempo final"tf", depois divide pelo clocks por segundo.  	
   	printf("\nCombSort                   %10.5f segundos", tempo);// imprimindo nome do metodo e tempo gasto. 
 

	// Analizando o metodo QuickSort.
	copiar_vetor(V, V_ORIGINAL, n);
    t0 = clock();// pegando tempo inicial 
    QuickSort( V, 0, n-1);// aplicando metodo QuickSort.
    tf = clock();   // pegando tempo final   
   	tempo = ((double)(tf - t0)) / (double)CLOCKS_PER_SEC;  // Variavel tempo calcula tempo inicia "t0"- tempo final"tf", depois divide pelo clocks por segundo. 	
   	printf("\nQuickSort                  %10.5f segundos", tempo);// imprimindo nome do metodo e tempo gasto. 
   	

	// Analizando o metodo ShellSort.
	copiar_vetor(V, V_ORIGINAL, n);
    t0 = clock(); // pegando tempo inicial 
    ShellSort(V,n); // aplicando metodo ShellSort.
    tf = clock();  // pegando tempo final   
   	tempo = ((double)(tf - t0)) / (double)CLOCKS_PER_SEC;   // Variavel tempo calcula tempo inicia "t0"- tempo final"tf", depois divide pelo clocks por segundo. 	 
   	printf("\nShellSort                  %10.5f segundos", tempo); // imprimindo nome do metodo e tempo gasto. 

   	
   	// Analizando o metodo de Inserção Direta
	copiar_vetor(V, V_ORIGINAL, n); 
    t0 = clock(); // pegando tempo inicial 
    InsercaoDireta(V,n); // aplicando metodo inserção direta.
    tf = clock(); // pegando tempo final    
   	tempo = ((double)(tf - t0)) / (double)CLOCKS_PER_SEC; // Variavel tempo calcula tempo inicia "t0"- tempo final"tf", depois divide pelo clocks por segundo.   	
	printf("\nInserção Direta            %10.5f segundos", tempo);// imprimindo nome do metodo e tempo gasto. 
	
	// Analizando o metodo BubbleSort.
	copiar_vetor(V, V_ORIGINAL, n);
    t0 = clock(); // pegando tempo inicial 
    BubbleSort(V,n); // aplicando metodo BubbleSort.
    tf = clock();  // pegando tempo final   
   	tempo = ((double)(tf - t0)) / (double)CLOCKS_PER_SEC;   // Variavel tempo calcula tempo inicia "t0"- tempo final"tf", depois divide pelo clocks por segundo. 	 
   	printf("\nBubbleSort                  %10.5f segundos", tempo); // imprimindo nome do metodo e tempo gasto. 
   	
   	
	// Analizando o metodo Bolha.
	copiar_vetor(V, V_ORIGINAL, n);
    t0 = clock();// pegando tempo inicial 
    Bolha(V,n); // aplicando metodo bolha.
    tf = clock();    // pegando tempo final  
   	tempo = ((double)(tf - t0)) / (double)CLOCKS_PER_SEC; // Variavel tempo calcula tempo inicia "t0"- tempo final"tf", depois divide pelo clocks por segundo.  	
   	printf("\nBolha                       %10.5f segundos", tempo);// imprimindo nome do metodo e tempo gasto. 


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
