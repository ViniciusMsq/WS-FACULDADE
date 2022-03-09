homem(rui).
homem(miguel).
homem(pedro).
homem(joao).
homem(jose).
mulher(ana).
mulher(manuela).
mulher(joana).
mulher(rita).
casados(ana,rui).
casados(manuela,miguel).
casados(joana,pedro).
descendente(joana,ana,rui).
descendente(miguel,ana,rui).
descendente(rita,joana,pedro).
descendente(joao,joana,pedro).
descendente(jose,joana,pedro).

pai(P,F):-descendente(F,_,P),homem(P).
mae(M,F):-descendente(F,M,_),mulher(M).

filho(F,P):-homem(F),(pai(P,F);mae(P,F)).
filha(F,P):-mulher(F),(pai(P,F);mae(P,F)).

avoh(A,N):-homem(A),pai(A,F),(pai(F,N);mae(F,N)).
avom(A,N):-mulher(A),mae(A,F),(pai(F,N);mae(F,N)).

neto(N,A):-homem(N),(avoh(A,N);avom(A,N)).
neta(N,A):-mulher(N),(avoh(A,N);avom(A,N)).

irmao(I,P):-homem(I),descendente(I,A,B),descendente(P,A,B),I\==P.
irma(I,P):-mulher(I),descendente(I,A,B),descendente(P,A,B),I\==P.

tio(T,S):-homem(T),irmao(T,M),(pai(M,S);mae(M,S)).
tia(T,S):-mulher(T),irma(T,M),(pai(M,S);mae(M,S)).

/* sobrinho(S,T):-homem(S),(tio(T,S);tia(T,S)).
sobrinha(S,T):-mulher(S),(tio(T,S);tia(T,S)).

cunhado(C,I):-homem(C),casados(M,C),(irmao(I,M);irma(I,M)).
cunhada(C,I):-mulher(C),casados(C,M),(irmao(I,M);irma(I,M)). */

sobrinho(S,T):-homem(S),descendente(S,M,P),(irma(M,T);irmao(P,T)).
sobrinha(S,T):-mulher(S),descendente(S,M,P),(irma(M,T);irmao(P,T)).

cunhado(C,P):-homem(C),irmao(C,X),(casados(X,P);casados(P,X)).
cunhada(C,P):-mulher(C),irma(C,X),(casados(X,P);casados(P,X)).


par(P):- P mod 2 =:= 0.
impar(I):- I mod 2 =:= 1.

nota_freq(marcos,logica,9.0,60). 
nota_freq(leonardo,logica,7.0,95). 
nota_freq(bruno,logica,4.0,75).

%aprovado(X,Y,Z,W) :- nota_freq(X,Y,Z,W), Z>7,W>75.
aprovado(X,Y,Z,W) :- nota_freq(X,Y,Z,W), Z>=7,W>=75.
%aprovado(X,Y,Z,W) :- nota_freq(X,Y,Z>7,W>75).
%reprovado(X,Y,Z,W) :- nota_freq(X,Y,Z,W), Z>=7,W>=75.

minimo(X,Y,X) :- X =< Y.



