#include "Anlexica.h"
#include "anSintatica.h"
//#include "tabSimb.h"

//#include "listComp.h"



int main(int argc, char** argv) {
	
	//Vari�veis
	FILE *arqEntrada, *arqSaida, *arqTeste;
	bool suc;
	//Inicializa os arquivos texto de entrada e sa�da
	arqEntrada = fopen("arqEntrada.txt","r");
	arqSaida = fopen("arqSaida.txt","aw");
	
 	if(AnalisadorLexico(arqEntrada, arqSaida, suc))	
		cout << "\nCodigo compilado com Sucesso";

	fclose(arqEntrada);
	fclose(arqSaida);
	
	arqSaida = fopen("arqSaida.txt","ra");
	
	
	if (Sintaxe(arqSaida))
		cout << "\nCodigo compilado com Sucesso";
 

		//Fecha arquivos texto

	fclose(arqSaida);
	
	system("pause>>null");
	return 0;
}
