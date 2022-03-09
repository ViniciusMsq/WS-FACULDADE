#include <iostream>
#include "TBT.h"

void TBT::Init() {
	Raiz = NULL;
}

bool TBT::IsEmpty() {
	return Raiz == NULL;
}

TBT::TNo* TBT::CriarRaiz(TInfo dado) {
	Raiz = new TNo;
	Raiz->dado = dado;
	Raiz->esq = NULL;
	Raiz->dir = NULL;

	return Raiz;
}

TBT::TNo* TBT::Insere_No_Direito(TNo* Pai, TInfo dado) {
	TNo* filho;
	filho = new TNo;
	filho->dado = dado;
	filho->esq = NULL;
	filho->dir = NULL;
	Pai->dir = filho;

	return filho;
}

TBT::TNo* TBT::Insere_No_Esquerdo(TNo* Pai, TInfo dado) {
	TNo* filho;
	filho = new TNo;
	filho->dado = dado;
	filho->esq = NULL;
	filho->dir = NULL;
	Pai->esq = filho;

	return filho;
}

void TBT::Print_caminhamento_em_pre_ordem(TNo* no) {
	if (no != NULL) {
		printf("%c", no->dado);
		Print_caminhamento_em_pre_ordem(no->esq);
		Print_caminhamento_em_pre_ordem(no->dir);
	}
}

void TBT::Print_caminhamento_em_in_ordem(TNo* no) {
	if (no != NULL) {
		
		Print_caminhamento_em_in_ordem(no->esq);
		printf("%c", no->dado);
		Print_caminhamento_em_in_ordem(no->dir);
	}
}

void TBT::Print_caminhamento_em_pos_ordem(TNo* no) {
	if (no != NULL) {
		
		Print_caminhamento_em_pos_ordem(no->esq);
		Print_caminhamento_em_pos_ordem(no->dir);
		printf("%c", no->dado);
	}
}

TBT::TNo* TBT::GetRaiz() {
	return Raiz;
}

int TBT::TotalNos(TNo* no) {
	if (no == NULL) {
		return 0;
	}
	return TotalNos(no->esq) + TotalNos(no -> dir) + 1;
}

int TBT::Altura(TNo* no) {
	int i, j, retorna;

	if (no == NULL) {
		return -1;
	}

	i = Altura(no->esq);
	j = Altura(no->dir);

	if (i > j) {
		retorna = i + 1;
	}
	else {
		retorna = j + 1;
	}

	return retorna;
}

TBT::TNo* TBT::BuscarNo(TNo* no, TInfo Elemento) {
	TNo* aux;

	if (no != NULL) {
		if (no->dado != Elemento) {
			aux = BuscarNo(no->esq, Elemento);

			if (aux != NULL && aux->dado == Elemento) {
				return aux;
			}

			aux = BuscarNo(no->dir, Elemento);

			return aux;
		}
		else {
			return no;
		}
	}
	else {
		return NULL;
	}
}

void TBT::ExcluirNo(TInfo Elemento) {
	TNo* no;

	no = BuscarNo(GetRaiz(), Elemento);

	if (Raiz->dado != Elemento) {
		Deserdar(GetRaiz(), Elemento);
		ExcluirDescendentes(no);
	}
	else {
		ExcluirDescendentes(no);
		Raiz = NULL;
	}
}

void TBT::Deserdar(TNo* no, TInfo Elemento) {
	
	if (no != NULL && no->esq != NULL) {
		if (no->esq->dado == Elemento) {
			no->esq = NULL;
		}
		else {
			Deserdar(no->esq, Elemento);
			Deserdar(no->dir, Elemento);
		}
	}
	else {
		if (no != NULL && no->dir != NULL) {
			if (no->dir->dado == Elemento) {
				no->dir = NULL;
			}
			else {
				Deserdar(no->esq, Elemento);
				Deserdar(no->dir, Elemento);
			}
		}
	}
}

void TBT::ExcluirDescendentes(TNo* no) {

	if (no != NULL) {
		ExcluirDescendentes(no->esq);
		ExcluirDescendentes(no->dir);
		delete(no);
		no = NULL;
	}
}


TBT::TNo* TBT::Pai(TNo* no, TInfo Elemento) {

	TNo* aux;

	if (IsEmpty()) {
		return NULL;
	}
	if (Raiz->dado == Elemento){
		return Raiz;
	}

	if (no != NULL) {
		
		if (no->esq != NULL && no->esq->dado == Elemento) {
			return no;
		}
		if (no->dir != NULL && no->dir->dado == Elemento) {
			return no;
		}

		aux = Pai(no->esq, Elemento);
		if (aux != NULL) {
			if (no->esq != NULL && no->esq->dado == Elemento) {
				return aux;
			}
			if (no->dir != NULL && no->dir->dado == Elemento) {
				return aux;
			}
		}

		aux = Pai(no->dir, Elemento);
		if (aux != NULL) {
			if (no->esq != NULL && no->esq->dado == Elemento) {
				return aux;
			}
			if (no->dir != NULL && no->dir->dado == Elemento) {
				return aux;
			}
		}
	}
	else {
		return NULL;
	}
}

int TBT::Nivel(TInfo Elemento) {

	TNo* n = BuscarNo(GetRaiz(), Elemento);

	int nivel;

	if (n != NULL) {
		nivel = 0;
		while (n != GetRaiz()) {
			n = Pai(GetRaiz(), n->dado);
			nivel++;
		}
		return nivel;
	}
	else {
		return -1;
	}
}

TBT::TBT() {
	void init();
}

TBT::~TBT() {
	if (!IsEmpty()) {
		ExcluirNo(Raiz->dado);
	}
}

