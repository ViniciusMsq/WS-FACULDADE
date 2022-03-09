#include <iostream>

using namespace  std; 

//-------------------------------------------------------------
class TPilha
{
	public:

		//--- Definição da Estrutura da Pilha 
		typedef int TInfoPilha;

		struct TNoPilha {	
			TInfoPilha dado;	
			TNoPilha *prox;		
		};

		//-------------------------------------------------------------
		bool IsEmpty()
		{
			return Topo == NULL;
			
		} // bool IsEmpty()

		//-------------------------------------------------------------
		void Push(TInfoPilha elemento)
		{
			TNoPilha *novo;
			
			novo = new TNoPilha;
			
			novo->dado = elemento;
			novo->prox = Topo;
			
			Topo = novo;
			
		} // void Push(int n)
		
		//-------------------------------------------------------------
		TInfoPilha Pop()
		{
			// se a pilha não estiver vazia
			if( !IsEmpty() )
			{
				TNoPilha *No_a_excluir;
				TInfoPilha valor;
				
				No_a_excluir = Topo;	
					
				valor = Topo->dado;
				
				Topo = Topo->prox;
				
				delete(No_a_excluir);
				
				return valor;
				
			} 
			else return 0;
			
		} // TInfoPilha Pop()
		
		//-------------------------------------------------------------
		TInfoPilha Top()
		{
			// se a pilha não estiver vazia
			if( !IsEmpty() )
			{
				return Topo->dado;
			
			} 
			else return 0;
			
		} // TInfoPilha Top()
		
		//-------------------------------------------------------------
		void PrintPilha()
		{
			TNoPilha *aux;
			
			// se a pilha não estiver vazia
			if( !IsEmpty() )
			{
				aux = Topo;
				while(aux != NULL)
				{
					cout << "\n " << aux->dado;
					aux = aux->prox;
				}
			
			} 
			else printf("\nPilha Valiza !\n\n");
			
		} // PrintPilha()
		
		//-------------------------------------------------------------
		TPilha()
		{
			Init();
			
		} // construtor
		
		//-------------------------------------------------------------		
		~TPilha()
		{
			// Esvaziando ou destruindo a pilha
			while( !IsEmpty() )
			{
				Pop();
			}
			
		} // DEstrutor
		
	//------------------------------------------------------------------------------
	private:
		
	//------------------------------------------------------------------------------
	protected:

		TNoPilha *Topo;

		//-------------------------------------------------------------
		void Init()
		{			
			Topo = NULL;		
					
		} // void Init()
			
}; // class TPilha


//-------------------------------------------------------------
int main(int argc, char** argv) {
	
	TPilha::TInfoPilha aux;
	
	TPilha pilha;
		
	pilha.Push(13);
	
	printf("\n=======================================");
	printf("\n=== PILHA DINAMICA ====================\n\n");
	
	printf("Informe um numero para incluir na Pilha.....: ");
	cin >> aux;
	
	pilha.Push(aux);
	
	printf("Informe outro numero para incluir na Pilha..: ");
	cin >> aux;
	
	pilha.Push(aux);
	
	printf("Informe outro numero para incluir na Pilha..: ");
	cin >> aux;
	
	pilha.Push(aux);
	
	printf("Informe outro numero para incluir na Pilha..: ");
	cin >> aux;
	
	pilha.Push(aux);
	
	printf("\n\nO topo da Pilha e: %d", pilha.Top() );
	
	printf("\n\n\nO Conteudo da Pilha e:\n");
	
	pilha.PrintPilha();
	
	// excluindo o top da pilha
	
	aux = pilha.Pop();		
	
	
	printf("\n\nO valor %d foi excluido do topo da pilha", aux ) ;

	printf("\n\n\nDesempilhamento Total da Pilha");
	while( !pilha.IsEmpty() )	
	{
		aux = pilha.Pop();
		
		printf("\nValor excluido: %2d", aux);
	}
	
	
	printf("\n\n");
	return 0;
	
} // main()
