#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int num;
	float res;
	
	cout<<"Informe um numero: ";
	cin>>num;
	
	res = num%2;
	if(num != 0){
	
		if(res==0){
			cout<<num<<" e um numero par";
		}
		else{
			cout<<num<<" e um numero impar";
		}
	}
	else{
		cout<<"Neutro";
	}
	
	return 0;
}
