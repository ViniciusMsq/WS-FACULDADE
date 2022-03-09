#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n1, n2, n3;
	
	cout<<"Informe um numero: ";
	cin>>n1;
	cout<<"Informe outro numero: ";
	cin>>n2;
	cout<<"Informe outro numero: ";
	cin>>n3;
	
	if(n1>n2 && n1>n3){
		cout<<"O maior e: "<<n1;
	}
	else if(n2>n1 && n2>n3){
		cout<<"O maior e: "<<n2;
	}
	else{
		cout<<"O maior e: "<<n3;
	}
	
	
	return 0;
}
