#include <iostream>

using namespace std;

int main(){
	
	int vetor[10],i, x=1;
	
	for(i=0;i<10; i++){
		vetor[i]=x;
		x+=2;
		cout<<"\nVetor["<<i<<"] ="<<vetor[i];
	}
}
