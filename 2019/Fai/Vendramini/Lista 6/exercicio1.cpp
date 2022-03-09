#include <iostream>
#include <stdio.h>
using namespace std;
int main( ){
    char *matriz[2][2];
    char nome[50];
    char snome[50];
    
    cout<<"Digite seu nome: ";
    gets(nome);
    cout<<"Digite seu sobrenome: ";
    gets(snome);

    matriz[0][0] = nome;
    matriz[1][0] = snome;
    printf("%s", matriz[0][0]);
    cout<<"\n";
    printf("%s", matriz[1][0]);
    
    return 0;
}
