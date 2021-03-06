UNIT DefTip;

{----------------------------------------------------------------------------
  UNIFAI - Centro Universit�rio de Adamantina
  Curso Ci�ncia da Computa��o - 6� Semestre de 2021
  Compiladores II  -  Prof. M�rcio Roberto Rizzatto

  Linguagem de Programa��o Hipot�tica Experimental - LIPHE

  Implementacao do algoritmo de analise sintatica usando-se a  t�cnica
  de parser  preditivo LL(1). 

  DefTip - Unit de definicao do tipo pilhas para a analise sintatica.
  
  ==> Desenvolvida em Linguagem Pascal ==> Alunos(as) devem Traduzir para C++
  
----------------------------------------------------------------------------}

INTERFACE


TYPE

     INST    =  RECORD
                  Cod  : BYTE;
                  Op1  : INTEGER;
                  Op2  : INTEGER;
                END;

     Str80      = STRING[80];
     VetorInst  =  ARRAY[0..2000] OF INST;
     VetorLit   =  ARRAY[0..10] OF Str80;


IMPLEMENTATION

END.  { DefTip }