#include <iostream>
#include <math.h>
#include <conio.h>
#include "TABB.h"

using namespace std; 

// CLASSE ÁRVORE BINÁRIA DE BUSCA BALANCEADA- AVL --------------------------------------------

//--------------------------------------------------------------------
//Método Protegido
//--------------------------------------------------------------------
void TABB::Rotacionar()
{
	//se houver algum Nó Desbalanceado ----------
	if(NoDesbalanceado != NULL)
	{
		TNo *no1, *no2;
		
		int FB = GetFB(NoDesbalanceado);
		
		if(FB < 0)
		{
			if(GetFB(NoDesbalanceado->dir) < 0) // - com -
			{
				RSE(NoDesbalanceado, NoDesbalanceado->dir);
			}
			else //- com + ou 0
			{
				RDE(NoDesbalanceado, NoDesbalanceado->dir);
			}
		}
		else
		{
			if(GetFB(NoDesbalanceado->esq) >0 ) // +com+
			{
				RSD(NoDesbalanceado, NoDesbalanceado->esq);
			}
			else // + com - ou 0
			{
				RDD(NoDesbalanceado, NoDesbalanceado->esq);
			}
		}
		
		NoDesbalanceado = NULL;
		
	} // se a arvore estiver desbalanceada
	
} // rotacionar();

//-------------------------------------------------------------
// Ja utilizados
//----------------------------------------------------------------------------------
void TABB::InserirNo(TInfo valor)
{
	InserirNo(Raiz, valor);
	
	Recalcular_Altura(Raiz);
	
	Rotacionar();
} 

//----------------------------------------------------------------------------------
void TABB::InserirNo(TNo *&No, TInfo valor)
{
	if( No != NULL )
	{
		No->h = -1;
		
		if( valor < No->dado )
		{
			InserirNo( No->esq, valor);
		}
		else
		{
			InserirNo( No->dir, valor);
		}
	}
	else
	{
		No       = new TNo;
		No->dado = valor;
		No->esq  = NULL;
		No->dir  = NULL;
		
		No->h    = 1;
	}
		
} // InserirNo(TNo *No, TInfo valor)*/

//----------------------------------------------------------------------------------
TABB::TNo* TABB::LocalizarNo(TInfo valor)
{
	return LocalizarNo(Raiz, valor);
}

//----------------------------------------------------------------------------------
TABB::TNo* TABB::LocalizarNo(TNo *No, TInfo valor)
{
	if( No != NULL )
	{
		if( valor == No->dado )
		{
			return No;
		}		
		else
		if( valor < No->dado )
		{
			return LocalizarNo( No->esq, valor);
		}
		else
		{
			return LocalizarNo( No->dir, valor);
		}
	}
	else
	{
		return NULL;
	}
		
} // TABB::TNo* TABB::LocalizarNo(TNo *No, TInfo valor)

//----------------------------------------------------------------------------------
void TABB::Init()
{
	Raiz = NULL;	
	
} // void TABB::Init()

//----------------------------------------------------------------------------------
bool TABB::IsEmpty()
{
	return Raiz == NULL;	
	
} // void TABB::IsEmpty()

//----------------------------------------------------------------------------------
TABB::TNo* TABB::CriarRaiz(TInfo dado)
{
	if( IsEmpty() )
	{
		Raiz = new TNo;
		Raiz->dado = dado;		
		Raiz->esq = NULL;
		Raiz->dir = NULL;
		return Raiz;
	}
	else 
	{
		printf("A arvore ja possui uma raiz !");
		return NULL;
	}
	
} // TNo TABB::CriarRaiz(TInfo dado)

//----------------------------------------------------------------------------------

TABB::TNo* TABB::GetRaiz()
{
	return Raiz;
	
} // TNo TABB::GetRaiz()

//--- CONSTRUTOR -------------------------------------------------------------------------------
TABB::TABB()
{
	Init();
	
} // TABB()

//--- DESTRUTOR --------------------------------------------------------------------------------
TABB::~TABB()
{
	while( !IsEmpty() ) Remover(Raiz->dado);
	
} // ~TABB()

//----------------------------------------------------------------------------------
void TABB::print_elementos_da_arvore()
{
	print_elementos_da_arvore(Raiz);
	
} // print_elementos_da_arvore()

//----------------------------------------------------------------------------------
void TABB::print_elementos_da_arvore(TNo *no)
{
	
	if( IsEmpty() )
	{
		printf("\n\nARVORE VAIZA!!!\n\n");
		return;
	}
	
	if( no != NULL )
	{
		if(no->esq != NULL || no->dir != NULL){
			
			
			printf("\n  %d(%d)", no->dado, Altura(no));
			
			printf("\n / \\\n");
			
			if( no->esq != NULL ) printf("%d(%d)", no->esq->dado, Altura(no->esq));
			if( no->dir != NULL ) printf("   %d(%d)", no->dir->dado, Altura(no->dir));
			
			if( no->esq != NULL ) print_elementos_da_arvore(no->esq);
			if( no->dir != NULL ) print_elementos_da_arvore(no->dir);
		}
	}
	
} // void TABB::print_elementos_da_arvore(TNo *no)

//----------------------------------------------------------------------------------
void TABB::print_caminhamento_em_pre_ordem(TNo *no)
{
	if( no != NULL )
	{
		printf("%d ", no->dado);
		print_caminhamento_em_pre_ordem(no->esq);
		print_caminhamento_em_pre_ordem(no->dir);
	}	
	
} // print_caminhamento_em_pre_ordem

//----------------------------------------------------------------------------------
void TABB::print_caminhamento_em_in_ordem(TNo *no)
{
	if( no != NULL )
	{
		print_caminhamento_em_in_ordem(no->esq);
		printf("%d ", no->dado);
		print_caminhamento_em_in_ordem(no->dir);
	}	
	
} // print_caminhamento_em_in_ordem

//----------------------------------------------------------------------------------
void TABB::print_caminhamento_em_pos_ordem(TNo *no)
{
	if( no != NULL )
	{
		print_caminhamento_em_pos_ordem(no->esq);
		print_caminhamento_em_pos_ordem(no->dir);
		printf("%d ", no->dado);
	}	
	
} // print_caminhamento_em_pos_ordem

//----------------------------------------------------------------------------------
bool TABB::Remover(TInfo Elemento)
{
	TNo* aux;
	
	aux = LocalizarNo(Raiz, Elemento);
	
	if( aux != NULL )
	{
		// Caso 1 : Nó não possui filho
		if( aux->esq == NULL && aux->dir == NULL ) 
		{
			RemoverCaso1(aux);
			return true;
		}
		else
		// Caso 2 : Nó possui apenas um filho
		if( (aux->esq == NULL && aux->dir != NULL) || (aux->esq != NULL && aux->dir == NULL) )
		{
			RemoverCaso2(aux);
			return true;
		}
		else
		// Caso 3 : Nó possui dois filhos
		{
			RemoverCaso3(aux);
			return true;
		}		
	}
	else
	{
		cout << "\n\nO elemento " << Elemento << " nao esta cadastrado na arvore !!!\n\n";
		return false;
	}

} // bool TABB::Remover(TInfo Elemento)


//----------------------------------------------------------------------------------
void TABB::RemoverCaso1(TNo *&no)
{		
	if( no != Raiz )
	{
		TNo* pai;

		// obtendo o Pai do nó a ser excluido
		pai = Pai(Raiz, no->dado);

		// retirando o vínculo do pai com o filho
		if( pai->esq == no )
		{
			pai->esq = NULL;
		}
		else
		{
			pai->dir = NULL;
		}
		
		//Atualizando as alturas e rotacionar
		// caso seja Necessario
		Negativar_H(Raiz, pai->dado);
		Recalcular_Altura(Raiz);
		Rotacionar();
		

		// eliminando o nó
		delete(no);	
		no = NULL;
	}
	else
	{
		// eliminando o nó Raiz
		delete(Raiz);	
		Raiz = NULL;
	}	
} // void TABB::RemoverCaso1(TNo* no)

//----------------------------------------------------------------------------------
void TABB::RemoverCaso3(TNo *no)
{		
	TInfo aux;
	TNo *no_maior;
	
	no_maior = Maior( no->esq->dado );
	
	aux = no_maior->dado;
	
	Remover(no_maior->dado);
	
	no->dado = aux;	
	
} // void TABB::RemoverCaso3(TNo *no)


//----------------------------------------------------------------------------------
void TABB::RemoverCaso2(TNo *&no)
{	
	TNo *filho;
	
	// obtendo o filho do nó a ser excluido
	if( no->esq != NULL ) filho = no->esq;
	if( no->dir != NULL ) filho = no->dir;

	// se o nó a ser excluido não for a raiz
	if( no != Raiz ) 
	{
		TNo *pai;
	
		// obtendo o Pai do nó a ser excluido
		pai = Pai(Raiz, no->dado);
		
		// fazendo com que o nó filho do nó a ser excluido ocupe o lugar do nó a ser removido
		if( pai->esq == no )
		{
			pai->esq = filho;
		}
		else
		{
			pai->dir = filho;
		}
		
	} // no != Raiz
	else
	{
		Raiz = filho;
	}
	
	//Atualizando as alturas e rotacionar
	// caso seja Necessario
	Negativar_H(Raiz, filho->dado);
	Recalcular_Altura(Raiz);
	Rotacionar();
	
	// eliminando o no
	delete(no);
	no = NULL;
	
} // void TABB::RemoverCaso2(TNo* no)



/*/---------------------------------------------------------------------------------
TABB::TNo* TABB::Pai_Velho(TNo *no, TInfo Elemento)
{
	TNo* aux;
	
	if( IsEmpty() ) return NULL;
	
	// o Pai da Raiz é a própria Raiz ---------
	if( Raiz->dado == Elemento ) return Raiz;	
	
	if( no != NULL  )
	{
		if( no->esq != NULL && no->esq->dado == Elemento ) return no;
		
		if( no->dir != NULL && no->dir->dado == Elemento) return no;
		
		// Analisando a Subarvore da Esquerda -----------
		aux = Pai(no->esq, Elemento);		
		if( aux != NULL )
		{
			if( aux->esq != NULL && aux->esq->dado == Elemento) return aux;
			if( aux->dir != NULL && aux->dir->dado == Elemento) return aux;
		}
		
		// Analisando a Subarvore da Direita -----------
		aux = Pai(no->dir, Elemento);
		if( aux != NULL )
		{
			if( aux->esq != NULL && aux->esq->dado == Elemento) return aux;
			if( aux->dir != NULL && aux->dir->dado == Elemento) return aux;
		}
						
	} // if( no != NULL )	
	else
	{
		return NULL;
	}
} // Pai_Velhor()*/

//----------------------------------------------
TABB::TNo* TABB::Pai(TNo *no, TInfo Elemento)
{
	TNo* aux;
	
	if(IsEmpty()) return NULL;
	
	if( no == NULL) return NULL;
	
	//o Pai da Raiz é a propria Raiz ----
	if(Raiz->dado == Elemento)return Raiz;
	
	if(Elemento > no->dado)
	{
		if(no->dir != NULL)
		{
			if(no->dir->dado == Elemento)
			{
				return no;
			}
			else
			{
				return Pai(no->dir, Elemento);
			}
			
		}
	}
	else
	{
		if(no->esq != NULL)
		{
			if(no->esq->dado == Elemento)
			return no;
			else
			return Pai(no->esq, Elemento);
		}
	}
	
} // Pai(TNo *no, Tinfo ELEMENTO)



//----------------------------------------------------------------------------------
TABB::TNo* TABB::Maior(TInfo elemento)
{
	if( IsEmpty() ) 
	{
		cout << "\n\nArvore vazia !!!\n\n";
		return NULL;
	}
	
	TNo *no;
	
	no = LocalizarNo(Raiz, elemento);
	
	if( no == NULL  ) 
	{
		cout << "\n\nNo nao encontrado !!!\n\n";
		return NULL;
	}
	
	while( no->dir != NULL )
	{
		no = no->dir;
	}
	
	return no;	
	
} // Maior(TInfo elemento)

//----------------------------------------------------------------------------------
TABB::TNo* TABB::Menor(TInfo elemento)
{
	if( IsEmpty() ) 
	{
		cout << "\n\nArvore vazia !!!\n\n";
		return NULL;
	}
	
	TNo *no;
	
	no = LocalizarNo(Raiz, elemento);
	
	if( no == NULL  ) 
	{
		cout << "\n\nNo nao encontrado !!!\n\n";
		return NULL;
	}

	while( no->esq != NULL )
	{
		no = no->esq;
	}
	
	return no;	
	
} // Maior(TInfo elemento)

//--- Obtem o Nível de um Nó utilizando O Método Pai -------------------------------
int TABB::Nivel(TInfo Elemento)
{
	
	TNo *n = LocalizarNo(GetRaiz(), Elemento);
	
	int nivel;
	
	if( n != NULL )
	{
		nivel = 0;
		while( n != GetRaiz() )
		{
			n = Pai(GetRaiz(), n->dado);
			nivel++;
		}
		
		return nivel;
	}
	else
	{
		return -1;
	}
	 
} // int TABB::Nivel(TInfo Elemento)

//----------------------------------------------------------------------------------
int TABB::TotalNos(TNo *no) 
{
    if (no == NULL) return 0;
    
    return TotalNos(no->esq) + TotalNos(no->dir) + 1;
    
} // TotalNos()

//--- Altura da Árvore = Maior Nível -----------------------------------------------
int TABB::Altura(TNo *no)
{
    int i, j, retorno;
    
    if (no == NULL) 
	{
		return 0;
	}
	
    i = Altura(no->esq);
    j = Altura(no->dir);    
    
    if (i > j) 
    {
    	retorno = i+1;
	}
	else
	{
		retorno = j+1;	
	}
	
	return retorno;
	 
} // Altura() 


//=============================================
//Atualiza a altura (h) de cada nó da árvore
// Na chamada da função, passa-se a Raiz como parametro
//==================================================
int TABB::Recalcular_Altura(TNo* no)
{
	int hDir;// Altura da sub-árvore da direita do nó
	int hEsq;// Altura da sub-árvore da esquerda do nó
	
	//a altura de uma sub-arvore vazia é zero
	if(no == NULL)return 0;
	
	// se a altura já estiver cadastrada retorne ela
	if( no->h != -1) return no->h;
	
	//obtendo a alatura da sub-arvore da direita
	if(no->dir != NULL)
	{
		if(no->dir->h != -1)
		{
			hDir = no->dir->h;
		}
		else
		{
			hDir = Recalcular_Altura( no->dir);
		}
	}
	else
	{
		hDir =0;
	}
	
	// obtendo a altura da sub-árvore da direita
	if(no->esq != NULL)
	{
		if(no->esq->h != -1)
		{
			hEsq = no->esq->h;
		}
		else
		{
			hEsq = Recalcular_Altura( no->esq);
		}
	}
	else
	{
		hEsq =0;
	}
	
	if( hEsq > hDir)
	{
		no->h = hEsq +1; //1+ pq é a altura da sub-árvore + a altura do nó atual
	}
	else
	{
		no->h = hDir +1;	
	}
	
	int FB = abs(hEsq - hDir); // Fator de Balanceamento
	
	if(FB > 1) // se estiver desbalanceado
	{
		if(NoDesbalanceado == NULL)
		{
			NoDesbalanceado = no;
		}
		else
		{
			// se a altura do altual nó for menor que a altura do nó desbalanceado
			if( no->h < NoDesbalanceado->h)
			{
				NoDesbalanceado = no;
			}
		}
	}	
	
	return no->h;
	
}// Recalcular_Altura();

//------------------------------------------------------
//Metodo Protegido para Obter o fator de balanceamento
//de um determinado Nó
//---------------------------------------------------------
int TABB::GetFB(TNo* no)
{
	int hE, hD;
	
	if(no == NULL) return 0;
	
	if( no->esq == NULL)
		hE =0;
	else
		hE = no->esq->h;
		
	if( no->dir == NULL)
		hD =0;
	else
		hD = no->dir->h;
		
	
	return hE - hD;
	
}// int Get FB (TNo* no)

//==============================================================
// Negativar "apagar" as alturas no nó Raiz até um determinado nó
//Nas chamada da função deve-se passar a Raiz como parametro
//==================================================================
void TABB::Negativar_H(TNo* no, TInfo valor)
{
	if(no == NULL) return;
	
	no->h = -1;
	
	if(valor== no->dado) return;
	
	if(valor < no->dado)
	{
		Negativar_H(no->esq, valor);
	}
	else
	{
		Negativar_H(no->dir, valor);
	}
}//  void TABB::Negativar_H(TNo* no, TInfo valor)

void TABB::RSE(TNo* no1, TNo* no2)
{
	TNo* pai, *aux;
	
	pai= Pai(Raiz, no1->dado);
	
	if(no1 == Raiz)
	{
		Raiz = no2;
	}
	else
	{
		if(pai->dir == no1)
			pai->dir = no2;
		else
			pai->esq = no2;
	}
	
	if(no2->esq == NULL)
	{
		no2->esq = no1;
		no1->dir = NULL;
	}
	else
	{
		aux = no2->esq;
		no2->esq = no1;
		no1->dir = aux;
	}
	
	Negativar_H(Raiz, no1->dado);
	Recalcular_Altura(Raiz);

}// RSE(no1, no2)


void TABB::RSD(TNo* no1, TNo* no2)
{
	TNo* pai, *aux;
	
	pai= Pai(Raiz, no1->dado);
	
	if(no1 == Raiz)
	{
		Raiz = no2;
	}
	else
	{
		if(pai->dir == no1)
			pai->dir = no2;
		else
			pai->esq = no2;
	}
	
	if(no2->dir == NULL)
	{
		no2->dir = no1;
		no1->esq = NULL;
	}
	else
	{
		aux = no2-> dir;
		no2->dir = no1;
		no1->esq = aux;
	}
	
	Negativar_H(Raiz, no1->dado);
	Recalcular_Altura(Raiz);

}// RSD(no1, no2)

//===============================================
//Rotação Dupla á Esquerda
void TABB::RDE(TNo* no1, TNo* no2)
{
	RSD(no1->dir, no2->esq);
	
	RSE(no1, no1->dir);
	
}// RDE(TNo* no1, TNo* no2


//===============================================
//Rotação Dupla á Esquerda
void TABB::RDD(TNo* no1, TNo* no2)
{
	RSE(no1->esq, no2->dir);
	
	RSD(no1, no1->esq);
	
}// RDD(TNo* no1, TNo* no2)
