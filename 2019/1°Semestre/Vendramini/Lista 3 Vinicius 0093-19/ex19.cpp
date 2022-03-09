#include <iostream>
#include <math.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	float peso, alt, imc;
	
	cout<<"Informe seu peso: ";
	cin>>peso;
	cout<<"Informe sua altura: ";
	cin>>alt;
	
	imc = peso / (pow(alt, 2));
	
	if ( imc < 18.5 ) {
		 
		cout<<"seu imc e "<<imc<<" ABAIXO DO PESO";
	}  
	else if ( imc >= 18.5 && imc < 25 ) {
		
	cout<<"seu imc e "<<imc<<" PESO NORMAL";
	
	} 
	else if ( imc >= 25 && imc <= 30 ) {
		
	cout<<"seu imc e "<<imc<<" ACIMA DO PESO";
	}                 
	else{
		
		cout<<"seu imc e "<<imc<<" OBESO";
	}              

	return 0;
}










