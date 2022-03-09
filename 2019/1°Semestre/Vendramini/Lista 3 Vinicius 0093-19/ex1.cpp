#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int num;
	
	cout<<"Digite um numero inteiro: ";
	cin>>num;
	
	if(num>0){
		cout<<"O numero "<<num<<" é positivo";
	}
	else if(num<0){
		cout<<"O numero "<<num<<" é negativo";
	}
	else{
		cout<<"O numero "<<num<<" é considerado um numero neutro";
	}
	
	
	
	return 0;
}
