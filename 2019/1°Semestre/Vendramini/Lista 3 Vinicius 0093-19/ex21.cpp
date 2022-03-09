#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int dia, mes;
		
	cout<<"Digite o dia: ";
	cin>>dia;
	cout<<"Digite o mes: ";
	cin>>mes;
	
	if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21)) {
		
		cout<<dia<<"/"<<mes<<" - SARGITARIO";
	}  
	else if ((mes == 12 && dia >= 22) || (mes == 01 && dia <= 19)) {
		
		cout<<dia<<"/"<<mes<<" - CAPRICORNIO";
	} 
	else if ((mes == 01 && dia >= 20) || (mes == 02 && dia <= 18)) {
		
		cout<<dia<<"/"<<mes<<" - AQUARIO";
	} 
	else if ((mes == 02 && dia >= 19) || (mes == 03 && dia <= 20)) {
		
		cout<<dia<<"/"<<mes<<" - PEIXES";
	}
	else if ((mes == 03 && dia >= 21) || (mes == 04 && dia <= 19)) {
		
		cout<<dia<<"/"<<mes<<" - ARIES";
	} 
	else if ((mes == 04 && dia >= 20) || (mes == 05 && dia <= 20)) {
		
		cout<<dia<<"/"<<mes<<" - TOURO";
	} 
	else if ((mes == 05 && dia >= 21) || (mes == 06 && dia <= 21)) {
		
		cout<<dia<<"/"<<mes<<" - GEMEOS";
	} 
	else if ((mes == 06 && dia >= 22) || (mes == 07 && dia <= 22)) {
		
		cout<<dia<<"/"<<mes<<" - CANCER";
	} 
	else if ((mes == 07 && dia >= 23) || (mes == 8 && dia <= 22)) {
		
		cout<<dia<<"/"<<mes<<" - LEAO";
	} 
	else if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22)) {
		
		cout<<dia<<"/"<<mes<<" - VIRGEM";
	} 
	else if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22)) {
		
		cout<<dia<<"/"<<mes<<" - LIBRA";
	} 
	else if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21)) {
		
		cout<<dia<<"/"<<mes<<" - ESCORPIAO";
	}  
	else{
		
		cout<<"Dia ou mes Invalido !!";
	}              

	return 0;
}






