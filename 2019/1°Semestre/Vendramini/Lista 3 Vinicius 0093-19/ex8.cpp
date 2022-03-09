#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	float n, a, b, c, d;
	
	cout<<"Informe o valor do inicio intervalo A-B: ";
	cin>>a;
	cout<<"Informe o valor do final intervalo A-B: ";
	cin>>b;
	cout<<"Informe o valor do inicio intervalo C-D: ";
	cin>>c;
	cout<<"Informe o valor do final intervalo C-D: ";
	cin>>d;
	cout<<"\n";
	cout<<"Informe um Numero: ";
	cin>>n;
	cout<<"\n";
	
	if(n>=a&&n<=b){
		
		if(n>=c&&n<=d){
			cout<<n<<" Pertence aos dois intervalos";	
		}
		else{
			cout<<n<<" Pertence apenas ao intervalo A-B";
		}
	}
	else if(n>=b&&n<=d){
		
		cout<<n<<" Pertence apenas ao intervalo C-D";
	}
	else{
		cout<<n<<" Não pertence a nenhum Intervalo";
	}
	
	return 0;
}
