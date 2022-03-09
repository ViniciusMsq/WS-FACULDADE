// exercicio23.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	char c;
	int voto,c1, c2, c3, c4,nulo,branco;

	do {
		cout << "Vote no seu candidato(codigos 1,2,3,4,5 para nulo e 6 para branco)";
		cin >> voto;

		if (voto == 1) {
			c1++;
		}
		else if (voto == 2) {
			c2++;
		}
		else if (voto == 3) {
			c3++;
		}
		else if (voto == 4) {
			c4;
		}
		else if (voto == 5) {
			nulo++;
		}
		else {
			branco++;
		}
		cout << "continuar votação?(s/n)";
		cin >> c;
	} while (c == 's');

	cout << "\ncandidato 1: " << c1;
	cout << "\ncandidato 2: " << c2;
	cout << "\ncandidato 3: " << c3;
	cout << "\ncandidato 4: " << c4;
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
