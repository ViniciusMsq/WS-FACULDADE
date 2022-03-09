#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int n, a, b , c, d, res, z;
	
	cout<<"Informe um numero de inteiro de ate 5 algarismos: ";
	cin>>n;
	z = (n/10000)%1000%100%10;
	a = (n/1000)%100%10;
	b = (n/100)%10;
	c = (n/10)%10;
	d = n%10;
	
	res = a+b+c+d+z;
	if(n<=99999){
	
	cout<<"\nsoma="<<res;
	}
	else{
		cout<<"Numero Invalido";
	}
	
	return 0;
}








