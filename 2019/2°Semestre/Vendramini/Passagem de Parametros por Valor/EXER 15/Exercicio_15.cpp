#include <iostream>
using namespace std;
int funcao (int *x)
{
	int resto;
	
	resto=*x%10;
	*x=*x/10;
	return (resto);
}

int main ()
{
	setlocale (LC_ALL, "Portuguese");
	int valor,x,resultado;
	cout<<"\n Digite um valor: ";
	cin>>valor;
	x = funcao (&valor);
	cout<<"\n Resultado: "<<x;
	cout<<"\n Resultado: "<<valor;

}
