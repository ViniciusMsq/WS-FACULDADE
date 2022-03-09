#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//funções declaradas:
int pesos();
int maiorMenor();
int exibir();
//--------------------------------------
int main(int argc, char** argv) {
	
	int bois[3], menor=100000000, maior=-100, n1, n2;
	
	for(int x=0; x<3; x++){
		cout<<"informe o peso do primeiro boi: (apenas kilo)";
		cin>>bois[x];
	} 
	
	for(int y=0; y<3; y++){
		
		if(bois[y]>maior){
			n1= y+1;
			maior = bois[y];
		}
		if(bois[y]<menor){
			n2 = y+1;
			menor = bois[y];
		}
	}
	
	cout<<"Maior Boi: "<<n1<<" "<<maior;
	cout<<"\n";
	cout<<"Menor Boi: "<<n2<<" "<<menor;
	
	return 0;
}
//funões-----------------
