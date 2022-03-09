
#include "includes.h"

typedef struct Nodo {
	int numero; 
    struct Nodo *prox;
} Lista;
   

void CriaLista(Lista *&L)
{
   	//L = (Lista*)malloc (sizeof(Lista));
   	L=NULL;
    //L->prox = NULL;
}

bool ListaVazia(Lista *L)
{
	if(L== NULL)
		return true;
	else
		return false;
}

void InsereLista(Lista *&L, int v)
{
	Lista *nova = (Lista*)malloc (sizeof(Lista));
	nova->numero = v;
	nova->prox = L;
	L= nova;	
}

//pega o ultimo elemento
void PegaInformacao(Lista *&L, int &v)
{	
	if(L != NULL)
	{
		v = L->numero;
		L = L->prox;
	}
	
}

//Retira o ultimo elemento
void RetiraLista(Lista *&L)
{
	Lista *comeco = L; 
	
	if(L != NULL)
	{
		L = comeco->prox;
		free(comeco);
		comeco = NULL;
	}
}

void MostraLista (Lista *L) {
   if (L != NULL) {
      cout << "\n" << L->numero;
      MostraLista (L->prox);
   }
}
