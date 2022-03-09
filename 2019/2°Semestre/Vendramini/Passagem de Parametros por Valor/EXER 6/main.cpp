#include <iostream>

using namespace std;

int LP(int pe[])
{
		int peso=0;
		
		while(peso<3)
	{
		cout<<"Digite o Peso do Boi "<<peso+1<<" : ";
		cin>>pe[peso];
		cout<<"\n";
		
		peso++;
	}
	
}

int Menor(int me[])
{
	int aux=1000,peso=0;
	
	while(peso<3)
	{
		
	
	
		if(me[peso]<aux)
		{
			aux=me[peso];
		
		}
		
		peso++;
	}
	
	return aux;
}

int Maior(int ma[])
{
	int aux=0,peso=0;
	
	while(peso<3)
	{
		if(ma[peso]>aux)
		{
			aux=ma[peso];
			
		}
		
		peso++;
	}
	
	return aux;
}

void imprima(int a, int b)
{
	cout<<"O Menor Valor é: "<<a<<"\n";
	cout<<"O Maior Valor é: "<<b<<"\n";
}

int main(int argc, char** argv) 
{
	int x[3],y,z;
	
	LP(x);
	y=Menor(x);
	z=Maior(x);
	imprima(y,z);
	

	

	return 0;
}
