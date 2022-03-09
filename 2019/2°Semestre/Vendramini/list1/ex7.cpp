#include <iostream>
using namespace std;

void quadrado(int res);
void triangulo(int res);
void circulo(int res);
void retangulo(int res);

int main(int argc, char** argv) {
	
	int escolha, res;
	
	cout<<"Selecione a opção desejada\n1: Area quadrado\n2: Area triangulo\n3 Area circulo\n4 Area retangulo\n5 Sair\n\n";
	cout<<"ESCOLHA: ";
	cin>>escolha;
	switch(escolha){
		case 1: quadrado(res);
		break;
		case 2: triangulo(res);
		break;
		case 3: circulo(res);
		break;
		case 4: retangulo(res);
		break;
		case 5: exit(0);
		break;
		default:
			cout<<"invalido";
			break;
	}
	return 0;
}
void quadrado(int res){
	cout<<"Informe o lado do quadrado: ";
	cin>>res;
	res=res*res;
	cout<<"A area do quadrado e: "<<res;

}
void triangulo(float res){
	float b, h;
	cout<<"Informe o valor da base: ";
	cin>>b;
	cout<<"Informe o valor da altura: ";
	cin>>h;
	res = b*h;
	cout<<"A area do triangulo é: "<<res;
}
void circulo(int res){
	float raio;
	cout<<""
}
