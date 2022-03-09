#include <iostream>

using namespace std;

struct TAluno {
	string nome;
	float media;
};


int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "");
	
	TAluno aluno[2];
	int i;
	
	for(i=0;i<2;i++)
	{
		printf("Informe o nome do aluno %d: ", i);
						
		fflush(stdin); // resolve o problema do buffer de entrada de \n em strings	
		getline(cin, aluno[i].nome);	
		
		printf("Informe a media.........: ");
		cin >> aluno[i].media;
		
	}
	
	printf("\n\nOs alunos cadastrados sao: \n\n");
	
	for(i=0;i<2;i++)
	{
		cout << "\n" << aluno[i].nome << " " << aluno[i].media;
	}
	
	// Exemplo de comparação entre duas strings
	if( aluno[0].nome > aluno[1].nome)
	{
		cout << "\n\nO PRIMEIRO nome eh maior alfabeticamente que o segundo !!!";
	}
	else
	{
		cout << "\n\nO SEGUNDO nome eh maior alfabeticamente que o primeiro !!!\n\n";
	}
	
	
	return 0;
}
