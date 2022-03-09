#ifndef TCLASSEFILA_H
#define TCLASSEFILA_H

class TClasseFila 
{
	//-------------------------------------------------------------
	public:
		typedef int TInfoFila;
		
		struct TNoFila {	
			TInfoFila dado;	
			TNoFila *prox;		
		};
		
		struct TFila {	
			TNoFila *Comeco;
			TNoFila *Final;
		};
		
		
		bool Q_IsEmpty();
		void Enqueue(TInfoFila elemento);
		TInfoFila Dequeue();
		TInfoFila Q_Comeco();
		TInfoFila Q_Final();
		void PrintFila();
		
		
		TNoFila * GetComeco();
		TNoFila * GetFinal();		
			
		TClasseFila();
		~TClasseFila();
		
	//-------------------------------------------------------------
	private:
		
	//-------------------------------------------------------------
	protected:
		
		TFila *Fila;

		void Q_Init();

}; // TClasseFila


#endif
