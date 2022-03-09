#include "includes.h"

typedef struct {
	string Nome;
	int Cat ;
	int Nivel ;
	int Atr3 ;
	int Atr4;
	int Prox;
}TipoSimbolo;

typedef TipoSimbolo TabelaSimbolos[51];
typedef int TipoEscopo[20];

TabelaSimbolos TS;

int tabHash[22];
int i;


int Hash(string ident)
{
	int valor = 23;
	char car1, car2, car3;
	int tam;
	int indHash;
	
	
	car1 = ' ';
   	car2 = ' ';
   	car3 = ' ';
   	car1 = (char)ident[0];
    tam = ident.length();
   	
   	if(tam > 1)
   		car2 = (char)ident[1];
   	if(tam > 2)
   		car3 = (char)ident[2];
   	
   	if(tam>2)
		return (car1+car2+car3)%valor;
	else if(tam >1 )
		return(car1+car2)%valor;
	else
		return car1%valor;
}

int Busca(TabelaSimbolos &TS, string ident)
{
	int indTab, indTS, posicao;
	
	indTab = Hash(ident);
	
	if( tabHash[indTab] == 0)
	{
		posicao = 0;
	}
	else
	{
		indTS = tabHash[indTab];
		posicao = 0;
		
		while(indTS != 0)
		{
			if(TS[indTS].Nome == ident)
			{
				posicao = indTS;
				indTS = 0;
			}
			else
				indTS = TS[indTS].Prox;
		}
	}
	return posicao;
}


// *******************   INSERIR    ***************//

void Insere(TabelaSimbolos &TS, TipoSimbolo info, int &nivel, int &ptLivre, bool &ok)
{
	int indTab, posicao;
	 
	indTab = Hash(info.Nome);
	posicao = Busca(TS,info.Nome);
	
	if (posicao!=0)
	{
		if(nivel > posicao)
		{	
			TS[ptLivre] = info;
			TS[ptLivre].Prox = tabHash[indTab];
			tabHash[indTab] = ptLivre;
			ptLivre++;
			ok = true;
		}
		else
			ok = false;
	}
	else
	{
		TS[ptLivre] = info;
		TS[ptLivre].Prox = tabHash[indTab];
		tabHash[indTab] = ptLivre;
		ptLivre++;
		ok = true;
	}
}

void Remove(TabelaSimbolos &TS,int nivel, int &ptLivre)
{
	int indTab, indTS;
	
	indTS = ptLivre -1;
	
	while(indTS >= nivel)
	{
		indTab = Hash(TS[indTS].Nome);
		tabHash[indTab] = TS[indTS].Prox;
		TS[indTS].Prox = 0;
		indTS = indTS -1;
	}
	ptLivre = nivel;
}

void Atribui( TipoSimbolo &info, string nome, int cat, int nivel, int atr3, int atr4, int prox)
{
	info.Nome = nome;
	info.Cat = cat;
	info.Nivel = nivel;
	info.Atr3 = atr3;
	info.Atr4 = atr4;
	info.Prox = prox;
}


void Mostra( TabelaSimbolos TS, int I )
{
	
	cout << tabHash[I-1] << "    " << TS[I].Nome << "    " << TS[I].Cat << "    " <<
        TS[I].Nivel << "    " << TS[I].Atr3 << "    " << TS[I].Atr4 << "    " << TS[I].Prox;
}

