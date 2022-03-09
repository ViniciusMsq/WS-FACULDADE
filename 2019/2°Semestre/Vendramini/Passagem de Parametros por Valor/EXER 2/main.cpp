#include <iostream>

using namespace std;

	void idade (int a)
	{
		if(a<18)
		{
			cout<<"Você é Menor de idade!!";
			cout<<"\n";
		}
		else
		{
			cout<<"Você é maior de idade!!";
			cout<<"\n";
		}
	}


int main(int argc, char** argv)
 {		
 	setlocale (LC_ALL,"portuguese");
	 
	int x;
		
		cout<<"Digite sua idade: ";
		cin>>x;
		cout<<"\n";
		
		idade (x); 
		cout<<"\n";
		
	system("pause");	
	return 0;
}
