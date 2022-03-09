#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	float h;
	char s;
	
	cout<<"M - Masculino\nF - Feminino\n\n";
	cout<<"Informe seu Sexo: ";
	cin>>s;
	cout<<"Informe sua altura: ";
	cin>>h;
	
	if(s=='M' || s=='m'){
		cout<<"Seu peso Ideal: "<<(72.7*h)-58;
	}
	else if(s=='F' || s=='f'){
		cout<<"Seu peso Ideal: "<<(62.1*h)-44.7;
	}
	else{
		cout<<"sexo invalido";
	}
	
	return 0;
}
