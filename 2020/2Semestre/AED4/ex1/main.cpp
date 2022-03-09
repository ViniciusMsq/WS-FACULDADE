#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include "TPilha.h"
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	TPilha::TNoPilha* P;
    TPilha pilha;
    pilha.Init(P);
    char frase[100];
    // char fraseFinal[100];
    int x;

    system("CLS");
    cout << "Informe uma frase: ";
    fflush(stdin);
    gets(frase);

    x = strlen(frase);

    for (int i = 0; i <= x; i++) {

        pilha.Push(P, frase[i]);

        if (frase[i] == ' ' || frase[i] == '\0') {

            while (!pilha.IsEmpty(P)) {
                cout << pilha.Pop(P);
            }
            cout << " ";
        }
    }

    printf("\n\n");
    system("PAUSE");
    system("CLS");
    return 0;
}
