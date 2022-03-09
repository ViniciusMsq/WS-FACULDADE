#include <iostream>
using namespace std;
//VINICIUS MESQUINI 0093/19
void shell(float*vetor, float tamanho){ 

    int i , j , h=tamanho/2;
    float aux;
    while(h>0){
    i = h;
    while (i<tamanho){
    aux = vetor[i];
    j = i;
    while (((j>=h) && (aux<vetor[j-h]))){
    vetor[j] = vetor [j-h];  
    j=j-h;
    } 
    vetor[j]=aux; 
    i=i+1;
    } 
    h=h/2;
    } 
}

main(){
    int tam = 0;
    float v[500];
    system("CLS");
    cout<<"INFORME A QUANTIDADE DE POSICOES PARA DIGITAR: ";
    cin>>tam;
    system("CLS");
    for(int i = 0; i<tam; i++){
        cout<<"Informe o "<<(i+1)<<" valor: ";
        cin>>v[i];
        system("CLS");
    }
    cout<<"VETORES DESORDENADOS\n";
	
	for(int i = 0; i<tam; i++){
		cout<<v[i]<<"; ";
	}
	
	shell(v, tam);
	
	cout<<"\nVETORES ORDENADOS\n";
	
	for(int i = 0; i<tam; i++){
		cout<<v[i]<<"; ";
	}
	
	system("PAUSE");
	return 0; 
}
