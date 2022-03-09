#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int cod;
	
	cout<<"Digite o Codigo: ";
	cin>>cod;
	
	if ( cod == 1 ) {
		
		cout<<"Alimento nao perecivel";
	}  
	else if ( cod >= 2 && cod <= 4 ) {
		
		cout<<"Alimento perecivel";
	} 
	else if ( cod >= 5 && cod <= 6 ) {
		
		cout<<"Vestuario";
	}  
	else if ( cod == 7 ) {
		
		cout<<"Higiene pessoal";
	}
	else if ( cod >= 8 && cod <= 15  ) {
		
		cout<<"Limpeza e utensilios domesticos";
	}                  
	else{
		
		cout<<"Codigo Invalido";
	}                     
	return 0;
}









