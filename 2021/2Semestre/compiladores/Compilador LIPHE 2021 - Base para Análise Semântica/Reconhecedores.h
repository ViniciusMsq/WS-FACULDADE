

#include "includes.h"

#define totReservados 37 // Tamanho máximo da Lista de Tokens em funcoes.h

// **************************************************************************************
//Monta um String(token no caso) perante duas posições da linha em questão. EX: linha[23] até Linha[50]
string Juntar(int p1, int p2, string value)
{
	string juntou ="";
	
	if(p1 == p2)
	{
		juntou += value[p1];
	}
	else
	{
		while(p1 != p2)
		{
			juntou += value[p1];
			p1++;
		}
	}
	return juntou;
}


// **************************************************************************************
//Transforma uma string em um ponteiro de char
char *toStr(string value)
{
	char *aux = strdup(value.c_str());
	return aux;
}


// **************************************************************************************
//Rertona o número perante a tabela ASC de um caracter
int tab_asc(char value)
{
	int asc;
	
	asc = value;
	return asc;
}


// **************************************************************************************
// Reconhece sequências de números inteiros
bool ReconheceInteiro (string linha,int &posicao)
{
		
	bool reconheceInteiro = true;
	
	posicao++;
	
	while( posicao < linha.length() &&isdigit(linha[posicao]))
	{
		posicao++;
	}
	
	return reconheceInteiro;
}


// **************************************************************************************
//Reconhece um identificado
bool ReconheceIdentificador (string linha,int &posicao)
{
	bool rec_id = true;
	bool fim = false;
	
	while((linha[posicao] == '_' || isalnum(toupper(linha[posicao]))) && !fim)
	{
		posicao++;
		if(posicao > linha.length())
			fim =false;
	}
	
	return rec_id;
}


// **************************************************************************************
// Reconhece um símbolo literal. OBS: Entre ''
bool ReconheceLiteral (string linha,int &posicao)
{
	bool reconheceLiteral = false , sair = false;
	
	posicao ++;	
	
	while(posicao< linha.length() && sair == false && tab_asc(linha[posicao]) <= 255 && tab_asc(linha[posicao])>= 0)
	{
		if(tab_asc(linha[posicao]) == 39)
		{
			sair = true;
			reconheceLiteral = true;
		}
			
		posicao++;
	}
	
	return reconheceLiteral;
}


// **************************************************************************************
// Função que reconhece comentários simples ou compostos
bool ReconheceComentario (FILE *Arq,char linha[],int &posicao,int &contLinha)
{
	int cont=1;
	bool reconhece_comentario = false;
	
	
	while(reconhece_comentario == false && !feof(Arq))
	{	
		posicao++;	
		while(isspace(linha[posicao])){
			posicao ++;
		}
		
		if(posicao < strlen(linha))
		{
			if(linha[posicao] == '*')
			{
				if(linha[posicao+1] == '/')
				{					
					reconhece_comentario =true;
					posicao++;
					posicao++;
				}
			}
		}
		else
		{
			fgets(linha,sizeof(linha),Arq);
			contLinha++;
			posicao = -1;
		}	
	}
	
	return reconhece_comentario;
}


// **************************************************************************************
bool ReconheceSimbolosEspeciais (string linha,int &posicao, int &numToken)
{
	//Variáveis
	bool reconhece = false;
	int pos_anterior = posicao;
	
	//Estrutura de dados da função		
	typedef struct afd{
		int tam_alfabeto;
		string alfabeto[6];		
		
		//Construtor
		afd()
		{
			string EnumStrings[] = {"+-/*()#,;.|",":","=",">","<","!"};
							
			tam_alfabeto = 6;
						
			for(int i =0; i < tam_alfabeto;i++)
				alfabeto[i] = EnumStrings[i];

		}
	
	
		//Funçõa que verifica se é símbolo composto
		bool isAlfaRep(char lin)
		{
			string EnumRepetidos[] = {":","=",">","<","!"};
			bool isalfarep = false;			
			
			for(int j =0; j < 5;j++)
			{
					if(alfabeto[j][0] == lin)
						isalfarep = true;
			}			
			return isalfarep;
		}
		
		//Função que retorna o número do token correspondente
		int RetornaToken(string linha, int pos, int pos_ant)
		{
			#define n_simb 21 // Número de símbolos a mais do que na Lista de Tokens em funcoes.h
			
			string sim_reservado[n_simb] = {"+","-","*","/","(",")",":=",":","=",">",">=",
 									  "<","<=","<>",",",";","=>",".","LITERAL","$","|"};
 										   
			string aux = "";
			aux = Juntar(pos_ant,pos,linha);
			
			bool sai;
			int i;

			sai = false;
			i = 0;
			
			while(i<n_simb && sai == false)
			{
				if(aux == sim_reservado[i])
					sai = true;
				else
					i++;
			}
			
			if(!sai)
				return -1;	
			else
				return (i+totReservados);	
		}			
	}afd; //FIM STRUCT afd
		
	afd tabela;

	//Verifica símbolos especiais compostos. Ex:(:=, ||)
	if(tabela.isAlfaRep(linha[posicao]))
	{
		posicao++;
		if(tabela.isAlfaRep(linha[posicao]))
			posicao++;
	}
	else
		posicao++;
	
	
	//Pega o número do token correspondente
	numToken = tabela.RetornaToken(linha, posicao,pos_anterior);
	
	
	if(numToken != -1)
		reconhece = true;
	else
		reconhece = false;
				
			
	return reconhece;
}
