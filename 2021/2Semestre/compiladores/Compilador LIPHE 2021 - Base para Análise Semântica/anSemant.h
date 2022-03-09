
#include "pilha_str.h"
#include "pilha_int.h"
#include "listComp.h"
#include "tabSimb.h"
#include "DEFTIPE.h"



//CONST
    //enum VarPar = {1,2,3,8};

    string ErroSem[40] =
                        {
						  "Identificador ja declarado",
                          "Identificador nao declarado",
                          "Nome do procedimento nao corresponde",
                          "Tipo incompativel",
                          "Tipo nao permitido",
                          "Simbolo nao eh rotulo",
                          "Numero de parametros incorreto",
                          "Rotulo nao encontrado",
                          "Rotulo duplicado" };



    //string Str20[20];
    //string Contexto[6] = {"Nada","Rotulo","Variavel","Parametro","Leitura","CampoEnum" };
                //{ Indica situacao onde foram encontrados identificadores }
                string Contexto;


//FUNCTION ExecutaAcaoSemantica( Acao: BYTE; Ident1,Ident2: STRING;
  //                         Var AInst: VetorInst; Var ALit: VetorLit ):BYTE;


//VARIAVÉIS
	
	TipoEscopo Escopo;
	TipoSimbolo Info;
	Lista *Rot[10];
    int PtLivre,  //Proxima entrada na tabela de simbolos(TS) }
    Nivel,    //Nivel atual em um momento da compilacao }
    LC,       //Indicador de posicao na area de codigo }
    L,        //Diferenca de Nivel }
    C,
    Temp,I,
    NR,
    NP,       //Acumulador de numero de parametros }
    CVT,      //Contador de variaveis total }
    CVP,      //Contador de variaveis parcias }
    CCE,      //Contador de campos de enumeracao }

    TipoFor,     //Tipo de laco - incremento = ou <> de 1 }
    CP           //Contador de parametros }
	;
    
	string Ident,SalvaIdent;
    pilhasS PlProc;
    pilhaI PlDSVT, PlDSVS,
    PlDSVF, PlIF,
    PlRepeat,PlFOR,
    PlEnde,PlNP;
    
	int PosLit,ErSem;




//{----------------------------------------------------------}

void GeraInst( int Cod, int Op1,int Op2)
{
    AInst[LC].Cod = Cod;
    AInst[LC].Op1 = Op1;
    AInst[LC].Op2 = Op2;
    LC++;
}

//{----------------------------------------------------------}

void  Acao0()
{
	bool OK;
	for(I=0;I<10;I++)
		Escopo[I] = 0;

    Atribui(Info,"",0,0,0,0,0);
    for(i= 0;i< 50;i++)
    {
    	TS[I]= Info;
	    ALit[I] = "";
	}
    PosLit = 0;
    
	for(int I = 0;I< 11; I++)
       CriaLista(Rot[I]);
    
	PtLivre = 1;
    Nivel= 0;
    NR= 0;
    LC= 0;
    NP= 0;
    CVT= 0;
    CVP= 0;
    CCE= 0;
    CP= 0;
    Contexto= "Nada";
    Temp= 0;
    CriaPilhaI(PlFOR);
    CriaPilhaI(PlRepeat);
    CriaPilhaI(PlDSVS);
    CriaPilhaI(PlDSVT);
    CriaPilhaI(PlDSVF);
    CriaPilhaI(PlIF);
    CriaPilhaI(PlEnde);
    CriaPilhaI(PlNP);
    CriaPilhaS(PlProc);
    EmPilhaS(PlProc,Ident);
    Atribui(Info,"TRUE",5,0,1,0,0);
    Insere(TS,Info,Escopo[Nivel],PtLivre,OK);
    Atribui(Info,"FALSE",5,0,0,0,0);
    Insere(TS,Info,Escopo[Nivel],PtLivre,OK);
}  //{ Acao0 }


//{----------------------------------------------------------}

void Acao1(string Ident1)
{
    GeraInst(26,0,0);
    if (NR > 0)
	{
       for (I = 0;I < (PtLivre-1);I++)
	   {
           if (TS[I].Cat == 7)
		   {
              if(ListaVazia(Rot[TS[I].Atr4]) == false)
                 {
                    Ident1 =TS[I].Nome;
                    ErSem =8;
                 }
            }
        }
    }
} //{ Acao1 }

//{----------------------------------------------------------}

void Acao2()
{
    GeraInst(24,0,CVT+3);
    CVT = 0;
} //{ Acao2 }

//{----------------------------------------------------------}

void Acao3()
{
    Contexto = "Rotulo";
}; //{  Acao3 }

//{----------------------------------------------------------}

void Acao4()
{
	TipoSimbolo Info;
    bool Ok;
    
	Info.Nome = Ident;
	Info.Nivel = Nivel;

    if(Contexto == "Rotulo")
	{
        Info.Cat = 7;
        Info.Atr3 = 0;
        Info.Atr4 = NR;
		Insere(TS,Info,Escopo[Nivel],PtLivre,Ok);
		if (Ok == false)
			ErSem =1;
		NR++;
	}
	else if(Contexto == "Variavel" )
	{
		Info.Cat = 0;
		Info.Atr3 = CVT+3;
		Info.Atr4 = 0;
		Insere(TS,Info,Escopo[Nivel],PtLivre,Ok);
		if (Ok == false )
			ErSem =1;
		CVT++;
 		CVP++;
	}

    else if (Contexto == "Parametro" ) 
	{
		Info.Cat = 8;
		Info.Atr3 = 0;
		Info.Atr4 = 0;
		Insere(TS,Info,Escopo[Nivel],PtLivre,Ok);
		if(Ok == false)
			ErSem =1;
		NP++;
	}

     else if (Contexto == "Leitura") 
	 {
		 I = Busca(TS,Ident);
		 if (I!=0) 
		 {
		 	if ((TS[I].Cat%2) == 0)
			{
				GeraInst(21,0,0);
				GeraInst(4,Nivel-TS[I].Nivel,TS[I].Atr3);
			}
			else
			{
				ErSem = 4;
			}
		}
		else
		{
			ErSem = 2;
		}
	}

    else if (Contexto ==  "CampoEnum")  
	{
		Info.Cat = 4;
		Info.Atr3 = CCE;
		Info.Atr4 = 0;
		Insere(TS,Info,Escopo[Nivel],PtLivre,Ok);
		CCE++;
	}

}; //{ Acao4 }


//{----------------------------------------------------------}

void Acao5()
{
    TipoSimbolo Info;
    bool Ok;
    
    Atribui(Info,Ident,5,Nivel,0,0,0);
    Insere(TS,Info,Escopo[Nivel],PtLivre,Ok);
    if (Ok == false)
       ErSem = 1;
} //{Acao5 }

//{----------------------------------------------------------}

int ConverteNum( string S)
{
	//int lixo,constante;
	//VAL(S,constante,lixo);
	return atoi(S.c_str());

}

//{----------------------------------------------------------}

void Acao6(string Ident1)
{
	TS[PtLivre-1].Atr3= ConverteNum(Ident1);
}//{ Acao6 }

//{-----------------------------------------------------------}

void ColocaCat( int Cat)
{
	if (Contexto == "Variavel")
    {
        for (I = (PtLivre-CVP);I <= (PtLivre-1);I++)
            TS[I].Cat = Cat;
        CVP = 0;
	}
}

//{----------------------------------------------------------}

void Acao7()
{
	Contexto = "Variavel";
}; //{ Acao7 }

//{----------------------------------------------------------}

void Acao7A()
{
    ColocaCat(1);
}; //{ Acao7A }

//{----------------------------------------------------------}

void Acao7B()
{
    ColocaCat(2);
} //{ Acao7B }

//{----------------------------------------------------------}

void Acao7C()
{
	if( Contexto == "Parametro")
	{
		ErSem = 5;	
	}
    else{
		if (Contexto == "Variavel")
		{
    		ColocaCat(3);
            Temp = PtLivre;
            CCE = 0;
            Contexto = "CampoEnum";
	    }             
	}
} //{ Acao7C }

//{----------------------------------------------------------}

void Acao7D()
{
    for (I = Temp; I <= (PtLivre-1); I++) 
        TS[I].Atr4 = CCE;
    CVP = 0;
    Contexto = "Variavel";
} //{ Acao7D }

//{----------------------------------------------------------}

void Acao8()
{
    bool Ok;
    Atribui(Info,Ident,6,Nivel,LC,0,0);
    Insere(TS,Info,Escopo[Nivel],PtLivre,Ok);
    if(Ok == false)
       ErSem = 1;
    Nivel++;
    Escopo[Nivel] = PtLivre;
    Temp = PtLivre - 1;
    EmPilhaS(PlProc,Ident);
} //{ Acao8 }

//{----------------------------------------------------------}

void Acao8B()
{
    string NomProc;
    NomProc = DesemPilhaS(PlProc);
    if (NomProc!=Ident)
       ErSem = 3;
} // { Acao8B }

//{----------------------------------------------------------}

void Acao9()
{
    EmPilhaI(PlEnde,LC);
    EmPilhaI(PlNP,NP);
    TS[Temp].Atr4 = NP;
    for (I = (Temp+1); I<=(PtLivre-1);I++)
    {
        TS[I].Atr3 = -1 * NP;
        NP--;
	}
    GeraInst(19,0,0);
} //{  Acao9 }

//{----------------------------------------------------------}

void Acao10(string Ident1)
{
    int TLC,TNP;

    TNP = DesemPilhaI(PlNP);
    TLC = DesemPilhaI(PlEnde);
    GeraInst(1,0,TNP);
    AInst[TLC].Op2 = LC;
    for (I = Escopo[Nivel]; I <= (PtLivre-1);I++){
	
        if (TS[I].Cat == 7)
        	if(ListaVazia(Rot[TS[I].Atr4])==false){
            	Ident1 =TS[I].Nome;
            	ErSem =8;
           }
	}
    Remove(TS,Escopo[Nivel],PtLivre);
    Nivel--;
}//{ Acao10 }

//{----------------------------------------------------------}

void Acao11()
{
    Contexto = "Parametro";
}//{ Acao11 }

//{----------------------------------------------------------}

void Acao12()
{
	SalvaIdent = Ident;
} //{ Acao12 }

//{----------------------------------------------------------}

void Acao13()
{
    int Ender;
    i = Busca(TS,SalvaIdent);
    if ( (I != 0) && (TS[I].Cat = 7) )
	{
       if ( TS[I].Nivel == Nivel )
        {
            if (TS[I].Atr3 != 0) {
                ErSem =9;
            }
            else
            {
                TS[I].Atr3 = LC;
                while (ListaVazia(Rot[TS[I].Atr4]) == false)
                {
                    PegaInformacao(Rot[TS[I].Atr4],Ender);
                    AInst[Ender].Op2 = LC;
                    RetiraLista(Rot[TS[I].Atr4]);
                }
            }
        }
        else
	    {
	   		ErSem = 2;
		}       
	}
	else
	{
    	ErSem =6;
    }
} //{ Acao13 }

//{----------------------------------------------------------}

void Acao14()
{
    I = Busca(TS,SalvaIdent);
    if (I != 0) 
	{
    	if ((TS[I].Cat%2) == 0)
    	{
            L = TS[I].Nivel;
            C = TS[I].Atr3;
    	}
    	else
		{
        	ErSem =4;
        }
    }
	else
	{
       ErSem = 2;
	}
} //{ Acao14 }

//{----------------------------------------------------------}

void Acao15()
{
    GeraInst(4,Nivel-L,C);
} //Acao15 }

//{----------------------------------------------------------}

void Acao16()
{
    I = Busca(TS,SalvaIdent);
    if (I != 0)
    {
       if (TS[I].Cat == 6)
    	{
            Temp = I;
            CP = 0;
        }
       	else
      	  ErSem =4;
	}
	else
       ErSem = 2;
}//Acao16 }

//{----------------------------------------------------------}

void Acao17()
{
    if (TS[Temp].Atr4 != CP)
       ErSem =7;
    else
       GeraInst(25,Nivel-TS[Temp].Nivel,TS[Temp].Atr3+1);
}//Acao17 }

//{----------------------------------------------------------}

void Acao18()
{
    CP++;
    
}//Acao18 }

//{----------------------------------------------------------}

void Acao19()
{
    int Op2 ;
    I = Busca(TS,Ident);
    if (I != 0)
    	if (TS[I].Cat == 7) 
		{
        	if (Nivel == TS[I].Nivel)
        	{
            	if (TS[I].Atr3 != 0)
				{
            		Op2 = TS[I].Atr3;
            	}
             	else
				{
                	Op2 = 0;
                	InsereLista(Rot[TS[I].Atr4],LC);
        		}
            	GeraInst(19,0,Op2);
            }
          	else
			{
            	ErSem =1;
        	}
        }
		else
		{
        	ErSem =1;
      	}
    else
	{
    	ErSem =2;
   	}
}// { Acao19 }

//{----------------------------------------------------------}

void Acao20()
{
    EmPilhaI(PlIF,LC);
    GeraInst(20,0,0);
}// Acao20 }

//{----------------------------------------------------------}

void Acao21()
{
    int Ender ;

    Ender = DesemPilhaI(PlIF);
    AInst[Ender].Op2 = LC;
} //Acao21 }

//{----------------------------------------------------------}

void Acao22()
{
    int Ender;

    Ender = DesemPilhaI(PlIF);
    AInst[Ender].Op2 = LC+1;
    EmPilhaI(PlIF,LC);
    GeraInst(19,0,0);
} //Acao22 }

//{----------------------------------------------------------}

void Acao23()
{
    EmPilhaI(PlRepeat,LC);
} //Acao23 }

//{----------------------------------------------------------}

void Acao24()
{
    int Ender;
    Ender = DesemPilhaI(PlRepeat);
    AInst[Ender].Op2 = LC+1;
    Ender  = DesemPilhaI(PlRepeat);
    GeraInst(19,0,Ender);
} //Acao24 }

//{----------------------------------------------------------}

void Acao25()
{
    EmPilhaI(PlRepeat,LC);
    GeraInst(20,0,0);
} //Acao25}

//{----------------------------------------------------------}

void Acao26()
{
    EmPilhaI(PlRepeat,LC);
    GeraInst(28,0,0);
} //Acao26 }

//{----------------------------------------------------------}

void Acao27()
{
    I = Busca(TS,Ident);
    if (I != 0)
	{
    	if ((TS[I].Cat%2)==0)
        	Temp = I;
        else
        	ErSem = 4;
    }
    else
       ErSem = 2;
} //Acao27 }

//{----------------------------------------------------------}

void Acao28()
{
    GeraInst(4,Nivel-TS[Temp].Nivel,TS[Temp].Atr3);
} //Acao28 }

//{----------------------------------------------------------}

void Acao29()
{
    TipoFor = 0;   //{ Sem passo }
} //Acao29 }

//{----------------------------------------------------------}

void Acao30()
{
    TipoFor = 1;   //{ Com passo }
} //Acao30 }

//{----------------------------------------------------------}

void Acao31()
{
    if (TipoFor = 0)
       GeraInst(3,0,1);
    EmPilhaI(PlFOR,LC);
    GeraInst(30,0,0);
    GeraInst(2,Nivel-TS[Temp].Nivel,TS[Temp].Atr3);
    GeraInst(13,0,0);
    EmPilhaI(PlFOR,LC);
    EmPilhaI(PlFOR,Temp);
    GeraInst(28,0,0);
} //Acao31 }

//{----------------------------------------------------------}

void Acao32()
{
    int Ender;
    Ender = DesemPilhaI(PlFOR);
    GeraInst(2,Nivel-TS[Ender].Nivel,TS[Ender].Atr3);
    GeraInst(30,0,0);
    GeraInst(5,0,0);
    GeraInst(4,Nivel-TS[Ender].Nivel,TS[Ender].Atr3);
    Ender = DesemPilhaI(PlFOR);
    AInst[Ender].Op2 = LC+1;
    Ender = DesemPilhaI(PlFOR);
    GeraInst(19,0,Ender);
    GeraInst(24,0,-2);
} //Acao32 }

//{----------------------------------------------------------}

void Acao33()
{
    Contexto = "Leitura";
}//Acao33 }

//{----------------------------------------------------------}

void Acao34(string Ident1)
{
    ALit[PosLit] = Ident1;
    GeraInst(23,0,PosLit);
    PosLit++;
} //Acao34 }

//{----------------------------------------------------------}

void Acao35()
{
    GeraInst(22,0,0);
} //Acao35 }

//{----------------------------------------------------------}

void Acao36()
{
    int mc;
    mc = -1;
    EmPilhaI(PlDSVF,mc);
    EmPilhaI(PlDSVS,mc);
} //Acao36 }

//{----------------------------------------------------------}

void Acao37(string Ident2)
{
    GeraInst(29,0,0);
    GeraInst(3,0,ConverteNum(Ident2));
    GeraInst(15,0,0);
    EmPilhaI(PlDSVT,LC);
    GeraInst(28,0,0);
} //Acao37 }

//{----------------------------------------------------------}

void Acao38(string Ident1)
{
    int Ender;

    GeraInst(29,0,0);
    GeraInst(3,0,ConverteNum(Ident1));
    GeraInst(15,0,0);
    while (PilhaIVazia(PlDSVT) == false)
        {
        	Ender = DesemPilhaI(PlDSVT);
        	AInst[Ender].Op2 = LC+1;
    	}
    EmPilhaI(PlDSVF,LC);
    GeraInst(20,0,0);
}//; { Acao38 }

//{----------------------------------------------------------}

void Acao39()
{
    GeraInst(15,0,0);
}//Acao39 }

//{----------------------------------------------------------}

void Acao40()
{
    GeraInst(13,0,0);
}//Acao40 }

//{----------------------------------------------------------}

void Acao41()
{
    GeraInst(14,0,0);
}// { Acao41 }

//{----------------------------------------------------------}

void Acao42()
{
    GeraInst(18,0,0);
}// { Acao42 }

//{----------------------------------------------------------}

void Acao43()
{
    GeraInst(17,0,0);
}// { Acao43 }

//{----------------------------------------------------------}

void Acao44()
{
    GeraInst(16,0,0);
}// { Acao44 }

//{----------------------------------------------------------}

void Acao45()
{
    GeraInst(9,0,0);
}// { Acao45 }

//{----------------------------------------------------------}

void Acao46()
{
    GeraInst(5,0,0);
}// { Acao46 }

//{----------------------------------------------------------}

void Acao47()
{
    GeraInst(6,0,0);
}// { Acao47 }

//{----------------------------------------------------------}

void Acao48()
{
    GeraInst(12,0,0);
}// { Acao48 }

//{----------------------------------------------------------}

void Acao49()
{
    GeraInst(7,0,0);
}// { Acao49 }

//{----------------------------------------------------------}

void Acao50()
{
    GeraInst(8,0,0);
}// { Acao50 }

//{----------------------------------------------------------}

void Acao51()
{
    GeraInst(11,0,0);
}// { Acao51 }

//{----------------------------------------------------------}

void Acao52(string Ident1)
{
    GeraInst(3,0,ConverteNum(Ident1));
}// { Acao52 }

//{----------------------------------------------------------}

void Acao53(string Ident1)
{
    GeraInst(10,0,ConverteNum(Ident1));
}// { Acao53 }

//{----------------------------------------------------------}

void Acao54()
{
    I = Busca(TS,Ident);
    if (I != 0) 
	{
        if ((TS[I].Cat = 5) || (TS[I].Cat = 4)) 
		{
        	GeraInst(3,0,TS[I].Atr3);
      	}
        else
		{
        	if ((TS[I].Cat%2)==0)
            	GeraInst(2,Nivel-TS[I].Nivel,TS[I].Atr3);
          	else
            	ErSem=4;
        }
    }
    else
       ErSem = 2;
}// { Acao54 }

//{----------------------------------------------------------}

void Acao55()
{
    int Ender;

    Ender = DesemPilhaI(PlDSVF);
    AInst[Ender].Op2 = LC+1;
    EmPilhaI(PlDSVS,LC);
    GeraInst(19,0,0);
}// { Acao55 }

//{----------------------------------------------------------}

void Acao56()
{
    int Ender;

    Ender = DesemPilhaI(PlDSVF);
    AInst[Ender].Op2 = LC+1;
    EmPilhaI(PlDSVS,LC);
    GeraInst(19,0,0);
}// { Acao56 }

//{----------------------------------------------------------}

void Acao57()
{
    int Ender;

    Ender = DesemPilhaI(PlDSVF);
    while (Ender != -1)
    {
        AInst[Ender].Op2 = LC;
        Ender = DesemPilhaI(PlDSVF);
    }
    Ender = DesemPilhaI(PlDSVS);
    while (Ender != -1)
    {
          AInst[Ender].Op2 = LC;
          Ender = DesemPilhaI(PlDSVS);
    }
    GeraInst(24,0,-1);
}// { Acao57 }


//{----------------------------------------------------------}

int ExecutaAcaoSemantica( int Acao, string Ident1, string Ident2)
{
    ErSem =0;
    Ident = Ident1;
    switch (Acao) 
	{
         case 100 : Acao0;  break;      		case 101 :  Acao1(Ident1);  break;      case 102 :  Acao2; break;
         case 103 : Acao3;  break;      		case 104 :  Acao4;  break;      		case 105 : Acao5; break;
         case 106 : Acao6(Ident1);  break;      case 107 :  Acao7;  break;      		case 108 : Acao7A; break;
         case 109 : Acao7B; break;      		case 110 :  Acao7C; break;      		case 111 : Acao7D; break;
         case 112 : Acao8;  break;      		case 113 :  Acao8B; break;      		case 114 : Acao9; break;
         case 115 : Acao10(Ident1); break;      case 116 :  Acao11; break;      		case 117 :  Acao12; break;
         case 118 : Acao13; break;      		case 119 :  Acao14; break;      		case 120 :  Acao15; break;
         case 121 : Acao16; break;      		case 122 :  Acao17; break;      		case 123 :  Acao18; break;
         case 124 : Acao19; break;      		case 125 :  Acao20; break;      		case 126 :  Acao21; break;
         case 127 : Acao22; break;      		case 128 :  Acao23; break;      		case 129 :  Acao24; break;
         case 130 : Acao25; break;      		case 131 :  Acao26; break;      		case 132 :  Acao27; break;
         case 133 : Acao28; break;      		case 134 :  Acao29; break;      		case 135 :  Acao30; break;
         case 136 : Acao31; break;      		case 137 :  Acao32; break;      		case 138 :  Acao33; break;
         case 139 : Acao34(Ident1); break;      case 140 :  Acao35; break;      		case 141 :  Acao36; break;
         case 142 : Acao37(Ident2); break;      case 143 :  Acao38(Ident1); break;      case 144 :  Acao39; break;
         case 145 : Acao40; break;      		case 146 :  Acao41; break;      		case 147 :  Acao42; break;
         case 148 : Acao43; break;      		case 149 :  Acao44; break;      		case 150 :  Acao45; break;
         case 151 : Acao46; break;      		case 152 :  Acao47; break;      		case 153 :  Acao48; break;
         case 154 : Acao49; break;      		case 155 :  Acao50; break;      		case 156 :  Acao51; break;
         case 157 : Acao52(Ident1); break;      case 158 :  Acao53(Ident1); break;      case 159 :  Acao54; break;
         case 160 : Acao55; break;      		case 161 :  Acao56; break;      		case 162 :  Acao57; break;
    }
    return (ErSem);

}// { ExecutaAcaoSemantica }

