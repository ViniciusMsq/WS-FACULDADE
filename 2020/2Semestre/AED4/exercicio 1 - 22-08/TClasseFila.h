#include <iostream>
#ifndef TCLASSEFILA_H
#define TCLASSEFILA_H

using namespace std; 

class TClasseFila 
{
	//-------------------------------------------------------------
	public:
		
		typedef struct {
			string nome;
			string telefone;
			int grau;			
		} TPessoa;
		
		typedef TPessoa TInfoFila;
		
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
		int GetSize();
		void ConsultaNome(string nome);
		
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
