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
			int h; // altura do nó (subárvore)
			
			int x,y;
		};
		
		TNo *Raiz;
		
		bool IsEmpty();
		TNo* CriarRaiz(TInfo dado);		
		TNo* GetRaiz();		

		// Métodos sobrecarregados : Polimorfismo -------------------
		void InserirNo(TInfo valor);		

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
		
		TNo* Pai_VELHO(TNo *no, TInfo Elemento);
		
		TNo* Pai(TInfo Elemento);
		TNo* Pai(TNo *no, TInfo Elemento);
		
		TNo* Maior(TInfo elemento);
		TNo* Menor(TInfo elemento);
		
		int Nivel(TInfo Elemento);
		int TotalNos(TNo *no); 
		int Altura(TNo *no);
			
		TABB();  // construtor
		~TABB(); // destrutor
		
		int Grafico_raio = 15;
		int Grafico_width = 1366; 
		int Grafico_height = 768;
		
		void Grafico_gerar_coordenadas(TNo *no, int x);
		void Grafico_print_nos(TNo *no);
		void Grafico_print_textos(TNo *no);
		void Grafico_print_ponterios(TNo *no, TNo *no_anterior);
		
	//-----------------------------------------------
	protected:
		
		TNo* NoDesbalanceado;
		
		void Init();

		void RemoverCaso1(TNo *&no);
		void RemoverCaso2(TNo *&no);
		void RemoverCaso3(TNo *no);
		
		void InserirNo(TNo *&No, TInfo valor);
		
		int Recalcular_Altura(TNo* no);
		
		int GetFB(TNo* no);
		
		void Negativar_H(TNo* no, TInfo valor);
		
		// Rotações ----
		void RSD(TNo* no1, TNo* no2);
		void RSE(TNo* no1, TNo* no2);
		void RDE(TNo* no1, TNo* no2);
		void RDD(TNo* no1, TNo* no2);
		
		void Rotacionar();		
		
	//-----------------------------------------------
	private:
		
}; // TABB

#endif
