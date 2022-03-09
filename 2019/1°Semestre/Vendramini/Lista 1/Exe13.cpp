#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	float graus, C;
	
	cout<<"Informe a Temperatura em Fahrenheit: ";
	cin>>graus;
	
	C = (graus - 32)/1.8;
	
	cout<<"Os graus em Celsios é: "<<C;

	return 0;
}
