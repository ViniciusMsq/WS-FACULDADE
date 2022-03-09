#include <iostream>
using namespace std;
int troca (int a, int b)
{   
    int z;
    z=a;
    a=b;
    b=z;
    cout<<"\n Primeiro valor: "<<a;
    cout<<"\n Segundo valor: "<<b;
	
}
int main ()
{
	setlocale (LC_ALL, "Portuguese");
	int x, y,reusult1, result2;
	cout<<"\n Digite o primeiro valor: ";
	cin>>x;
	cout<<"\n Digite o segundo valor: ";
	cin>>y;
	troca (x,y);
}
