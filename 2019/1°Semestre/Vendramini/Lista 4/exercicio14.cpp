// exercicio14.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
using namespace std;
int main()
{
	char c, sex;
	int anos;
	float sal=0.00, reaj=0.00, bonus=0.00;

	do {
		cout << "Informe seu sexo(m/f): ";
		cin >> sex;
		cout << "Informe o tempo de casa: ";
		cin >> anos;
		cout << "Informe seu salario: ";
		cin >> sal;

		if (sex == 'm' || sex == 'M') {
			if (anos > 15) {
				reaj = sal + (sal * 0.20);
				bonus += sal * 0.20;
			}
		}
		else if (anos > 10) {
			reaj = sal + (sal * 0.25);
			bonus += sal * 0.25;
		}
		else {
			reaj = sal + 5000;
			bonus += 5000;
		}

		cout << "\nSalario reajustado: " << reaj;

		cout << "\nDeseja calcular mais um Funcionario?(s/n) ";
		cin >> c;
	} while (c == 's' || c == 'S');
	cout << "\n\nTotal de Bonus: " << bonus;
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
