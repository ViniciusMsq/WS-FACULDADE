#ifndef TABB_H
#define TABB_H

// CLASSE ÁRVORE BINÁRIA DE BUSCA - ABB ---------------------------------------------

class TABB
{
	//-----------------------------------------------
	public:		
		typedef int TInfo;
		
		struct TNo {	
			TInfo dado;	
			TNo *esq, *dir;
		};
		
		TNo *Raiz;

		bool IsEmpty();
		TNo* CriarRaiz(TInfo dado);		
		TNo* GetRaiz();		


		// Métodos sobrecarregados : Polimorfismo -------------------
		void InserirNo(TInfo valor);
		void InserirNo(TNo *&No, TInfo valor);

		// Métodos sobrecarregados : Polimorfismo -------------------
		TNo* LocalizarNo( TInfo valor );
		TNo* LocalizarNo(TNo *No, TInfo valor);
		
		bool Remover(TInfo Elemento);
						
		// Métodos sobrecarregados : Polimorfismo -------------------
		void print_elementos_da_arvore();        
		void print_elementos_da_arvore(TNo *no);
		
		void print_caminhamento_em_pre_ordem(TNo *no);
		void print_caminhamento_em_in_ordem(TNo *no);
		void print_caminhamento_em_pos_ordem(TNo *no);
		
		TNo* Pai(TNo *no, TInfo Elemento);
		
		TNo* Maior(TInfo elemento);
		TNo* Menor(TInfo elemento);
		
		int Nivel(TInfo Elemento);
		int TotalNos(TNo *no); 
		int Altura(TNo *no);
			
		TABB();  // construtor
		~TABB(); // destrutor
		
	//-----------------------------------------------
	protected:
		
		void Init();

		void RemoverCaso1(TNo *&no);
		void RemoverCaso2(TNo *&no);
		void RemoverCaso3(TNo *no);
		
	//-----------------------------------------------
	private:
		
}; // TABB

#endif
