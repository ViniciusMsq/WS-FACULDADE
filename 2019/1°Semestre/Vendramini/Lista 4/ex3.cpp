#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int cont = 0;
	double a = 9000000, b = 20000000;
	
	while(a < b){
		
		a += (a * 0.3);
		b += (b * 0.15);

		cont++;
	}
	cout<<"Levará "<<cont<<" anos para Pais A ter uma população maior que do Pais B";
	
	cout<<"\n Pais A "<<a;
	cout<<"\n Pais B "<<b;
	
	return 0;
}
