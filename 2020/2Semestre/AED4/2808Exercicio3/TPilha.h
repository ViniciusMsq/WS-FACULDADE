#ifndef TPILHA_H
#define TPILHA_H

class TPilha
{	public:

		typedef char TInfoPilha;

		struct TNoPilha {	
			TInfoPilha dado;	
			TNoPilha *prox;		
		};

		bool IsEmpty();
		void Push(TInfoPilha elemento);
		TInfoPilha Pop();
		TInfoPilha Top();
		void PrintPilha();
		TPilha();
		~TPilha();

	private:
		
	protected:

		TNoPilha *Topo;

		void Init();	
}; 

#endif
