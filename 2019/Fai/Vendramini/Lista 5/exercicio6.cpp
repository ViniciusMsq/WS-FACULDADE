#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
		int vetor[5], x, i, j;
		
		for(x=0; x<5; x++){
			cout<<"Informe um valor: ";
			cin>>vetor[x];	
		}
		
		cout<<"Digite uma posi��o de 0 a 4: ";
		cin>>i;
		cout<<"Digite outra posi��o de 0 a 4: ";
		cin>>j;
		
		cout<<"\nA soma das posi��es �: "<<i+j;
		
	return 0;
}
