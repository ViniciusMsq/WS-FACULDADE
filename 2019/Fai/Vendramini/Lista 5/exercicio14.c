#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int i, sizeV, num;
	bool found = false;
	printf("\n\n# Pesquisa por valor X no vetor.\n\n");
	printf("- Informe o tamanho do vetor: ");
	scanf("%d", &sizeV);
	int array[sizeV];
	printf("\n\n");

	// Preenchendo o vetor com valores fornecidos pelo usuário.
	for (i = 0; i < sizeV; i++)
	{
		printf("- Digite o valor do indice [%d]: ", i);
		scanf("%d", &array[i]);
	}

	// Valor que será procurado dentro do vetor.
	printf("\n\n- Informe um valor para X que seja inteiro: ");
	scanf("%d", &num);

	// Definir que há algum valor dentro do array que seja igual a X
	for (i = 0; i < sizeV; i++)
	{
		if (array[i] == num)
		{
			found = true;
			break;
		}
		else
		{
			found = false;
		}
	}

	// Percorrendo vetor e imprimindo cada indice na tela
	printf("> Vetor = [");
	for (i = 0; i < sizeV; i++) { if (i == sizeV - 1) { printf("%d]\n", array[i]); } else { printf("%d, ", array[i]); } }

	// Se existir algum valor igual a X, imprimir quis são os indices que correspondem com X
	if (found == true)
	{
		printf("\n\n> Valor X = %d digitado foi encontrado no Vetor dentro do indice = ", num);
		for (i = 0; i < sizeV; i++)
		{
			// Imprimindo o numero do indice com o valor igual a X
			if (array[i] == num)
			{
				printf("[%d] ", i);
			}
		}
		printf(".\n\n");
	}
	else
	{
		// Mensagem mostrada na tela caso nao for encontrado nenhum valor.
		printf("\n\n> Valor X = %d digitado nao foi encontrado no Vetor.\n", num);
	}

	return 0;
}