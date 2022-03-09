#include "includes.h"

#define capTotal 20

typedef struct 
{
	int topo;
	string info[TamPilhas];	
}pilhasS;

void CriaPilhaS( pilhasS &p ){

   p.topo = -1;

}

bool PilhaSVazia ( pilhasS p ){

   	if(p.topo == -1)
   		return true;
   	else
   		return false;
}

bool estacheia ( pilhasS p  ){

	if(p.topo == TamPilhas)
		return true;
	else
		return false;

}

void EmPilhaS ( pilhasS &p , string v){
	p.topo++;
	
	for(int i =0; i<v.length();i++)
		p.info[p.topo][i] = v[i];
}

string DesemPilhaS ( pilhasS &p){
   //char aux[capTotal];
   string aux= "-1";
   
   if(PilhaSVazia(p) != false)
   {
   		for(int i =0; i < p.info[p.topo].length(); i++)
			aux[i] = p.info[p.topo][i];
   }
   
		
   return aux;
}

void MostraPilhaS ( pilhasS p  ){
	if(p.topo != -1)
	{
		for(int i=0; i < p.info[p.topo].length(); i++)
   			cout << p.info[i];
	}

}
