// Ponteiro.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <locale.h>
#include <stdio.h>

using namespace std;

int menor(int m, int n) {
	int r;
	if (m<n) {
		r = m;
	}
	else {
		r = n;
	}
	return (r);
}

int main()
{
	setlocale(LC_ALL, "");

	int result, x, y;
	cout << "Digite o valor x: ";
	cin >> x;
	cout << "Digite o valor y:";
	cin >> y;
	result = menor(x, y);
	cout << "\n\n O menor valor é: " << result;
	return 0;

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
