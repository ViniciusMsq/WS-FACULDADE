#include "reconhecedores.h"

//Variáveis
typedef struct{
	string token;
	int id;
}tabSimbol;

string apostrofo = "'";

#define NL 100  // número de linhas

// **************************************************************************************
//Função que verifica se é símbolo especial
bool isEspecial(char value)
{
	#define num_sim_esp 16 // Quantidade de Símbolos Especiais
	bool is_especial = false;
	
	char simbolos_especiais[num_sim_esp] = {'+','-','*','/','(',')',':',
							   				'=','>','<',',',';','!','#','.','|'};
	
	for(int i=0; i< num_sim_esp;i++)
	{
		if(simbolos_especiais[i] == value)
			is_especial = true;
	}
	
	return is_especial;
}


// **************************************************************************************
//Função que verifica se a palavra é reservada
bool EhReservada(string txt, int &tok)
{		
	tabSimbol reservados[totReservados] = {"PROGRAM" , 1, "LABEL" , 2, "CONST", 3, "VAR",4, "PROCEDURE",5, 
											"BEGIN",6, "END",7, "INTEGER",8, "ENUM",9, "BOOLEAN",10,
											"FUNCTION",11,"GOTO",12,"IF",13,"THEN",14,"ELSE",15,
											"ENDIF",16,"REPEAT",17,"AGAIN",18,"WHILE",19,"UNTIL",20,
											"READ",21,"WRITE",22,"OR",23,"AND",24,"NOT",25,
											"IDENTIFICADOR",26,"INTEIRO",27,"FOR",28,"TO",29,"SELECT",30,
											"WHEN",31,"OTHERS",32,"ENDSELECT",33,"BY",34,"DO",35,
											"ENDFOR",36
											};
	
	int i;
	bool sai = false;
	
	for(i=0; i<txt.length();i++)
	{
		txt[i] = toupper(txt[i]);
	}
	
	i =0;
	
	while(i< totReservados && sai == false)
	{
		
		if(txt.compare(reservados[i].token) == 0)
		{
			tok = reservados[i].id;
			sai = true;
		}
		else
		{
			i++;
		}	
	}
	return sai;

}


// **************************************************************************************
//Função que Desconsidera Brancos
void DesconsideraBrancos(string value, int &posicao)
{
	
	while(posicao < value.length() && value[posicao] == ' ')
	{
		posicao++;
	}
}


// **************************************************************************************
void EscreveToken(FILE *arqSaida,int token,string aux, int cont){
	string escreva = "";
	
	stringstream convert[2];
	
	convert[0] << token; // int to string
	convert[1] << cont;	
	escreva += convert[0].str() + " " +convert[1].str() + " " + aux + "\n";	

	char *value = strdup(escreva.c_str());
	fputs(value,arqSaida);
	
	free(value);
}


// **************************************************************************************
bool AnalisadorLexico(FILE *arqEntrada, FILE *arqSaida, bool sucesso)
{
	int posicao=0;
	int posicao_anterior;
	string aux;
	char linha[NL];
	bool sai=false;
	int cont=0; // numero da linha
	int num_token;
	
	while(!feof(arqEntrada) && !sai)
	{
		cont++;
		posicao = 0;
		num_token = -1;
		
		fgets(linha,sizeof(linha),arqEntrada); //Lê próxima Linha
		
		while(posicao < strlen(linha) && sai==false )
		{
			DesconsideraBrancos(linha,posicao); //Desconsidera espaços
			posicao_anterior = posicao;
					
			if(isdigit(linha[posicao])) // Se for número
			{
				if(ReconheceInteiro(linha,posicao))
				{
					aux = Juntar(posicao_anterior,posicao,linha);  // monta o token
					EscreveToken(arqSaida,27,aux,cont);  //escreve o token no txt
				} 
			}
			else if(isalpha(linha[posicao])) // Se for Letra
			{
				if(ReconheceIdentificador(linha,posicao))
				{
					aux = Juntar(posicao_anterior,posicao,linha);
					
					if(aux == "DIV")
						EscreveToken(arqSaida,40,"",cont);
					else
					{
						if(EhReservada(aux,num_token))
							EscreveToken(arqSaida,num_token,"",cont);
						else
							EscreveToken(arqSaida,26,aux,cont);
					}
				}				
			}
			else if(tab_asc(linha[posicao]) == 39) // Se for Literal. OBS: 39 é ' na tabela asc
			{
				if(ReconheceLiteral(linha,posicao))
				{
					aux = Juntar(posicao_anterior,posicao,linha);
					EscreveToken(arqSaida,55,aux,cont);
				}
				else
				{
					cout << "ERRO LEXICO NA LINHA: "<<cont<<" E COLUNA: "<<posicao<<" O SIMBOLO LITERAL NÃO FOI FECHADO";
					sai = true;
				}			
			}
			else if(linha[posicao] == '/' && linha[posicao] == '*') // Se for um comentário composto
			{
				if(!ReconheceComentario(arqEntrada,linha,posicao,cont))
				{
					cout << "ERRO LEXICO: O COMENTARIO NAO FOI FECHADA";
					sai = true;
				}
			}
			else if(linha[posicao] == '/' && linha[posicao] == '/') //Se for um comentário simples
			{
				break;
			} 
			else if(isspace(linha[posicao])) //Se chegar no fim da LINHA
			{
				posicao = NL;
			}
			else
			{				
				if(isEspecial(linha[posicao])) // Se for símbolo especial
				{
					if(ReconheceSimbolosEspeciais(linha,posicao,num_token))
					{			
						EscreveToken(arqSaida,num_token,"",cont);
					}
					else
					{
						aux = Juntar(posicao_anterior,posicao,linha);
						cout << "ERRO LEXICO NA LINHA: "<<cont<<" E COLUNA: "<<posicao<<" COM O SIMBOLO INVALIDO: " << aux;
						sai = true;
					}
				}
				else
				{
					cout << "ERRO LEXICO NA LINHA: "<<cont<<" E COLUNA: "<<posicao<<" COM O SIMBOLO INVALIDO: "  << linha[posicao];
					sai = true;
				}
			}
		}// while 2
	}// while 1
	
	EscreveToken(arqSaida,56,"",cont);	
	sucesso = !sai;
	return sucesso;
	
}//fim analisador lexico
