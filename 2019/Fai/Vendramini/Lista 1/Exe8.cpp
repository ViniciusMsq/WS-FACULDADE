#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;
int main(int argc, char** argv) {
	float r, area;
	
	cout<<"Informe o valor do Raio: ";
	cin>>r;
	
	area = 3.1416*(r*r);
	
	cout<<"o valor da área do circulo é: "<<area;
	
	return 0;
	
}
