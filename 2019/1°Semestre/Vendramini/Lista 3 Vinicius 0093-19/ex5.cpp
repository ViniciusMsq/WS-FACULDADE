#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	float n1, n2 , n3;
	
	cout<<"Digite um valor: ";
	cin>>n1;
	cout<<"Digite outro valor: ";
	cin>>n2;
	cout<<"Digite outro valor: ";
	cin>>n3;
	
	if(n1>n2 && n1>n3){
		if(n2>n3){
			cout<<"Crescente: "<<n3<<" "<<n2<<" "<<n1;
		}
		else{
			cout<<"Crescente: "<<n2<<" "<<n3<<" "<<n1;
		}
	}
	else if(n2>n1 && n2>n3){
		if(n1>n3){
			cout<<"Crescente: "<<n3<<" "<<n1<<" "<<n2;
		}
		else{
			cout<<"Crescente: "<<n1<<" "<<n3<<" "<<n2;
		}	
	}
	else{
		if(n1>n2){
			cout<<"Crescente: "<<n2<<" "<<n1<<" "<<n3;
		}
		else{
			cout<<"Crescente: "<<n1<<" "<<n2<<" "<<n3;
		}
	}
	
	
	
	
	return 0;
}
