#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int num;
	
	cout<<"Digite um numero inteiro: ";
	cin>>num;
	
	if(num>0){
		cout<<"O numero "<<num<<" � positivo";
	}
	else if(num<0){
		cout<<"O numero "<<num<<" � negativo";
	}
	else{
		cout<<"O numero "<<num<<" � considerado um numero neutro";
	}
	
	
	
	return 0;
}
