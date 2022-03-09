#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int idade, dias, hor, min, seg;
	
	cout<<"Informe a sua idade: ";
	cin>>idade;
	
	dias = idade*365;
	hor = dias*24;
	min = hor*60;
	seg = min*60;
	
	cout<<"sua idade em: ";
	cout<<"\nDias: "<<dias;
	cout<<"\nHoras: "<<hor;
	cout<<"\nMinutos: "<<min;
	cout<<"\nSegundos: "<<seg;
	return 0;
}
