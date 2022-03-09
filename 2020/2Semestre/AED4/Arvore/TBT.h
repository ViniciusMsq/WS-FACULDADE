#ifndef TBT_H
#define TBT_H

class TBT
{
	public:
		typedef char TInfo;
		
		struct TNo{
			TInfo dado;
			TNo *esq, *dir;
		};
		
		bool IsEmpty();
		TNo* CriarRaiz(TInfo dado);
		TNo* Insere_No_Direito(TNo *Pai, TInfo dado);
		TNo* Insere_No_Esquerdo(TNo *Pai, TInfo dado);
		void Print_caminhamento_em_pre_ordem(TNo *no);
		void Print_caminhamento_em_in_ordem(TNo* no);
		void Print_caminhamento_em_pos_ordem(TNo* no);
		TNo* GetRaiz();
		int TotalNos(TNo *no);
		int Altura(TNo *no);
		TNo* BuscarNo(TNo *no, TInfo Elemento);
		void ExcluirNo(TInfo Elemento);
		TNo* Pai(TNo *no, TInfo Elemento);
		int Nivel(TInfo Elemento);
		TBT();
		~TBT();
		
	protected:
		TNo *Raiz;
		void Init();
		void Deserdar(TNo *no, TInfo Elemento);
		void ExcluirDescendentes(TNo *no);
		
};

#endif
