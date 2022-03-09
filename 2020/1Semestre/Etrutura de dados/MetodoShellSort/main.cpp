#include <iostream> 
 
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
int main() { 
 float vetor[100]; 
 int tam; 
 
    cout << "Digite a quantidade de posicoes: "; 
    cin >> tam; 
    for (int i = 0; i < 1000; i++) { 
    if (i < tam) { 
    cout << "informe um valor: "; 
    cin >> vetor[i]; 
    } 
    else { 
    break; 
    } 
    } 
    
    cout << "\n\nvetor dessarrumado: "; 
    for (int i = 0; i < tam; i++) { 
    cout << vetor[i] << ", "; 
    } 
    cout << "\n\nvetor arrumado: "; 
    shell(vetor, tam); 
    
    for (int i = 0; i < tam; i++) { 
    cout << vetor[i] << ", "; 
    } 
}
