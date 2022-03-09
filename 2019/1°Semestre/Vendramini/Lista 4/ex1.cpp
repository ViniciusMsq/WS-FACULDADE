#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int id = 0 , cont = 0;
	float media = 0.0;
	
	do{
		cout<<"Informe a idade: ";
		cin>>id;
		media += id;
		cont++;
	}while(id != 0);
	
	media = media/(cont-1);
	cout<<"A media de idade é: "<<media;
	
	return 0;
}
