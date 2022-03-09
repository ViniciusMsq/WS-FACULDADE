#include <iostream>
#include "TBT.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	/*
		exercicio 1- Copiar classe TBT
		exercicio 2- Adicionar dois metodos
		exercicio 3- Modificar a Arvore
	*/

	TBT arvore;
	TBT::TNo* no_aux;
	TBT::TInfo E;

	no_aux = arvore.CriarRaiz('A');

	arvore.Insere_No_Esquerdo(no_aux, 'B');
	arvore.Insere_No_Direito(no_aux, 'C');

	no_aux = arvore.BuscarNo(arvore.GetRaiz(), 'B');
	arvore.Insere_No_Esquerdo(no_aux, 'D');

	no_aux = arvore.BuscarNo(arvore.GetRaiz(), 'C');
	arvore.Insere_No_Esquerdo(no_aux, 'E');
	arvore.Insere_No_Direito(no_aux, 'F');

	no_aux = arvore.BuscarNo(arvore.GetRaiz(), 'E');
	arvore.Insere_No_Direito(no_aux, 'G');

	no_aux = arvore.BuscarNo(arvore.GetRaiz(), 'F');
	arvore.Insere_No_Esquerdo(no_aux, 'H');
	arvore.Insere_No_Direito(no_aux, 'I');

	arvore.Print_caminhamento_em_pre_ordem(arvore.GetRaiz());
	printf("\n\n");
	arvore.Print_caminhamento_em_in_ordem(arvore.GetRaiz());
	printf("\n\n");
	arvore.Print_caminhamento_em_pos_ordem(arvore.GetRaiz());
	printf("\n");
	
	system("PAUSE");
	return 0;
}
