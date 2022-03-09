// exercicio8.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
using namespace std;
int main()
{
	char sex;
	int nh=0, nm=0, i;
	float alt=00.00, menor=00.00, maior=0.00, media=00.00, perc=0.00;

	for (i = 1; i <=50 ; i++)
	{
		cout << "Informe seu Sexo(m/f): ";
		cin >> sex;
		cout << "Informe sua Altura: ";
		cin >> alt;

			if (sex == 'f' || sex == 'F') {
			nm++;
			media += alt;
			}
			else
			{
				nh++;
			}
			if (alt > maior) {
				maior = alt;
			}
			if (alt < menor) {
				menor = alt;
			}
			{

			}
	}
	perc = ((nm*100)/50)-((nm*100)/50);
	cout << "A maior altura é: " << maior;
	cout << "\nA menor altura é: " << menor;
	cout << "\nA media da altura das mulheres é: " << media/nm;
	cout << "\nNumero de homens: " << nh << " / Numero de mulheres: " << nm;
	cout << "\nDiferença percentual: " << perc;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
