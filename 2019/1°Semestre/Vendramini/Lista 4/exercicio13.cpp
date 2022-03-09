// exercicio13.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int i;
	float sal = 0.00, reaj = 0.00;

	for (i = 1; i <= 1000; i++) {
		cout << "Funcionario " << i << "\n";
		cout << "\nInforme seu salário: ";
		cin >> sal;

		cout << "\n\n";

		if (sal < 1000) {
			reaj = sal + (sal * 0.33);
		}
		else if(sal>=1000 && sal<=2500){
			reaj = sal + (sal * 0.20);
		}
		else {
			reaj = sal + (sal * 0.10);
		}

		cout << "Salário com reajuste: " << reaj;
		cout << "\n";
		system("pause");
		system("cls");
	}
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
