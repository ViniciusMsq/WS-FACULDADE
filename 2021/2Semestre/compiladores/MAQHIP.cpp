#include MaqHip;

ExecutaMaqHip();

int T, B, PC;
bool fim;
int S[2500];
LongInt Limite;


bool Sucesso()
{
   string MensErro='';
   switch  (AInst[PC].cod){
     		case 5,6,7,21 :
			 	 if (Limite > 32767) 
                  {
                     MensErro=' ***  Overflow *** ';
                     fim=TRUE;
                  }
                else
                  if (Limite < -32767) 
                     {
                        MensErro=' ***   Underflow  *** ';
                        fim=TRUE;
                     };
				break;
       		case 8   :   
			   		if (S[T] = 0)  {
						MensErro='  ***  Divisao por zero  *** ';
						fim=TRUE;
					};
				break;

       ExecutaMaqHip() =  !fim;
       Sucesso()=  !fim;
}


int BASE (int parm){

	int temp;

   temp=B;
   WHILE (parm > 0) 
      {
        temp= S[temp];
        Dec(parm);
      };
   BASE=temp;
}


void RETU(int A)
{
    T=B-1;
    PC=S[T+3];
    B=S[T+2];
    T=T-A;
}

void CRVL(int L, int A)
{                           
   Inc(T);                      
   S[T]=S[BASE(L)+A];
   Inc(PC);
}

void CRCT(int K)
{
   Inc(T);
   S[T]=K;
   Inc(PC);
}

void ARMZ(int L, int A)
{                           
   S[BASE(L)+A]=S[T];
   Dec(T);
   Inc(PC);
}

void SOMA() 
{
   Limite=LONGINT(S[T-1])+LONGINT(S[T]);
   if (Sucesso()) 
     {
        S[T-1]=S[T-1]+S[T];
        Dec(T);
        Inc(PC);
     };
}

void SUBT()
{
   Limite=LONGINT(S[T-1])-LONGINT(S[T]);
   if Sucesso() 
     {
        S[T-1]=S[T-1]-S[T];
        Dec(T);
        Inc(PC);
     };
}

void MULT()
{
   Limite=LONGINT(S[T-1])*LONGINT(S[T]);
   if (Sucesso()) 
     {
        S[T-1]=S[T-1]*S[T];
        Dec(T);
        Inc(PC);
     };
}

void DIVI()
{
   if (Sucesso()) 
     {
       S[T-1]=S[T-1] DIV S[T];
       Dec(T);
       Inc(PC);
     };
}

void INVR()
{
    S[T]= -S[T];
    Inc(PC);
}

void NEGA()
{
   S[T]=1 - S[T];
   Inc(PC);
}

void CONJ()
{
   if (S[T-1]=1) AND (S[T]=1)){ 
      S[T-1] = 1
   }else{
      S[T-1] = 0;
   }Dec(T);
   Inc(PC);
}

void DISJ()
{
   if ((S[T-1]=1) OR (S[T]=1)){
      S[T-1]= 1
   }else{
      S[T-1]= 0;
   }
   Dec(T);
   Inc(PC);
}

void CMME()
{
   if (S[T-1] < S[T]){
       S[T-1] = 1
   }else{
       S[T-1] = 0;
	}Dec(T);
   Inc(PC);
}

void CMMA() 
{
   if (S[T-1] > S[T]){ 
       S[T-1]= 1
   }else{
       S[T-1]= 0;
   }Dec(T);
   Inc(PC);
}

void CMIG() 
{
   if( S[T-1] = S[T]){ 
       S[T-1]= 1
   }else{
       S[T-1]= 0;
	}Dec(T);
   Inc(PC);
}

void CMDF()
{
   if( S[T-1] <> S[T]){ 
       S[T-1]= 1
   }else{
       S[T-1]= 0;
   }
   Dec(T);
   Inc(PC);
}

void CMEI()
{
	if(S[T-1] <= S[T])
	{
		S[T-1] = 1;
	}		
	else
	{
		S[T-1] = 0;
		T--;
		PC++;
	}
}

void CMAI()
{
	if(S[T-1] >= S[T])
	{
		S[T-1] = 1;
	}
	else
	{
		S[T-1] = 0;
		T--;
		PC++;
	}
}

void DSVS(int A)
{
	PC = A;
}

void DSVF(int A)
{
	if(S[T] == 0)
	{
		PC = A;
	}
	else
	{
		PC++;
		T--;
	}
}

void LEIT()
{
	int limite;
	T++;
	cin>>limite;
	if(Sucesso()())
	{
		S[T] = limite;
		PC++;
	}
}

void IMPR()
{
	cout<<""+S[T];
	T--;
	PC++;
}

void IMPRLIT(int num)
{
	if(num ==-1 )
	{
		cout<<"";
	}
	else
	{
		cout<<""+AreaLit[num];
		PC++;
	}
}

void AMEM(int A)
{
	T = T + A;
	PC++;
}

void CALL(int L, int A)
{
	S[T+1] = L;
	S[T+2] = B;
	S[T+3] = PC;
	B = T+1;
	PC = A;
}

void PARA()
{
	fim = true;
}

void NADA()
{
	PC++;
}

void DSVT(int A)
{
	if(S[T] == 1)
	{
		PC = A;
	}
	else
	{
		PC++;
		T--;
	}
}

void COPIA()
{
	T++;
	S[T] = S[T-1];
	PC++;
}

void SEG()
{
	T++;
	S[T] = S[T-2];
	PC++;
}

void main()
{
	T = 0;
	B = 1;
	fim = false;
	ExecutaMaqHip = true;
	for(PC=1;PC<=2500; PC++)
	{
		S[PC] = 0;
		PC = 0;
		
		while(!fim)
		{
			switch(AInst[PC].Cod)
			{
				case 1:
					RETU(AInst[PC].Op2);
				break;
				
				case 2:
					CRVL(AInst[PC].Op1,AInst[PC].Op2);
				break;
				
				case 3:
					CRCT(AInst[PC].Op2);
				break;
				
				case 4:
					ARMZ(AInst[PC].Op1,AInst[PC].Op2);
				break;
				
				case 5:
					SOMA();
				break;
				
				case 6:
					SUBT();
				break;
				
				case 7:
					MULT();
				break;
				
				case 8:
					DIVI();
				break;
				
				case 9:
					INVR();
				break;
				
				case 10:
					NEGA();
				break;
				
				case 11:
					CONJ();
				break;
				
				case 12:
					DISJ();
				break;
				
				case 13:
					CMME();
				break;
				
				case 14:
					CMMA();
				break;
				
				case 15:
					CMIG();
				break;
				
				case 16:
					CMDF();
				break;
				
				case 17:
					CMEI();
				break;
				
				case 18:
					CMAI();
				break;
				
				case 19:
					DSVS(AInst[PC].Op2);
				break;
				
				case 20:
					DSVF(AInst[PC].Op2);
				break;
				
				case 21:
					LEIT();
				break;
				
				case 22:
					IMPR();
				break;
				
				case 23:
					IMPRLIT(AInst[PC].Op2);
				break;
				
				case 24:
					AMEM(AInst[PC].Op2);
				break;
				
				case 25:
					CALL(AInst[PC].Op1,AInst[PC].Op2);
				break;
				
				case 26:
					PARA();
				break;
				
				case 27:
					NADA();
				break;
				
				case 28:
					DSVT(AInst[PC].Op2);
				break;
				
				case 29:
					COPIA();
				break;
				
				case 30:
					SEG();
				break;
			}
		}
	}	
}
