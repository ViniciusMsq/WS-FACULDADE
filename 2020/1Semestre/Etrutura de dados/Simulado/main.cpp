#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


 
void shell(float*vetor, float tamanho){ 
    int aux, i , j , h=tamanho/2;//h vai ser o controlador a divis�o do vetor ex: h = 8/2; h=4 
    while(h>0){ // enquanto o h > 0 (h=4) 
    i = h; // i = 4 
    while (i<tamanho){ // 4<tamanho (8) 
    aux = vetor[i];// aux recebe o numero na posição i (que refere o h) 
    j = i; // j = 4 
    while (((j>=h) && (aux<vetor[j-h]))){ //enquanto 4 >= 4 E aux(valor do vetor)<vetor[4-4](posição 0 do vetor) 
    vetor[j] = vetor [j-h];  
    j=j-h; // j = 4 - 4; 
    } 
    vetor[j]=aux; 
    i=i+1;// i = 4+1; 
    } 
    h=h/2; // h = 4/2; 
    } 
 }

int main(int argc, char const *argv[])
{
    float n1, n2, teste;
    float *v;
    int cont=0;

    do{ 
        system("CLS");
        cout<<"informe a nota do 1 bim: ";
        cin>>n1;
        cout<<"\ninforme a nota do 2 bim: ";
        cin>>n2;
        v[cont] = ((n1+n2)/2);
        cont++;
        
        cout<<"\ndeseja continuar ? [1-sim, 2-nao] ";
        cin>>teste;
    }while(teste == 1);
    
    shell(v, cont);
    for(int i =0; i<cont; i++){
        cout<<(v[i])<<" ; ";
    }
    


    return 0;
}
