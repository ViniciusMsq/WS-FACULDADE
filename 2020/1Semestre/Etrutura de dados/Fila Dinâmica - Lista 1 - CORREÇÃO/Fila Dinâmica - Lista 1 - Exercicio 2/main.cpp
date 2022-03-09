#include <iostream>

using namespace std; 

//--- Defini��o da Estrutura da Fila -------------------------

typedef int TInfoFila;

struct TNoFila {	
	TInfoFila dado;	
	TNoFila *prox;		
};

struct TFila {	
	TNoFila *Comeco;
	TNoFila *Final;
};

//-------------------------------------------------------------
void Q_Init(TFila *&Fila)
{
	Fila = new TFila;
	Fila->Comeco = NULL;
	Fila->Final  = NULL;
	
} // void Init()

//-------------------------------------------------------------
bool Q_IsEmpty(TFila *Fila)
{
	return Fila->Comeco == NULL;
	
} // bool IsEmpty()

//-------------------------------------------------------------
void Enqueue(TFila *&Fila, TInfoFila elemento)
{
	TNoFila *novo;
	novo = new TNoFila;

	novo->dado = elemento;
	novo->prox = NULL;
	
	if( Q_IsEmpty(Fila) )	
	{
		Fila->Comeco = novo;
		Fila->Final  = novo;		
		
	} // se a Fila estiver vazia
	else
	{
		Fila->Final->prox = novo;
		
		Fila->Final  = novo;		
				
	} // se a Fila N�����OOOO estiver vazia
	
} // void Enqueue(int n)

//-------------------------------------------------------------
TInfoFila Dequeue(TFila *Fila)
{
	TInfoFila aux;
	
	TNoFila *no_aux;
	
	if( !Q_IsEmpty(Fila) )	
	{		
		aux = Fila->Comeco->dado;
		
		no_aux = Fila->Comeco;
		
		Fila->Comeco = Fila->Comeco->prox;	
		
		delete(no_aux);
	}
	else
	{
		aux = 0;
	}
	
	return aux;	
	
} // Dequeue

//-------------------------------------------------------------
TInfoFila Q_Comeco(TFila *Fila)
{
	// se a Fila n�o estiver vazia
	if( !Q_IsEmpty(Fila) )
	{
		return Fila->Comeco->dado;
	
	} 
	else return 0;
	
} // TInfoFila Q_Comeco()

//-------------------------------------------------------------
TInfoFila Q_Final(TFila *Fila)
{
	// se a Fila n�o estiver vazia
	if( !Q_IsEmpty(Fila) )
	{
		return Fila->Final->dado;
	
	} 
	else return 0;
	
} // TInfoFila Q_Final()


//-------------------------------------------------------------
void PrintFila(TFila *F)
{	
	if( !Q_IsEmpty(F) )
	{
		TNoFila *aux_no;	
	
		cout << "\n\nO CONTEUDO DA FILA E:\n";
		aux_no = F->Comeco;

		while( aux_no != NULL )		
		{
			cout << aux_no->dado << " ";
			aux_no = aux_no->prox;
		}

	} // se a fila n�o estiver fazia
	else 
	{
		cout << "\n\nA FILA esta vazia !!!";
	}
	
	cout << "\n\n";	
	
} // PrintFila

//-------------------------------------------------------------
int main(int argc, char** argv) {
	
	TInfoFila aux;		
	TFila *F;
		
	Q_Init(F);
	
	printf("\n=======================================");
	printf("\n=== FILA DINAMICA - EXERCICIO 2 ======\n\n");
	
	cout << "Informe um valor para a Fila: ";
	cin >> aux;
	
	while( aux > 0 )
	{
		
		Enqueue(F, aux);		

		cout << "Informe um valor para a Fila: ";
		cin >> aux;
		
	}
	
	
	cout << "\n\nO conteudo da fila eh: \n\n";
	
	TNoFila *no_auxiliar;
	
	no_auxiliar = F->Comeco;
	
	while( no_auxiliar != NULL )
	{		 
		cout << no_auxiliar->dado << "\t";
		
		no_auxiliar = no_auxiliar->prox;
	}
	
	
	printf("\n\n");
	return 0;
	
} // main()
