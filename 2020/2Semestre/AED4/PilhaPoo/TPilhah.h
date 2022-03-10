#ifndef TPilhah_H
#define TPilhah_H

class TPilha
{
	public:

		//--- Defini??o da Estrutura da Pilha 
		typedef char TInfoPilha;

		struct TNoPilha {	
			TInfoPilha dado;	
			TNoPilha *prox;		
		};

		//-------------------------------------------------------------
		bool IsEmpty(); // bool IsEmpty()

		//-------------------------------------------------------------
		void Push(TInfoPilha elemento);
		
		//-------------------------------------------------------------
		TInfoPilha Pop();
		
		//-------------------------------------------------------------
		TInfoPilha Top();
		//-------------------------------------------------------------
		void PrintPilha();
		
		//-------------------------------------------------------------
		TPilha();
		
		//-------------------------------------------------------------		
		~TPilha();
		
	//------------------------------------------------------------------------------
	private:
		
	//------------------------------------------------------------------------------
	protected:

		TNoPilha *Topo;

		//-------------------------------------------------------------
		void Init();
			
}; // class TPilha

#endif