#include<iostream>
#include<algorithm>


using namespace std;


void display(int *vetor, int tamanho)
{
   for(int i = 0; i<tamanho; i++)
      cout << vetor[i] << " ";
      cout << "\n";
}

void combSort(int *vetor, int tamanho)
{
   int gap = tamanho; //inicializa o tamanho do espaço com o tamanho da vetor
   bool flag = true;
   while(gap != 1 || flag == true)
   {
      gap = (gap*10)/13; //minimizar a folga pelo fator de contração
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
int main()
{   system("cls");

    int vetor[1000]; // cria uma matriz com determinado número de elementos
	int qtPosicao; // declarando variavel de quantidade de posições

		cout << " Digite a quantidade de posicao que deseja inserir: "; 
		cin >> qtPosicao; 
		cout << "\n";

	for (int i = 0; i < 1000; i++) 
	{
		if (i >= qtPosicao)  
		{
			break;
			cout << "\n valores inseridos!\n";
		}
		else 
		{
			cout << " Digite o valor da posicao " << i << ": ";
			cin >> vetor[i];
		}

	}

   cout << "\n Valores das posicoes antes do Metodo {";
	for (int i = 0; i < qtPosicao; i++)
	{
		cout << vetor[i] << ","; 
	}cout << "}\n\n";

   combSort(vetor, qtPosicao);

    cout << "\n Valores das posicoes depois do Metodo {";
		for (int i = 0; i < qtPosicao; i++)
		{
			cout << vetor[i] << ",";
		}
		cout << "}\n\n";


}