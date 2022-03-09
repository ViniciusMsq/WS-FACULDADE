#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	float n, cont = 1;
	float s = 0.00;
	
	cout<<"Digite um numero: ";
	cin>>n;
	
	while(n>=1){
		s += cont/n;
		cout<<"\n"<<cont<<"/"<<n;
		cont++;
		n--;
	}
	cout<<"\n\nSoma:"<<s;
	return 0;
}
