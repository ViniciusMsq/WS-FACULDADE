#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	float reaj, sal;
	
	cout<<"Informe seu salario: ";
	cin>>sal;
	
	if(sal>500 && sal<=1000){
		reaj = sal*1.15;
		cout<< "Seu salario e: "<<reaj;
	}
	else if(sal>1000){
		reaj = sal*1.05;
		cout<<"Seu salario e: "<<reaj;
	}
	else{
		cout<<"Sem reajuste";
	}


	return 0;
}
