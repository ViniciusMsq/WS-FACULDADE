#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int x;

	cout<<"Digite o numero do mes: ";
	cin>>x;
	
	switch(x)
    {
       case 1: cout<<"Janeiro"<<endl;break;
       case 2: cout<<"Fevereiro"<<endl;break; 
       case 3: cout<<"Marco"<<endl;break;
       case 4: cout<<"Abril"<<endl;break;
       case 5: cout<<"Maio"<<endl;break;
       case 6: cout<<"Junho"<<endl;break;
       case 7: cout<<"Julho"<<endl;break;
       case 8: cout<<"Agosto"<<endl;break; 
       case 9: cout<<"Setembro"<<endl;break;
       case 10: cout<<"Outubro"<<endl;break;
       case 11: cout<<"Novembro"<<endl;break;
       case 12: cout<<"Dezembro"<<endl;break;
       default: cout<<"Valor invalido: Digite um numero entre 1 e 12"<<endl;         
    }

	return 0;
}






