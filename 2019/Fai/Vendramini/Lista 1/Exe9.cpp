#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main(int argc, char** argv) {
	
	float a, b, r1, r2;
	
	cout<<"informe o tamanho da base do retangulo: ";
	cin>>a;
	cout<<"informe o tamanho da altura do retangulo: ";
	cin>>b;
	
	r1 = a+a+b+b;
	r2 = a*b;
	
	cout<<"Perimetro: "<<r1;
	cout<<"\nArea: "<<r2;
	
	return 0;
}
