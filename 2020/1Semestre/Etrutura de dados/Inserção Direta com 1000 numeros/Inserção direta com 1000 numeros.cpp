#include <iostream>

using namespace std;

// função nao vai devolver valores, tem como parametro vetor com um ponteiro e tamanho.
void shell(float*vetor, float tamanho){
	int aux, i , j , h=tamanho/2;
	while(h>0){
		i = h;
		while (i<tamanho){
			aux = vetor[i];
			j = i;
			while (((j>=h) && (aux<vetor[j-h]))){
				vetor[j] = vetor [j-h];
				j=j-h;
			}
			vetor[j]=aux;
			i=i+1;
		}
		h=h/2;
	}
}


int main()
{
	// Decladrando variaveis. 
	float vetor[1000];
	int op = 1, tam;
					
	cout <<" Digite a quantidade de posicao que deseja inserir: "; // imprimindo para o usuario
	cin >> tam; // variavel que vai receber a quantidade de posi��es desejadas.
	cout << "\n";

					for (int i = 0; i < 1000; i++) // enquanto o i for menor que o vetor ele continua repetindo.
					{
						if (i >= tam) // Se i for maior que a quantidade de posi��o desejada pelo usuario ele quebra e sai a repeti��o. 
						{
							break;
							cout << "\n valores inseridos!\n";
						}
						else // enquanto o valor i for menor que a quantidade de posi��o desejada pelo usuario ele vai inserindo valores nas posi��es do vetor. 
						{
							cout << " Digite o valor da posicao " << i << ": "; 
							cin >> vetor[i]; 
						}
						
					}

					// Imprimindo valores gerados. 
					cout << "\n Valores das posicoes {"; // Coloquei antes para n�o imprimir varias vezes. 
						for (int i = 0; i < tam; i++)
						{
							cout << vetor[i]<<","; // Imprimindo valores das posi��es em seguida uma virgula para separar eles.
						}
					cout << "}\n\n"; // Coloquei depois para fechar e ficar tudo em uma linha organizado { 0,2,5,3, }.
					
					//insercao_Direta(vetor,qtPosicao); // Chamando a fun��o.
					shell(vetor, tam);
					// imprimindo os valores das posi��es da fun��o insercao diretea.
					cout << "\n Valores das posicoes {"; 
					for (int i = 0; i < tam; i++)
					{
						cout << vetor[i] << ",";
					}
					cout << "}\n\n";
}
