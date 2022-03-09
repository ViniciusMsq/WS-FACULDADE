#include <iostream>
using namespace std;
int funcao (int x,int y)
{
	int min;
	min=(x*60) +y;
	cout<<"\n Se passaram "<<min<<" minutos desde meia-noite";
	cout<<"\n Horas correntes: "<<x;
}
int main ()
{
	setlocale (LC_ALL, "Portuguese");
	system ("cls");
	int minutos,horas;
	cout<<"\n Digite as horas: ";
	cin>>horas;
	cout<<"Digite os minutos: ";
	cin>>minutos;
	funcao (horas,minutos);
}
