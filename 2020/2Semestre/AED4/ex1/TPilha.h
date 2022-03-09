#ifndef TPILHA_H
#define TPILHA_H

class TPilha
{	
		public:
		typedef char TInfoPilha;
	
	    struct TNoPilha
	    {
	        TInfoPilha dado;
	        TNoPilha* prox;
	    };
	
	    void Init(TNoPilha*& Topo);
	
	    bool IsEmpty(TNoPilha* Topo);
	
	    void Push(TNoPilha*& Topo, TInfoPilha elemento);
	
	    TInfoPilha Pop(TNoPilha*& Topo);
	
	    TInfoPilha Top(TNoPilha* Topo);
	
	    void PrintPilha(TNoPilha* Topo);

};

#endif
