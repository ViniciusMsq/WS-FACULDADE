#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int dia;
	float res;
	
	cout<<"Informe a quantidade de dias: ";
	cin>>dia;
	
	res = dia%7;
	
	if(res == 0){
		cout<<"Sexta";
	}
	else if(res == 1){
		cout<<"Sabado";
	}
	else if(res == 2){
		cout<<"Domingo";
	}
	else if(res == 3){
		cout<<"Segunda";
	}
	else if(res == 4){
		cout<<"Terca";
	}
	else if(res == 5){
		cout<<"Quarta";
	}
	else {
		cout<<"Quinta";
	}
	
	
	
	
	
	
	
	
	
	return 0;
}
