// exercicio41.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int nh = 0, nm = 0, sex;
	float alt = 00.00, menor = 00.00, maior = 0.00, media = 00.00, perc = 0.00, mediah;

	
	do{
		cout << "Informe seu Sexo(1-masc/2-fem): ";
		cin >> sex;
		cout << "Informe sua Altura: ";
		cin >> alt;

		if (sex == 2) {
			nm++;
			media += alt;
		}
		else
		{
			nh++;
			mediah += alt;
		}
		if (alt > maior) {
			maior = alt;
		}
		if (alt < menor) {
			menor = alt;
		}
	} while (sex != 0);
	
	cout << "A maior altura Ã©: " << maior;
	cout << "\nA menor altura Ã©: " << menor;
	cout << "\nA media da altura das mulheres Ã©: " << media / nm;
	cout << "\nA media da altura das mulheres Ã©: " << mediah / nh;
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
