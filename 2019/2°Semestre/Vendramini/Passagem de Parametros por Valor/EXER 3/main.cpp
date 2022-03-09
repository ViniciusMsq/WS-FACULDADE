#include <iostream>

using namespace std;

	int param_ref(int *num1,int *num2)
	{
		int soma;
		soma= *num1+*num2;
		*num1=4;
		*num2=5;
		return soma;
	}
	int param_valor(int num1, int num2)
	{
		int soma;
		soma= num1+num2;
		num1=4;
		num2=5;
		return soma;
	}
	
	int main()
	{
		int total,num1,num2;
		num1=20;
		num2=30;
		
		total = param_ref(&num1, &num2); // O Parametro muda o valor do num1=4 e o valor do num2=5
		
		total = param_valor(num1, num2); // Mantem o valor do num1 = 20 e o valor do num2=30
		
		cout << "total: "<< total << endl;
		cout<<"num1: "<<num1<<"\n";
		cout<<"num2: "<<num2<<"\n";
		
		

		
		return 0;
	}


