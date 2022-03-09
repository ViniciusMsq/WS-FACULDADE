#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	float a, b, x;
	
	cout<<"Informe o numero A: ";
	cin>>a;
	cout<<"Informe o numero B: ";
	cin>>b;
	cout<<"\n";	
	x = a;
	a = b;
	b = x;
	
	cout<<"Valor de A agora e: "<<a;
	cout<<"\nValor de B agora e: "<<b;
	
	return 0;
}
