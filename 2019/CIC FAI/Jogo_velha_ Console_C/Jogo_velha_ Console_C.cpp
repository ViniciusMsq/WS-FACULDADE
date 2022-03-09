// Jogo da velha1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include<stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void tabuleiro(char casas2[3][3]) {
	system("cls");
	cout << "" << casas2[0][0] << "|" << casas2[0][1] << "|" << casas2[0][2] << endl;
	cout << "-----" << endl;
	cout << "" << casas2[1][0] << "|" << casas2[1][1] << "|" << casas2[1][2] << endl;
	cout << "-----" << endl;
	cout << "" << casas2[2][0] << "|" << casas2[2][1] << "|" << casas2[2][2] << endl;

}
int main()
{
	int pont[4], pontX=0, pontO=0;
	int cont_vet = 0;
	char casas[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'}, };
	char res;
	int cont_jogadas, l, c, vez = 0, i, j;

	do {
		do {
			cont_jogadas = 1;
			for (i = 0; i <= 2; i++)
			{
				for (j = 0; j <= 2; j++)
				{
					casas[i][j] = ' ';

				}
			}

			//Repetição quantidade de jogadas 
			do {
				tabuleiro(casas);
				if (vez % 2 == 0) {
					cout << "Jogador X" << endl;
				}
				else {
					cout << "Jogador O" << endl;
				}
				cout << "Digite a linha: ";
				cin >> l;
				cout << "Digite a coluna: ";
				cin >> c;

				if (l < 1 || c < 1 || 1 > 3 || c > 3)
				{
					l = 0;
					c = 0;
				}
				else if (casas[l - 1][c - 1] != ' ')
				{

				}
				else {
					if (vez % 2 == 0)
					{
						casas[l - 1][c - 1] = 'X';
					}
					else
					{
						casas[l - 1][c - 1] = 'O';
					}

					vez++;
					cont_jogadas++;
				}

				if (casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X')
				{
					cont_jogadas = 11;
				}
				if (casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X')
				{
					cont_jogadas = 11;
				}
				if (casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X')
				{
					cont_jogadas = 11;
				}
				if (casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X')
				{
					cont_jogadas = 11;
				}
				if (casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X')
				{
					cont_jogadas = 11;
				}
				if (casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X')
				{
					cont_jogadas = 11;
				}
				if (casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X')
				{
					cont_jogadas = 11;
				}
				if (casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X')
				{
					cont_jogadas = 11;
				}

				if (casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O')
				{
					cont_jogadas = 12;
				}
				if (casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O')
				{
					cont_jogadas = 12;
				}
				if (casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O')
				{
					cont_jogadas = 12;
				}
				if (casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O')
				{
					cont_jogadas = 12;
				}
				if (casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O')
				{
					cont_jogadas = 12;
				}
				if (casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O')
				{
					cont_jogadas = 12;
				}
				if (casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O')
				{
					cont_jogadas = 12;
				}
				if (casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O')
				{
					cont_jogadas = 12;
				}

			} while (cont_jogadas <= 9);
			tabuleiro(casas);

			if (cont_jogadas == 10)
			{
				cout << "Jogo empatado!" << endl;
			}
			if (cont_jogadas == 11)
			{
				cout << "vencedor X!" << endl;
				pontX++;
			}
			if (cont_jogadas == 12)
			{
				cout << "Vencedor O!" << endl;
				pontO++;
			}

			cout << "Deseja jogar novamente?[S-N]" << endl;
			cin >> res;

		} while (res == 's');

		pont[c] = pontX;
		pont[c + 1] = pontO;
		c += 2;
		cout << "Deseja reiniciar outro jogo?[s-n]";
		cin >> res;
	} while (res == 's');
	cout << "Ranking:" << endl;
	int aux;
	for (int r = 0; r < 4; r++) {
		for (int r2 = 0; r2 < 4; r++) {
			if (pont[r] < pont[r2]) {
				aux = pont[r];
				pont[r] = pont[r2];
				pont[r2] = aux;
			}
		}
	}
	cout << "Ranking:" << endl;
	for (int r = 0; r < 4; r++) {
		cout << pont[r] << endl;
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
