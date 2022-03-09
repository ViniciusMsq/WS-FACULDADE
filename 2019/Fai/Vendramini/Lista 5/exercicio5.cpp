#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int vetorX[5], vetorY[5], vetorZ[5],i;
	
	for(i=0; i<5;i++){
		cout<<"Digite o valor do X: ";
		cin>>vetorX[i];
		
		cout<<"Digite o valor do Y: ";
		cin>>vetorY[i];
	}
	for(i=0; i<5;i++){
		vetorZ[i]=vetorX[i]+vetorY[i];
		
		cout<<"\nSoma:"<<vetorZ[i];
	}
	
	return 0;
}
