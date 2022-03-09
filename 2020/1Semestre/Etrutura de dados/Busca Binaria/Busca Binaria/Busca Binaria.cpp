#include <iostream>

using namespace std;

int BuscaBin(float* v, int i, int j, float chave) {
    int k; 
    if (i <= j) {
        k = (i + j) / 2;
        if (v[k] == chave) {
            return k;
        }
        else {
            if (chave < v[k]) {
                return BuscaBin(v, i, k - 1, chave);
            }
            else {
                return BuscaBin(v, k + 1, j, chave);
            }
        }
    }
    else {
        return -1;
    }
}

void Insercao(float* v, int n) {
    float cb;
    for (int i = 0; i < 10; i++) {
        
    }
    
}
void Bolha(float* v, int n) {
    int i, j;
    float aux;
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j + 1];
                v[j + 1] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main()
{

    float v[] = {8,1,9,5,16,18,89,25,28,2};
    int pos, pesquisa;
    
    cout << "-----------Area de pesquisa---------------\n\n";
    printf("Informe a chave de pesquisa: ");
    cin >> pesquisa;
    for (int i = 0; i < 10; i++) {
        cout << v[i] << ", ";
    }
    cout << "\n\n";
    Insercao(v, 10);
    for (int i = 0; i < 10; i++) {
        cout << v[i]<<", ";
    }
    cout << "\n";
    system("PAUSE");
    pos = BuscaBin(v, 0, 9, pesquisa);

    if (pos == -1) {
        system("cls");
        printf("Valor nao encontrado");
    }
    else {
        system("cls");
        cout << "-------------------------------------\n\n";
        cout << "A posicao encontrada foi " << pos << " (" << pos + 1 << ")\n\n";
        cout << "-------------------------------------\n\n";
    }
}