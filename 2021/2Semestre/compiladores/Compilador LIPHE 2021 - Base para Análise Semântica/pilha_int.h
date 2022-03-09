

#include "includes.h"


typedef struct 
{
	int topo;
	int info[TamPilhas];	
}pilhaI;

void CriaPilhaI( pilhaI &p ){

   p.topo=-1;

}

bool PilhaIVazia ( pilhaI &p ){

   	if(p.topo == -1)
   		return true;
   	else
   		return false;
}

bool estacheia ( pilhaI p  ){

	if(p.topo == TamPilhas)
		return true;
	else
		return false;

}

void EmPilhaI ( pilhaI &p , int v){
	p.topo++;
	p.info[p.topo]=v;
}

int DesemPilhaI ( pilhaI &p){

   int aux = p.info[p.topo];
   p.topo--;
   return aux;

}

int MostraPilhaI ( pilhaI p  ){

	if(p.topo != -1)
	{
		for(int i=0; i< TamPilhas; i++)
   		p.info[i];
	}
	else
	{
		return -1;
	}
		
    
}
