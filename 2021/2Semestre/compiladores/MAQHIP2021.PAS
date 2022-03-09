UNIT MaqHip;

{----------------------------------------------------------------------------
  UNIFAI - Centro Universitário de Adamantina
  Curso Ciência da Computação - 6º Semestre de 2021
  Compiladores II  -  Prof. Márcio Roberto Rizzatto

  Linguagem de Programação Hipotética Experimental - LIPHE

  Implementacao do algoritmo de analise sintatica usando-se a  técnica
  de parser  preditivo LL(1). 

  Unit de Implementacao das instrucoes geradas pela analise semântica
  
  MEPA( Maquina Hipotetica )   
  
  ==> Desenvolvida em Linguagem Pascal ==> Alunos(as) devem Traduzir para C++
  
  ----------------------------------------------------------------------------}


INTERFACE

USES
    crt,DefTip;


     FUNCTION ExecutaMaqHip( Var AInst : VetorInst; Var AreaLit : VetorLit;
                             Var MensErro : STRING ): BOOLEAN;
{
   Funcao que executa a maquina hipotetica.
   ENTRADA:
            AInst  - regiao onde estao armazenadas as instrucoes a serem
                   executadas;
            AreaLit - Area onde estao armazenadas as literais.
   SAIDA  :
            MensErro - Indica o erro de execucao se houver.
   A FUNCAO RETORNA :
                       TRUE  -  Nao houve erro de excucao
                       FALSE -  Houve erro de execucao.

-------------------------------------------------------------------------}

IMPLEMENTATION


FUNCTION ExecutaMaqHip;

VAR
    PC,    { Designa proxima instrucao a ser executada     }
    B,     { Indica o endereco do segmento de dados        }
    T      { Aponta para o topo da pilha ( area d dados )  }
           : Integer;
    fim    : Boolean;
    S      : ARRAY [1..2500] OF Integer;   { Area de Dados }
    Limite : LongInt;


FUNCTION Sucesso:boolean;
BEGIN
   MensErro:='';
   CASE   AInst[PC].cod OF
     5..7,21  : IF Limite > 32767 THEN
                  BEGIN
                     MensErro:=' ***  Overflow *** ';
                     fim:=TRUE;
                  END
                ELSE
                  IF Limite < -32767 THEN
                     BEGIN
                        MensErro:=' ***   Underflow  *** ';
                        fim:=TRUE;
                     END;

       8   :   IF S[T] = 0 THEN BEGIN
                  MensErro:='  ***  Divisao por zero  *** ';
                  fim:=TRUE;
               END;
       END;
       ExecutaMaqHip:= NOT fim;
       Sucesso:= NOT fim;
END; { Sucesso }


FUNCTION BASE (parm : Integer):Integer;
{ Determina base para resolver referencias a variaveis }

VAR  temp : Integer;
BEGIN
   temp:=B;
   WHILE parm > 0 DO
      BEGIN
        temp:= S[temp];
        Dec(parm);
      END;
   BASE:=temp;
END;  { BASE }


PROCEDURE RETU(A: Integer);  { retorno de procedure }
BEGIN
    T:=B-1;
    PC:=S[T+3];
    B:=S[T+2];
    T:=T-A;
END;

PROCEDURE CRVL(L,A : Integer);  {  carrega valor na pilha,      }
BEGIN                           {  L -> DIFERENCA DE NIVEL,     }
   Inc(T);                      {  A -> DESLOCAMENTO            }
   S[T]:=S[BASE(L)+A];
   Inc(PC);
END;

PROCEDURE CRCT(K: Integer);  { carrega constante na pilha }
BEGIN
   Inc(T);
   S[T]:=K;
   Inc(PC);
END;

PROCEDURE ARMZ(L,A : Integer);  { armazena conteudo do topo da pilha  }
BEGIN                           { no endereco fornecido               }
   S[BASE(L)+A]:=S[T];
   Dec(T);
   Inc(PC);
END;

PROCEDURE SOMA;  { operacao soma }
BEGIN
   Limite:=LONGINT(S[T-1])+LONGINT(S[T]);
   IF Sucesso THEN
     BEGIN
        S[T-1]:=S[T-1]+S[T];
        Dec(T);
        Inc(PC);
     END;
END;

PROCEDURE SUBT;  { operacao subtracao }
BEGIN
   Limite:=LONGINT(S[T-1])-LONGINT(S[T]);
   IF Sucesso THEN
     BEGIN
        S[T-1]:=S[T-1]-S[T];
        Dec(T);
        Inc(PC);
     END;
END;

PROCEDURE MULT;  { operacao multiplicacao }
BEGIN
   Limite:=LONGINT(S[T-1])*LONGINT(S[T]);
   IF Sucesso THEN
     BEGIN
        S[T-1]:=S[T-1]*S[T];
        Dec(T);
        Inc(PC);
     END;
END;

PROCEDURE DIVI;  { operacao divisao }
BEGIN
   IF Sucesso THEN
     BEGIN
       S[T-1]:=S[T-1] DIV S[T];
       Dec(T);
       Inc(PC);
     END;
END;

PROCEDURE INVR;  { operacao de inversao de sinal }
BEGIN
    S[T]:= -S[T];
    Inc(PC);
END;

PROCEDURE NEGA;  { operacao de negacao }
BEGIN
   S[T]:=1 - S[T];
   Inc(PC);
END;

PROCEDURE CONJ;  { operacao AND }
BEGIN
   IF (S[T-1]=1) AND (S[T]=1) THEN
      S[T-1] := 1
   ELSE
      S[T-1] := 0;
   Dec(T);
   Inc(PC);
END;

PROCEDURE DISJ;  { operacao OR }
BEGIN
   IF (S[T-1]=1) OR (S[T]=1) THEN
      S[T-1]:= 1
   ELSE
      S[T-1]:= 0;
   Dec(T);
   Inc(PC);
END;

PROCEDURE CMME;  { compara menor }
BEGIN
   IF S[T-1] < S[T] THEN
       S[T-1] := 1
   ELSE
       S[T-1] := 0;
   Dec(T);
   Inc(PC);
END;

PROCEDURE CMMA;  { compara maior }
BEGIN
   IF S[T-1] > S[T] THEN
       S[T-1]:= 1
   ELSE
       S[T-1]:= 0;
   Dec(T);
   Inc(PC);
END;

PROCEDURE CMIG;  { compara igual }
BEGIN
   IF S[T-1] = S[T] THEN
       S[T-1]:= 1
   ELSE
       S[T-1]:= 0;
   Dec(T);
   Inc(PC);
END;

PROCEDURE CMDF;  { compara diferente }
BEGIN
   IF S[T-1] <> S[T] THEN
       S[T-1]:= 1
   ELSE
       S[T-1]:= 0;
   Dec(T);
   Inc(PC);
END;

PROCEDURE CMEI;  { compara menor-igual }
BEGIN
   IF S[T-1] <= S[T] THEN
       S[T-1]:= 1
   ELSE
       S[T-1]:= 0;
   Dec(T);
   Inc(PC);
END;

PROCEDURE CMAI;  { compara maior-igual }
BEGIN
   IF S[T-1] >= S[T] THEN
       S[T-1]:= 1
   ELSE
       S[T-1]:= 0;
   Dec(T);
   Inc(PC);
END;

PROCEDURE DSVS(A: Integer);  {  desviar sempre }
BEGIN
   PC:= A;
END;

PROCEDURE DSVF(A : Integer);  { desviar se falso }
BEGIN
   IF S[T] = 0  THEN
      PC:=A
   ELSE
      Inc(PC);
   Dec(T);
END;

PROCEDURE  LEIT;  { leitura }
BEGIN
   Inc(T);
   READ(Limite);
   IF Sucesso  THEN
      BEGIN
        S[T]:=INTEGER(Limite);
        Inc(PC);
      END;
END;

PROCEDURE IMPR;  { imprimir }
BEGIN
   WRITE(S[T]) ;
   Dec(T);
   Inc(PC);
END;

PROCEDURE IMPRLIT(num:Integer);  { imprimir literal }
BEGIN
   IF num=-1 THEN WRITELN
   ELSE WRITE(AreaLit[num]);
   Inc(PC);
END;

PROCEDURE AMEM(A:Integer);  { alocar espaco na area de dados }
BEGIN
   T:= T + A;
   Inc(PC);
END;

PROCEDURE CALL(L,A: Integer);  { chamada de procedure }
BEGIN
   S[T+1]:= BASE(L);
   S[T+2]:= B;
   S[T+3]:= PC;
   B:= T+1;
   PC:= A;
END;

PROCEDURE PARA;  { para execucao }
BEGIN
   fim:= TRUE;
END;

PROCEDURE NADA;  { nada faz }
BEGIN
   Inc(PC);
END;

PROCEDURE DSVT(A:Integer);  { desviar se verdade }
BEGIN
   IF S[T] = 1 THEN
      PC:= A
   ELSE
      Inc(PC);
   Dec(T);
END;

PROCEDURE COPIA;  { duplica topo }
BEGIN
   Inc(T);
   S[T]:=S[T-1];
   Inc(PC);
END;

PROCEDURE SEG;  { duplica sub-topo }
BEGIN
   Inc(T);
   S[T]:= S[T-2];
   Inc(PC);
END;


BEGIN
   T:=0;
   B:=1;
   Fim:=FALSE;
   ExecutaMaqHip:= TRUE;
   FOR PC := 1 TO 2500 DO
      S[PC]:=0;
   PC := 0;
   WHILE NOT Fim DO
     BEGIN
       CASE AInst[PC].Cod OF
          1 : RETU(AInst[PC].Op2);
          2 : CRVL(AInst[PC].Op1,AInst[PC].Op2);
          3 : CRCT(AInst[PC].Op2);
          4 : ARMZ(AInst[PC].Op1,AInst[PC].Op2);
          5 : SOMA;
          6 : SUBT;
          7 : MULT;
          8 : DIVI;
          9 : INVR;
          10: NEGA;
          11: CONJ;
          12: DISJ;
          13: CMME;
          14: CMMA;
          15: CMIG;
	  16: CMDF;
          17: CMEI;
          18: CMAI;
          19: DSVS(AInst[PC].Op2);
          20: DSVF(AInst[PC].Op2);
          21: LEIT;
          22: IMPR;
          23: IMPRLIT(AInst[PC].Op2);
          24: AMEM(AInst[PC].Op2);
          25: CALL(AInst[PC].Op1,AInst[PC].Op2);
          26: PARA;
          27: NADA;
          28: DSVT(AInst[PC].Op2);
          29: COPIA;
          30: SEG;
       END; { CASE }
     END; { WHILE }
END;   { ExecutaMaqHip }

BEGIN
END.  { MaqHip }
