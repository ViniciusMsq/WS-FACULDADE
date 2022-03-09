#include "tabelas.h"
#include "pilhas.h"

#include "anSemant.h"


pilha Pl;


void InicializaPilha()
{
	CriarPilha(Pl);
	Empilha(Pl,56);
	Empilha(Pl,60);
}


bool EhTerminal(int x)
{
	if(x>=0 && x < 58)
		return true;
	else
		return false;
}

bool EhNaoTerminal(int x)
{
	if(x >= 60 && x <= 97)
		return true;
	else
		return false;
}

bool EhAcaoSemantica(int x)
{
	if(x>=100)
		return true;
	else
		return false;
}

void ExpandeTopo(int NumProd)
{
	cout << "\n NP: " << NumProd;
    int I,Ult;

	Ult =IndiceProd[NumProd+1]-1; // pega o indice para usar no for EX: 1 até 9
	
    if( Producoes [Ult-1] != 58) 
	{
        for (I = IndiceProd[NumProd]-1; I< Ult; I++)
        	Empilha(Pl,Producoes[I]);
    }
	
	if(NumProd == 17)
		cout << "\n I: " << I;  

}

void AtribuirTxt(char linha[], int &Token, int &NumLinha, string &Identif)
{
	
	string aux;
	aux= "";
	int i =-1,j=0;

		while(j <sizeof(linha))
		{
			if(isspace(linha[j]))
			{
				j++;
				i++;
				
				if(i == 0)
					Token = atoi(aux.c_str());
				else if(i == 1)
					NumLinha = atoi(aux.c_str());
				else
					Identif = aux;
				
				aux = "";
			}

			aux += linha[j];
			j++; 
			Identif = aux;
		}
}

bool Sintaxe(FILE *arqSaida)
{
	InicializaPilha();
	
	char Linha[100];
	int teste = 0;
	int Topo;
	int Token;
	int NumProd;
	bool Erro=false, Fim=false;
	int NumLin;
	int ErSem;
	string Identif="", Ident1="", Ident2="";
	
	if(!feof(arqSaida))
	{
		fgets(Linha,sizeof(Linha),arqSaida);	
		AtribuirTxt(Linha,Token,NumLin,Identif);
	}
	

	while( Erro == false && Fim == false && !feof(arqSaida)){
		Topo = Desempilhar(Pl);
		
		if (EhAcaoSemantica(Topo)) 
		{
	       	ErSem = ExecutaAcaoSemantica(Topo,Ident1,Ident2); // retorna o erro semântico
	        if (ErSem != 0)
	    	{
	            Erro = true;
	            cout << "\nERRO SEMANTICO NA LINHA: " <<NumLin;
	            cout << "\n Erro: "<<ErroSem[ErSem];
			}
		}
		else 
		{
			if (EhTerminal(Topo)) // 0 até 57
			{
				cout << "\n"<<Topo;
				cout << "\n" <<Token;
				
	        	if (Topo == Token) 
				{
	            	if (Topo == 56)
					{
	                    Fim = true;
	                }
	                else
					{
	                    Ident2 = Ident1;
	                    Ident1 = Identif;
	                    fgets(Linha,sizeof(Linha),arqSaida);
	                    AtribuirTxt(Linha,Token,NumLin,Identif);
	                }
	            }
	            else
	            {
	            	MostrarPilha(Pl);
	                Erro = true;
	                cout << "\nERRO SINTATICO NA LINHA: " << NumLin;
	                cout << "\nEspera-se : " << NomesTerminais[Topo];
	                cout << "\nEncontrado : "<< NomesTerminais[Token-1];	                
	            }
	        }
	        else if(EhNaoTerminal(Topo))  //{ Nao terminal } 60 até 97
	    	{
	    		NumProd = TabParsing [Topo-60][Token-1];
				if (NumProd != 0) 
				{
					MostrarPilha(Pl);
	              	ExpandeTopo(NumProd-1);
	              	MostrarPilha(Pl);
	            }
	            else
	            {
	                Erro = true;
	                cout << "\nERRO SINTATICO NA LINHA: "<<NumLin;
	        	}
	        }
	        else
			{
				Erro = true;
				cout << "\nDEU ERRO";
			}
	    }
        
	}
	
	return Fim;
}
