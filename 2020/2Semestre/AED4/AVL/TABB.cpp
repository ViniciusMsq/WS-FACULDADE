#include <iostream>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include "TABB.h"

using namespace std; 

// CLASSE �RVORE BIN�RIA DE BUSCA BALANCEADA - AVL --------------------------------------------

//----------------------------------------------------------------------------------
// M�todo Protegido
//----------------------------------------------------------------------------------
void TABB::Rotacionar()
{	
	// se houver algum N� Desbalanceado ---------	
	if( NoDesbalanceado != NULL )
	{
		TNo *no1, *no2;
		
		int FB = GetFB(NoDesbalanceado); 
		
		if( FB < 0 )
		{
			if( GetFB(NoDesbalanceado->dir) < 0 ) // - com -
			{
				RSE(NoDesbalanceado, NoDesbalanceado->dir);
			}
			else // - com + ou 0
			{
				RDE(NoDesbalanceado, NoDesbalanceado->dir);
			}
		}
		else
		{
			if( GetFB(NoDesbalanceado->esq) > 0 ) // + com +
			{
				RSD(NoDesbalanceado, NoDesbalanceado->esq);
			}
			else // + com - ou 0
			{
				RDD(NoDesbalanceado, NoDesbalanceado->esq);
			}
			
		}
		
		NoDesbalanceado = NULL;
		
	} // se a �rvore estiver Desbalanceada
	
} // Rotacionar()

//----------------------------------------------------------------------------------
// M�todo P�blico
void TABB::InserirNo(TInfo valor)
{
	InserirNo(Raiz, valor);
	
	Recalcular_Altura(Raiz);	
	
	Rotacionar();
	
} // inserir n� p�blico

//----------------------------------------------------------------------------------
// M�todo Protegido
void TABB::InserirNo(TNo *&No, TInfo valor)
{
	if( No != NULL )
	{
		No->h = -1; // "Apagando a altura do N�" ou Marcando o n� para rec�lculo de sua altura
		
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
		
		No->h	 = 1;
	}
		
} // InserirNo(TNo *No, TInfo valor)

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
	
	NoDesbalanceado = NULL;
	
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
	
	// para n�o imprimir os n�s folhas que n�o seja a raiz, pois seria redundante
	if( no->esq == NULL && no->dir == NULL && no != Raiz )	return;
	
	if( no != NULL )
	{
		printf("\n\n  %d(%d)", no->dado, no->h);
		
		printf("\n / \\\n");
		
		if( no->esq != NULL ) printf("%d(%d)", no->esq->dado, no->esq->h);
		if( no->dir != NULL ) printf("    %d(%d)", no->dir->dado, no->dir->h);
		
		printf("\n");
		
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
		// Caso 1 : N� n�o possui filho
		if( aux->esq == NULL && aux->dir == NULL ) 
		{
			RemoverCaso1(aux);
			return true;
		}
		else
		// Caso 2 : N� possui apenas um filho
		if( (aux->esq == NULL && aux->dir != NULL) || (aux->esq != NULL && aux->dir == NULL) )
		{
			RemoverCaso2(aux);
			return true;
		}
		else
		// Caso 3 : N� possui dois filhos
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
	
			// obtendo o Pai do n� a ser excluido
			pai = Pai(Raiz, no->dado);
	
			// retirando o v�nculo do pai com o filho
			if( pai->esq == no )
			{
				pai->esq = NULL;
			}
			else
			{
				pai->dir = NULL;
			}
			
			// Atualizando as Alturas e Rotacionar 
			// caso seja Necess�rio-------------
			Negativar_H(Raiz, pai->dado);
			Recalcular_Altura(Raiz);	
			Rotacionar();
			
			// eliminando o n�
			delete(no);	
			no = NULL;
		}
		else
		{
			// eliminando o n� Raiz
			delete(Raiz);	
			Raiz = NULL;
		}	
	} // void TABB::RemoverCaso1(TNo* no)


	//----------------------------------------------------------------------------------
	void TABB::RemoverCaso2(TNo *&no)
	{	
		TNo *filho;
		
		// obtendo o filho do n� a ser excluido
		if( no->esq != NULL ) filho = no->esq;
		if( no->dir != NULL ) filho = no->dir;
	
		// se o n� a ser excluido n�o for a raiz
		if( no != Raiz ) 
		{
			TNo *pai;
		
			// obtendo o Pai do n� a ser excluido
			pai = Pai(Raiz, no->dado);
			
			// fazendo com que o n� filho do n� a ser 
			// excluido ocupe o lugar do n� a ser removido
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
			
		// Atualizando as Alturas e Rotacionar caso seja Necess�rio-------------
		Negativar_H(Raiz, filho->dado);
		Recalcular_Altura(Raiz);	
		Rotacionar();
			
		// eliminando o no
		delete(no);
		no = NULL;
		
	} // void TABB::RemoverCaso2(TNo* no)

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
TABB::TNo* TABB::Pai_VELHO(TNo *no, TInfo Elemento)
{
	TNo* aux;
	
	if( IsEmpty() ) return NULL;
	
	// o Pai da Raiz � a pr�pria Raiz ---------
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
} // Pai_VELHO()

//----------------------------------------------------------------------------------
TABB::TNo* TABB::Pai(TInfo Elemento)
{
	return Pai(Raiz, Elemento);
	
} // Pai(TInfo Elemento)

//----------------------------------------------------------------------------------
TABB::TNo* TABB::Pai(TNo *no, TInfo Elemento)
{
	TNo* aux;
	
	if( IsEmpty() ) return NULL;
	
	if( no == NULL ) return NULL;
	
	// o Pai da Raiz � a pr�pria Raiz ---------
	if( Raiz->dado == Elemento ) return Raiz;	
	
	if( Elemento > no->dado )
	{
		if( no->dir != NULL ) 
		{
			if( no->dir->dado == Elemento )
				return no;
			else
				return Pai(no->dir, Elemento);
		}
	}
	else
	{
		if( no->esq != NULL ) 
		{
			if( no->esq->dado == Elemento )
				return no;
			else
				return Pai(no->esq, Elemento);
		}
	}
	
} // Pai(TNo *no, TInfo Elemento)

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

//--- Obtem o N�vel de um N� utilizando O M�todo Pai -------------------------------
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

//--- Altura da �rvore = Maior N�vel -----------------------------------------------
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


//================================================================================
// Atualiza a altura (h) de cada n� da �rvore marcado como h=-1
// Na chamada da fun��o, passa-se a Raiz como par�metro 
//================================================================================
int TABB::Recalcular_Altura(TNo* no)
{
	int hDir; // Altura da sub-�rvore da direita do n�
	int hEsq; // Altura da sub-�rvore da esquerda do n�
	
	// a altura de uma sub-�rvore vazia � zero
	if( no == NULL ) return 0; 
	
	// se a altura j� estiver cadastrada retorne ela
	if( no->h != -1 ) return no->h; 

	// obtendo a altura da sub-�rvore da direita
	if( no->dir != NULL )
	{
		if( no->dir->h != -1 )
		{		
			hDir = no->dir->h;
		}
		else
		{
			hDir = Recalcular_Altura( no->dir );
		}
	}
	else
	{
		hDir = 0;
	}

	// obtendo a altura da sub-�rvore da direita
	if( no->esq != NULL )
	{
		if( no->esq->h != -1 )
		{		
			hEsq = no->esq->h;
		}
		else
		{
			hEsq = Recalcular_Altura( no->esq );
		}
	}
	else
	{
		hEsq = 0;
	}
	
	// Calculando a altura do n� --------------------
	if( hEsq > hDir )		
		no->h = hEsq + 1; // +1 pq � a altura da sub-�rvore + a altura do n� atual
	else
		no->h = hDir + 1;
				
	// Verificando se o n� est� Desbalanceado -------	
	int FB = abs(hEsq - hDir);	// M�dulo do Fator de Balanceamento
	
	if( FB > 1 ) // se estiver desbalanceado
	{
		if( NoDesbalanceado == NULL )
		{
			NoDesbalanceado = no;
		}
		else
		{
			// se a altura do atual n� for menor que a altura do n� desbalanceado
			if(  no->h < NoDesbalanceado->h  )
			{
				NoDesbalanceado = no;
			}
		}
	}
		
	return no->h;	

} // Recalcular_Altura()

//----------------------------------------------------------------------------------
// M�todo Protegido para Obter o Fator de Balanceamento
// de um determinado N�
//----------------------------------------------------------------------------------
int TABB::GetFB(TNo* no)
{
	int hE, hD;
	
	if( no == NULL ) return 0;

	if( no->esq == NULL )
		hE = 0;
	else
		hE = no->esq->h;
	
	if( no->dir == NULL )
		hD = 0;
	else
		hD = no->dir->h;
		
		
	return hE - hD;
	
} // int GetFB(TNo* no)

//============================================================================
// Negativa "apaga" as alturas no n� Raiz at� um determinado n�
// Na chamada da fun��o deve-se passar a Raiz como par�metro
//============================================================================
void TABB::Negativar_H(TNo* no, TInfo valor)
{
	if( no == NULL ) return;
	
	no->h = -1;
	
	if( valor == no->dado ) return;
	
	if( valor < no->dado  )
	{
		Negativar_H(no->esq, valor);
	}
	else 
	{
		Negativar_H(no->dir, valor);
	}
	
	return;

} // void TABB::Negativar_H(TNo* no, TInfo valor)

//============================================================================
// Rota��o Simples � Esquerda
//============================================================================
void TABB::RSE(TNo* no1, TNo* no2)
{
	TNo* pai, *aux;
	
	pai = Pai(Raiz, no1->dado);

	if( no1 == Raiz )
	{
		Raiz = no2;
	}
	else
	{
		if( pai->dir == no1 )
		   pai->dir = no2;
		else
		   pai->esq = no2;
	}
	
	if( no2->esq == NULL )
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
	
} // RSE(no1, no2)

//============================================================================
// Rota��o Simples � Direita
//============================================================================
void TABB::RSD(TNo* no1, TNo* no2)
{
	TNo* pai, *aux;
	
	pai = Pai(Raiz, no1->dado);

	if( no1 == Raiz )
	{
		Raiz = no2;
	}
	else
	{
		if( pai->dir == no1 )
		   pai->dir = no2;
		else
		   pai->esq = no2;
	}
	
	if( no2->dir == NULL )
	{		
		no2->dir = no1;
		no1->esq = NULL;
	}
	else
	{
		aux = no2->dir;
		no2->dir = no1;
		no1->esq = aux;
	}
	
	Negativar_H(Raiz, no1->dado);
	Recalcular_Altura(Raiz);	
	
} // RSD(no1, no2)

//============================================================================
// Rota��o Dupla � Esquerda
//============================================================================
void TABB::RDE(TNo* no1, TNo* no2)
{	

	RSD( no1->dir, no2->esq );
	
	RSE( no1, no1->dir );	

} // RDE(TNo* no1, TNo* no2)

//============================================================================
// Rota��o Dupla � Direita
//============================================================================
void TABB::RDD(TNo* no1, TNo* no2)
{
	
	RSE( no1->esq, no2->dir );
	
	RSD( no1, no1->esq );	

} // RDD(TNo* no1, TNo* no2)

	
void TABB::Grafico_gerar_coordenadas(TNo *no, int x)
{ 
    if( no == NULL )return;
    
    int nivel;
    
    nivel = Nivel(no->dado);
    
    no->x = x;
    no->y = nivel * 70 + Grafico_raio + 20;
    
    // Imprimindo o no
    //fillellipse(no->x, no->y, Grafico_raio, Grafico_raio);
    
    //Calculando o x dos nos filhos
    
    nivel = nivel + 1;
    
    int delta = (Grafico_width/2) / pow(2,nivel);
    
    Grafico_gerar_coordenadas(no->esq, x - delta);
    Grafico_gerar_coordenadas(no->dir, x + delta);
	
}// void TABB::Grafico_gerar_coordenadas(TNo *no, int x)

void TABB::Grafico_print_nos(TNo *no)
{
	if( no == NULL )return;
	
	setbkcolor( WHITE );
	setcolor( BLACK );
	
	fillellipse(no->x, no->y, Grafico_raio, Grafico_raio);
	
	Grafico_print_nos(no->esq);
	Grafico_print_nos(no->dir);
}// void TABB::Grafico_print_nos(TNo *no)

void TABB::Grafico_print_ponterios(TNo *no, TNo *no_anterior)
{
	if( no == NULL )return;
	setbkcolor(WHITE);
	setcolor(BLACK);
	
	if(no!=Raiz){
		line(no_anterior->x, no_anterior->y, no->x, no->y);
	}
	Grafico_print_ponterios(no->esq,no);
	Grafico_print_ponterios(no->dir,no);
	
}// void TABB::Grafico_print_ponterios(TNo *no, TNo *no_anterior)
void TABB::Grafico_print_textos(TNo *no)
{
	if( no == NULL )return;
	
	char bufferstr[20];
	
	outtextxy(no->x - Grafico_raio/2, no->y - Grafico_raio/2, itoa(no->dado,bufferstr,10));
	
	Grafico_print_textos(no->esq);
	Grafico_print_textos(no->dir);
	
}// void TABB::Grafico_print_texto(TNo *no)
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------



















