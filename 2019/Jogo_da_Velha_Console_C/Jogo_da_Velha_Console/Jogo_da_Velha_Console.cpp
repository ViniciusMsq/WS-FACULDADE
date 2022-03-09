
#include<stdlib.h>

#include <stdio.h>

#include <iostream>

using namespace std;

//void Ranking(int vet, int tam);

void tabuleiro(char casas2[3][3]) {
	system("cls");
	cout << "--Jogo da Velha--" << endl<<endl;
	cout << "  " << casas2[0][0] << "  |" << casas2[0][1] << "   |" << casas2[0][2] << endl;
	cout << "-----------------" << endl;
	cout << "  " << casas2[1][0] << "  |" << casas2[1][1] << "   |" << casas2[1][2] << endl;
	cout << "-----------------" << endl;
	cout << "  " << casas2[2][0] << "  |" << casas2[2][1] << "   |" << casas2[2][2] << endl<<endl;
	
}
int main() {
	 int pont[4], pontX = 0, pontO = 0, p=0;
	int cont_vet = 0;
	char casas[3][3] = {
	  {
		'1',
		'2',
		'3'
	  },
	  {
		'4',
		'5',
		'6'
	  },
	  {
		'7',
		'8',
		'9'
	  },
	};
	char res;
	int cont_jogadas, l, c, vez = 0, i, j;

	do {
		do {
			cont_jogadas = 1;
			for (i = 0; i <= 2; i++) {
				for (j = 0; j <= 2; j++) {
					casas[i][j] = ' ';

				}
			}

			//Repetição quantidade de jogadas 
			do {
				tabuleiro(casas);
				cout << "\n";
				if (vez % 2 == 0) {
					cout << "Jogador X" << endl;
					cout << "\n";
				}

				else {
					cout << "Jogador O" << endl;
					cout << "\n";
				}
				cout << "Digite a linha: ";
				cin >> l;
				cout << "Digite a coluna: ";
				cin >> c;

				if (l < 1 || c < 1 || 1 > 3 || c > 3) {
					l = 0;
					c = 0;
				}
				else if (casas[l - 1][c - 1] != ' ') {

				}
				else {
					if (vez % 2 == 0) {
						casas[l - 1][c - 1] = 'X';
					}
					else {
						casas[l - 1][c - 1] = 'O';
					}

					vez++;
					cont_jogadas++;
				}

				if (casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X') {
					cont_jogadas = 11;
				}
				if (casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X') {
					cont_jogadas = 11;
				}
				if (casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X') {
					cont_jogadas = 11;
				}
				if (casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X') {
					cont_jogadas = 11;
				}
				if (casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X') {
					cont_jogadas = 11;
				}
				if (casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X') {
					cont_jogadas = 11;
				}
				if (casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X') {
					cont_jogadas = 11;
				}
				if (casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X') {
					cont_jogadas = 11;
				}

				if (casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O') {
					cont_jogadas = 12;
				}
				if (casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O') {
					cont_jogadas = 12;
				}
				if (casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O') {
					cont_jogadas = 12;
				}
				if (casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O') {
					cont_jogadas = 12;
				}
				if (casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O') {
					cont_jogadas = 12;
				}
				if (casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O') {
					cont_jogadas = 12;
				}
				if (casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O') {
					cont_jogadas = 12;
				}
				if (casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O') {
					cont_jogadas = 12;
				}

			} while (cont_jogadas <= 9);
			tabuleiro(casas);

			if (cont_jogadas == 10) {
				cout << "Jogo empatado!" << endl;
			}
			if (cont_jogadas == 11) {
				cout << "vencedor X!" << endl;
				pontX++;
			}
			if (cont_jogadas == 12) {
				cout << "Vencedor O!" << endl;
				pontO++;
			}

			cout << "Deseja jogar novamente?[S-N]" << endl;
			cin >> res;

		} while (res == 's'|| res == 'S');

		pont[p] = pontX;
		pont[p+1] = pontO;
		p += 2;
		pontX = 0;
		pontO = 0;

		cout << "Deseja reiniciar outro jogo?[s-n]";
		cin >> res;
	} while (res == 's' || res == 'S');

	 int aux;
	for (int r = 0; r < 4; r++) {
		for (int r2 = 0; r2 < 4; r2++) {
			if (pont[r] < pont[r2]) {
				aux = pont[r];
				pont[r] = pont[r2];
				pont[r2] = aux;
			}
		}
	}
	cout << "Ranking:" << endl;
	for (int r = 3; r >=0; r--) {

		cout << "Jogadores " << pont[r] << endl;

	}
}
