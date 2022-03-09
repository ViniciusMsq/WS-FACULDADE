#include <iostream>


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int idade;
	
	
	cout<<"Digite sua Idade: ";
	cin>>idade;
	
	if ( idade >= 0 && idade <= 4 ) {
		
		cout<<"Categoria: Bebe [0-4]";
	}  
	else if ( idade >= 5 && idade <= 7 ) {
		
		cout<<"Categoria: Infantil A [5-7]";
	} 
	else if ( idade >= 8 && idade <= 10 ) {
		
		cout<<"Categoria: Infantil B [8-10]";
	}  
	else if ( idade >= 11 && idade <= 13) {
		
		cout<<"Categoria: Infantil C [11-13]";
	}  
		else if ( idade >= 14 && idade <= 17) {
		
		cout<<"Categoria: Infantil D [14-17]";
	} 
		else if ( idade >= 18) {
		
		cout<<"Categoria: Senior ";
	}                  
	else{
		
		cout<<"Idade Invalida !!";
	}                     
	return 0;
}









