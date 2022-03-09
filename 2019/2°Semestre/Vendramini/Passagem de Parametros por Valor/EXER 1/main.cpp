#include <iostream>


using namespace std;

	int menor(int a,int b)
	{
		int r;
		if(a<b)
		{
			r=a;	
		}
		else
		{
			r=b;
		}	
			return(r);
 	
	}
int main(int argc, char** argv) 
{
	setlocale (LC_ALL, "Portuguese");
	
	int x,y,result;
	
		cout<<"Digite o Primeiro Valor: ";
		cin>>x;
		cout<<"\n";
	
		cout<<"Digite o Segundo Valor: ";
		cin>>y;
		cout<<"\n";
		 
		result=menor(x,y);
		cout<<"O menor valor é : "<<result;<<"\n";
	
	
	system ("pause");
	return 0;
}
