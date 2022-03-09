#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	float n1, n2, n3, n4, n5;
	
	cout<<"Informe um numero: ";
	cin>>n1;
	cout<<"Informe outro numero: ";
	cin>>n2;
	cout<<"Informe outro numero: ";
	cin>>n3;
	cout<<"Informe outro numero: ";
	cin>>n4;
	cout<<"Informe outro numero: ";
	cin>>n5;
	
	cout<<"A media é: "<<(n1+n2+n3+n4+n5)/5;
	
	return 0;
}
