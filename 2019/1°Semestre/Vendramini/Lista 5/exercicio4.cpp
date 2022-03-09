#include <iostream>
using namespace std;

int main(){
	int i, vetorA[10];
	
	for(i=0; i<10;i++){
		cout<<"Informe um valor: ";
		cin>>vetorA[i];
		
		if(vetorA[i]<0){
			vetorA[i]=0;
		}
	}
	for(i=0; i< 10; i++){
		cout<<" "<<vetorA[i];
	}
	
	return 0;
	
}
