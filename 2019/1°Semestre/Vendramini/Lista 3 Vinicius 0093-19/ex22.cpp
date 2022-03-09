#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int idade;
	
	cout<<"Digite sua Idade: ";
	cin>>idade;
	
	if ( idade < 16 ) {
		
		cout<<"voce ainda nao vota";
	}  
	else if ( idade >= 18 && idade <= 65 ) {
		
		cout<<"o seu voto e obrigatorio ";
	} 
	else if ( (idade >= 16 && idade < 18) || (idade > 65 )) {
		
		cout<<"seu voto e facultativo ";
	}         
	else{
		
		cout<<"idade invalida ";
	}
                    
	
	return 0;
}










