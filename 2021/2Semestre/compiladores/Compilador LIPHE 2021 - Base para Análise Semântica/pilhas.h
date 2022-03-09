#include "includes.h"


typedef int pilha[TamPilhas];


void CriarPilha( pilha &p ){

   p[0] = 0;

}

bool PilhaEhVazia ( pilha p ){

   	if(p[0] == 0)
   		return true;
   	else
   		return false;
}

int TopoPilha ( pilha p  ){

	return p[0];

}

void Empilha ( pilha &p , int v){
	p[0]++;
	p[p[0]] = v;
}

int Desempilhar ( pilha &p){

   int aux = p[p[0]];
   p[0]--;
   return aux;

}

void MostrarPilha ( pilha p){
	cout << "\n";

	if(p[0] != 0)
	{
		
		for(int i=p[0]; i> 0; i--)
   			cout << p[i];
	}
	else
	{
		cout << "Pilha Vazia";
	}		
    
}
