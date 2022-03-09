#ifndef TPILHA_H
#define TPILHA_H

class TPilha
{
	public:

		typedef char TInfoPilha;
		
		void Init();
		 
		struct TNoPilha {	
			TInfoPilha dado;	
			TNoPilha *prox;		
		};

		TNoPilha *Topo;

		
		bool IsEmpty();
	
		void Push(TInfoPilha elemento);
	
		TInfoPilha Pop();
	
		TInfoPilha Top();
	
		void PrintPilha();
	
		TPilha();
	
		~TPilha();

};

#endif
