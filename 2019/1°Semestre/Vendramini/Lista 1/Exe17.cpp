#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int nrc;
	float custo;
	
	cout<<"Informe o numero de coelhos: ";
	cin>>nrc;
	
	custo= (nrc * 0.70)/18 + 10;
	
	cout<<"Custo = "<<custo;
	
	return 0;
}
