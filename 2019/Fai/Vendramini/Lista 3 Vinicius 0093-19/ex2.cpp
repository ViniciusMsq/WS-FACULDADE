#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n1, n2;
	
	cout<<"Informe um valor: ";
	cin>>n1;
	cout<<"Informe outro valor: ";
	cin>>n2;
	
	if(n1>n2){
		cout<<"Menor valor: "<<n2;
	}
	else{
		cout<<"Menor valor: "<<n1;
	}



	return 0;
}
