#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	float r, a, res;
	
	cout<<"Informe o raio da lata: ";
	cin>>r;
	cout<<"Informe a altura da lata: ";
	cin>>a;
	
	res = 3.1416 *(r*r)* a;
	
	cout<<"O volume da lata é: "<<res;

	return 0;
}
