#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {

	float r=0, result=0;
	
	cout<<"Informe o valor do Raio: ";
	cin>>r;
	
	result = (4.0/3)*3.1416*(r*r*r);
	cout<<"O volume da esfera é: "<<result;

	return 0;
}
