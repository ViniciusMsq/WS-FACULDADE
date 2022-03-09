#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	float a, b;
	char c;
	cout<<"+ = soma;\n- = subtracao;\n* = multiplicacao;\n/ = divisao;\n\n";
	cout<<"Informe um valor: ";
	cin>>a;
	cout<<"Informe o operador aritimetico: ";
	cin>>c;
	cout<<"Informe outro valor: ";
	cin>>b;
	cout<<"\n";
	
	if(c == '+'){
		cout<<a<<c<<b<<" = "<<a+b;
	}
	else if(c == '-'){
		cout<<a<<c<<b<<" = "<<a-b;
	}
	else if(c == '*'){
		cout<<a<<c<<b<<" = "<<a*b;
	}
	else if(c == '/'){
		cout<<a<<c<<b<<" = "<<a/b;
	}
	else{
		cout<<"Operador nao definido";
	}
	
	
	return 0;
}
