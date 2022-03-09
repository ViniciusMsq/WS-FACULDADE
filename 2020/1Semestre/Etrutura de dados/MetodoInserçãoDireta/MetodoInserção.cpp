#include <iostream>

using namespace std;

void insercao(float* vetor, int tam) {
	int j, i, m, aux;
	for (i = 0; i < tam - 1; i++) {
		m = i;

		for (j = i + 1; j < tam; j++) {
			if (vetor[j] < vetor[m]) {
				m = j;
			}
		}
		aux = vetor[i];
		vetor[i] = vetor[m];
		vetor[m] = aux;
	}
}
int main() {
	float vetor[100];
	int tam;

	cout << "Digite a quantidade de posicoes: ";
	cin >> tam;
	for (int i = 0; i < 1000; i++) {
		if (i < tam) {
			cout << "informe um valor: ";
			cin >> vetor[i];
		}
		else {
			break;
		}
	}
	
	cout << "\n\nvetor dessarrumado: ";
	for (int i = 0; i < tam; i++) {
		cout << vetor[i] << ", ";
	}
	cout << "\n\nvetor arrumado: ";
	insercao(vetor, tam);

	for (int i = 0; i < tam; i++) {
		cout << vetor[i] << ", ";
	}
}