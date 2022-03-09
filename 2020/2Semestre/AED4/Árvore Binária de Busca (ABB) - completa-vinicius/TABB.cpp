#include "TABB.h"
#include "funcoes.h"
#include <iostream>

using namespace std; 

// CLASSE ÁRVORE BINÁRIA DE BUSCA - ABB --------------------------------------------

//----------------------------------------------------------------------------------
void TABB::InserirNo(TNo *&No, TInfo valor)
{
	if( No != NULL )
	{
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
		No = new TNo;
		No->dado = valor;
		No->esq = NULL;
		No->dir = NULL;
	}
		
} // InserirNo(TNo *No, TInfo valor)

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
	
} // ~TABB()

//----------------------------------------------------------------------------------
void TABB::print_arvore(TNo *no, int x, int y)
{
	int nivel, altura, dx;
	
	if( IsEmpty() )
	{
		printf("\n\nARVORE VAIZA!!!\n\n");
		return;
	}
	
	nivel = Nivel(no->dado);
	altura = Altura(Raiz);
	
	
	//dx = -6 * nivel + 20;
	//dx = 
			
	switch( nivel )
	{
		case 0 : dx = 40; break;
		case 1 : dx = 20; break;
		case 2 : dx = 10; break;
		case 3 : dx =  5; break;
		default : dx = 2; break;
	}
	
	if( nivel == 0 )
	{
		dx = (altura * 8);
	}
	else
	{
		dx = (altura * 8) / (nivel+2);
	}
	
	
	if( no != NULL )
	{
		gotoxy(x, y + nivel * 4);
		printf("%2d", no->dado);
		
		if( no->esq != NULL ) 
		{
//			gotoxy(x-2, y + Nivel(no->dado) );
//			printf("/");
//			y = y + 2;
			
			print_arvore(no->esq, x - dx, y);
		}
		
		if( no->dir != NULL ) 
		{
//			gotoxy(x+2, y + Nivel(no->dado)  );
//			printf("\\");
//			y = y + 2;
			
			print_arvore(no->dir, x + dx, y);
		}
	}
	
} // void TABB::print_elementos_da_arvore(TNo *no)


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
		printf("\n  %d", no->dado);
		
		printf("\n / \\\n");
		
		if( no->esq != NULL ) printf("%d", no->esq->dado);
		if( no->dir != NULL ) printf("    %d", no->dir->dado);
		
		if( no->esq != NULL ) print_elementos_da_arvore(no->esq);
		if( no->dir != NULL ) print_elementos_da_arvore(no->dir);
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
		// Caso 2 : Nó possui apenas um filho
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
	
	// eliminando o no
	delete(no);
	no = NULL;
	
} // void TABB::RemoverCaso2(TNo* no)



//----------------------------------------------------------------------------------
TABB::TNo* TABB::Pai(TNo *no, TInfo Elemento)
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
} // Pai()

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
		return -1;
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

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------



















