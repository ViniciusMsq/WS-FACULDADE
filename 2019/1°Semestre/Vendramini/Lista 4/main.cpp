#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int n = 0, cont = 0;
	float media = 0.0;
	
	do{
		cout<<"informe um numero inteiro: ";
		cin>>n;
		
		if(n>0){
		media += n;
		cont++;
		}	
	}while(n != 0);
	
	media = media/cont;
	cout<<"A media dos numeros é:"<<media;
	
	
	
	return 0;
}
