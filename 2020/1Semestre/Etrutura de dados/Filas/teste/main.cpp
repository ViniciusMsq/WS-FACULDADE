#include <iostream>
#include <string>

using namespace std;

typedef struct{
    string nome;
    int telefone;
    int grau;
}Paciente;

int main(){

    Paciente *pacientes;

    pacientes->nome = "Vinicius";
    pacientes->telefone = 123;
    pacientes->grau = 1;

    cout<<pacientes[0].grau;

    return 0;
}