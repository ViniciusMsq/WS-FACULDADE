// Ex1Lista2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace std;

struct endereco {
	int numero;
	string rua, cidade, estado, pais;
};
struct banco {
	int numerocont;
	float dinheiro;
};
struct candidatos {
	string nome;
	struct endereco endereco;
	struct banco banco;
	string filhos[5];
};

int main()
{
	candidatos cadastro;

	cout << "nome: ";
	cin >> cadastro.nome;
	cout << "pais: ";
	cin >> cadastro.endereco.pais;
	cout << "estado: ";
	cin >> cadastro.endereco.estado;
	cout << "cidade: ";
	cin >> cadastro.endereco.cidade;
	cout << "rua: ";
	cin >> cadastro.endereco.rua;
	cout << "numero: ";
	cin >> cadastro.endereco.numero;
	cout << "conta banco: ";
	cin >> cadastro.banco.numerocont;
	cout << "dinheiro: ";
	cin >> cadastro.banco.dinheiro;
	for (int n = 0; n < 5; n++) {
		cout << "nome do filho[]";
		cin >> cadastro.filhos[n];
	}


	system("CLS");

	cout << cadastro.nome << endl;
	cout << cadastro.endereco.cidade << endl;
	cout << cadastro.banco.dinheiro << endl;
	for (int n = 0; n < 5; n++) {
		cout << cadastro.filhos[n]<<"\n";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
